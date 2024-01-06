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

int	render_ghosts(t_vars *data)
{
	int	i;

	data->enemies[0] = mlx_xpm_file_to_image(data->mlx,
			"./images/green_ghost.xpm", &data->img_width, &data->img_height);
	data->enemies[1] = mlx_xpm_file_to_image(data->mlx,
			"./images/red_ghost.xpm", &data->img_width, &data->img_height);
	data->enemies[2] = mlx_xpm_file_to_image(data->mlx,
			"./images/yellow_ghost.xpm", &data->img_width, &data->img_height);
	i = 0;
	while (i < 3)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemies[i], i
			* 100, i * 100);
		i++;
	}
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
	data->walls = mlx_xpm_file_to_image(data->mlx, "./images/walls.xpm",
			&data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "./images/pacman.xpm",
			&data->img_width, &data->img_height);
	data->player_x = 100;
	data->player_y = 100;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		data->player_x, data->player_y);
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
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}
