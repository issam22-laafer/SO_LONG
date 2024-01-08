/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:21 by lissam            #+#    #+#             */
/*   Updated: 2024/01/05 14:29:29 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_elements(t_vars *data)
{
	draw_floor(data);
	draw_walls(data);
	draw_collectives(data);
	draw_player(data);
	draw_exit(data);
}

void	draw_map(t_vars *data, t_data *img)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * 60,
			data->map_height * 60, "SO _ LONG _ GAME");
	img->img = mlx_new_image(data->mlx, data->map_width * 60, data->map_height
			* 60);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_elements(data);
}

void	draw(t_vars *data)
{
	t_data	img;

	draw_map(data, &img);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_loop(data->mlx);
}
