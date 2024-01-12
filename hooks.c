/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:39 by lissam            #+#    #+#             */
/*   Updated: 2024/01/12 09:31:24 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_map1(data);
	exit(1);
	return (0);
}

int	key_press(int keycode, t_vars *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free_map1(data);
		exit(1);
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
	moves_counter(data);
	return (1);
}
