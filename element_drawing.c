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

	data->walls = mlx_xpm_file_to_image(data->mlx, "./images/oak_wall.xpm",
			&data->img_width, &data->img_height);
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

	data->floor = mlx_xpm_file_to_image(data->mlx, "./images/white_floor.xpm",
			&data->img_width, &data->img_height);
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

	data->clc = mlx_xpm_file_to_image(data->mlx, "./images/banana.xpm",
			&data->img_width, &data->img_height);
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

	data->plyr = mlx_xpm_file_to_image(data->mlx, "./images/kevin.xpm",
			&data->img_width, &data->img_height);
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
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->plyr, j
					* 60, i * 60);
					data->player_x = i;
					data->player_y = j;
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

	data->ext = mlx_xpm_file_to_image(data->mlx, "./images/door_.xpm",
			&data->img_width, &data->img_height);
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
