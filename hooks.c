/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:39 by lissam            #+#    #+#             */
/*   Updated: 2024/01/05 14:29:42 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *data)
{
	// printf("Hello from key_hook! %d \n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data->mlx);
		exit(0);
	}
	return (1);
}

int	close_window(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(1);
}

int	key_press(int keycode, t_vars *data)
{
	// mlx_clear_window(data->mlx, data->mlx_win);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data->mlx);
		exit(0);
	}
	else if (keycode == 13 && data->map[(data->player_y - 60)
		/ 60][data->player_x / 60] != '1')
		move_player(data, keycode);
	else if (keycode == 1 && data->map[(data->player_y + 60)
		/ 60][data->player_x / 60] != '1')
		move_player(data, keycode);
	else if (keycode == 0 && data->map[data->player_y / 60][(data->player_x
			- 60) / 60] != '1')
		move_player(data, keycode);
	else if (keycode == 2 && data->map[data->player_y / 60][(data->player_x
			+ 60) / 60] != '1')
		move_player(data, keycode);
	// draw_elements(data);
	moves_counter(data);
	return (1);
}
