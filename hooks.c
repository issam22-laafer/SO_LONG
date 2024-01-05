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

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook! %d \n", keycode);
	if (keycode == 53 || keycode == 17)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		free(vars->mlx);
		exit(0);
		return (1);
	}
	return (1);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars->mlx);
	exit(0);
	return (1);
}

int	key_press(int keycode, t_vars *data)
{
	data->count_mouves = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data->mlx);
		exit(0);
	}
	else if (keycode == 126)
		data->player_y -= PLAYER_SPEED;
	else if (keycode == 125)
		data->player_y += PLAYER_SPEED;
	else if (keycode == 123)
		data->player_x -= PLAYER_SPEED;
	else if (keycode == 124)
		data->player_x += PLAYER_SPEED;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		data->player_x, data->player_y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->walls, 0, 0);
	return data->count_mouves += 1;
}
