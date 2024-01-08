/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:35:46 by lissam            #+#    #+#             */
/*   Updated: 2024/01/07 15:35:48 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_walls(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->walls, j
					* 60, i * 60);
			}
			j++;
		}
		i++;
	}
}

void	draw_floor(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '0')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j
					* 60, i * 60);
			}
			j++;
		}
		i++;
	}
}

void	draw_collectives(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j
					* 60, i * 60);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->clc, j
					* 60, i * 60);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j
					* 60, i * 60);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
					j * 60, i * 60);
				data->player_x = j * 60;
				data->player_y = i * 60;
			}
			j++;
		}
		i++;
	}
}

void	draw_exit(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j
					* 60, i * 60);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->ext, j
					* 60, i * 60);
			}
			j++;
		}
		i++;
	}
}
