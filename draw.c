/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:21 by lissam            #+#    #+#             */
/*   Updated: 2024/01/13 08:34:39 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_elements(t_vars *data)
{
	draw_floor(data);
	draw_walls(data);
	draw_collectives(data);
	draw_player(data);
	draw_exit(data);
	draw_ennemie(data);
}

void	check_ennemie_images(t_vars *data)
{
	data->ennemie = mlx_xpm_file_to_image(data->mlx, "./images/ennemie_1.xpm",
			&data->img_width, &data->img_height);
	if (!data->ennemie)
		free_images(data);
	data->ennemie = mlx_xpm_file_to_image(data->mlx, "./images/ennemie.xpm",
			&data->img_width, &data->img_height);
	if (!data->ennemie)
		free_images(data);
	data->ennemie = mlx_xpm_file_to_image(data->mlx, "./images/ennemie_2.xpm",
			&data->img_width, &data->img_height);
	if (!data->ennemie)
		free_images(data);
	data->ennemie = mlx_xpm_file_to_image(data->mlx, "./images/ennemie_3.xpm",
			&data->img_width, &data->img_height);
	if (!data->ennemie)
		free_images(data);
}

void	check_player_images(t_vars *data)
{
	data->player = mlx_xpm_file_to_image(data->mlx, "./images/door_open.xpm",
			&data->img_width, &data->img_height);
	if (!data->player)
		free_images(data);
	data->player = mlx_xpm_file_to_image(data->mlx, "./images/kevin_up.xpm",
			&data->img_width, &data->img_height);
	if (!data->player)
		free_images(data);
	data->player = mlx_xpm_file_to_image(data->mlx, "./images/kevin_left.xpm",
			&data->img_width, &data->img_height);
	if (!data->player)
		free_images(data);
	data->player = mlx_xpm_file_to_image(data->mlx, "./images/kevin_down.xpm",
			&data->img_width, &data->img_height);
	if (!data->player)
		free_images(data);
	data->player = mlx_xpm_file_to_image(data->mlx, "./images/kevin.xpm",
			&data->img_width, &data->img_height);
	if (!data->player)
		free_images(data);
}

void	draw_map(t_vars *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		free_map1(data);
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * 60,
			data->map_height * 60, "SO _ LONG _ GAME");
	data->ext = mlx_xpm_file_to_image(data->mlx, "./images/door_.xpm",
			&data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "./images/kevin.xpm",
			&data->img_width, &data->img_height);
	data->clc = mlx_xpm_file_to_image(data->mlx, "./images/banana.xpm",
			&data->img_width, &data->img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./images/white_floor.xpm",
			&data->img_width, &data->img_height);
	data->walls = mlx_xpm_file_to_image(data->mlx, "./images/oak_wall.xpm",
			&data->img_width, &data->img_height);
	data->ennemie = mlx_xpm_file_to_image(data->mlx, "./images/ennemie_1.xpm",
			&data->img_width, &data->img_height);
	check_images(data);
	check_player_images(data);
	check_ennemie_images(data);
	draw_elements(data);
}

void	draw(t_vars *data)
{
	draw_map(data);
	moves_counter(data);
	mlx_loop_hook(data->mlx, render_ennemie, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_loop(data->mlx);
}
