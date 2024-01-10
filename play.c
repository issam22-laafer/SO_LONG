/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:45:17 by lissam            #+#    #+#             */
/*   Updated: 2024/01/10 17:52:00 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_vars *data)
{
	if (data->map[(data->player_y - 60) / 60][data->player_x / 60] == '0')
	{
		data->map[(data->player_y - 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[(data->player_y - 60) / 60][data->player_x / 60] == 'C')
	{
		data->map[(data->player_y - 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[(data->player_y - 60) / 60][data->player_x / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[(data->player_y - 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	else if (data->map[(data->player_y - 60) / 60][data->player_x / 60] == 'N')
		close_window_lose(data);
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}

void	down(t_vars *data)
{
	if (data->map[(data->player_y + 60) / 60][data->player_x / 60] == '0')
	{
		data->map[(data->player_y + 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[(data->player_y + 60) / 60][data->player_x / 60] == 'C')
	{
		data->map[(data->player_y + 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[(data->player_y + 60) / 60][data->player_x / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[(data->player_y + 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	else if (data->map[(data->player_y + 60) / 60][data->player_x / 60] == 'N')
		close_window_lose(data);
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}

void	right(t_vars *data)
{
	if (data->map[data->player_y / 60][(data->player_x + 60) / 60] == '0')
	{
		data->map[data->player_y / 60][(data->player_x + 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[data->player_y / 60][(data->player_x + 60) / 60] == 'C')
	{
		data->map[data->player_y / 60][(data->player_x + 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[data->player_y / 60][(data->player_x + 60) / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[data->player_y / 60][(data->player_x + 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	else if (data->map[data->player_y / 60][(data->player_x + 60) / 60] == 'N')
		close_window_lose(data);
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}

void	left(t_vars *data)
{
	if (data->map[data->player_y / 60][(data->player_x - 60) / 60] == '0')
	{
		data->map[data->player_y / 60][(data->player_x - 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[data->player_y / 60][(data->player_x - 60) / 60] == 'C')
	{
		data->map[data->player_y / 60][(data->player_x - 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[data->player_y / 60][(data->player_x - 60) / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[data->player_y / 60][(data->player_x - 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	else if (data->map[data->player_y / 60][(data->player_x - 60) / 60] == 'N')
		close_window_lose(data);
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}

void	move_player(t_vars *data, int keycode)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	if (keycode == 13)
	{
		data->player = mlx_xpm_file_to_image(data->mlx, "./images/kevin_up.xpm",
				&data->img_width, &data->img_height);
		up(data);
	}
	else if (keycode == 1)
	{
		data->player = mlx_xpm_file_to_image(data->mlx,
				"./images/kevin_down.xpm", &data->img_width, &data->img_height);
		down(data);
	}
	else if (keycode == 0)
	{
		data->player = mlx_xpm_file_to_image(data->mlx,
				"./images/kevin_left.xpm", &data->img_width, &data->img_height);
		left(data);
	}
	else if (keycode == 2)
	{
		data->player = mlx_xpm_file_to_image(data->mlx, "./images/kevin.xpm",
				&data->img_width, &data->img_height);
		right(data);
	}
}
