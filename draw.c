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
void	draw_walls(t_vars *data)
{
	int	i;
	int	j;

	data->walls = mlx_xpm_file_to_image(data->mlx, "./images/rockwall.xpm",
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
void	draw_collectives(t_vars *data)
{
	int	i;
	int	j;

	data->walls = mlx_xpm_file_to_image(data->mlx, "./images/banana.xpm",
			&data->img_width, &data->img_height);
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->walls, j
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

	data->walls = mlx_xpm_file_to_image(data->mlx, "./images/kevin.xpm",
			&data->img_width, &data->img_height);
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->walls, j
					* 60, i * 60);
			}
			j++;
		}
		i++;
	}
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
	draw_walls(data);
	draw_collectives(data);
	draw_player(data);
	
}

void	draw(t_vars *data)
{
	t_data	img;

	draw_map(data, &img);
	mlx_key_hook(data->mlx_win, key_hook, &data);
	mlx_hook(data->mlx_win, 17, 0, close_window, &data);
	// mlx_hook(data->mlx_win, 2, 1L << 0, key_press, &data);
	mlx_loop(data->mlx);
}
