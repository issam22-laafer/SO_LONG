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

int	draw_map(t_vars *data, t_data *img)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		exit(1);
		return (0);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hello world!");
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	data->path = "./images/walls.xpm";
	data->walls = mlx_xpm_file_to_image(data->mlx, data->path, &data->img_width,
			&data->img_height);
	if (data->walls == NULL)
	{
		write(1, "OPS! SOMETHING HAPPEND WITH IMAGES", 34);
		free(data->mlx);
		exit(1);
		return (0);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->walls, 0, 0);
	return (1);
}

int	main(void)
{
	t_vars	data;
	t_data	img;
	int		checker;

	checker = draw_map(&data, &img);
	if (!checker)
	{
		write(1, "OPS! SOMETHING WRONG", 34);
		return (0);
	}
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
