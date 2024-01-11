/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:12:56 by lissam            #+#    #+#             */
/*   Updated: 2024/01/11 17:30:27 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	go_left(t_vars *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->map_height)
// 	{
// 		j = 0;
// 		while (j < data->map_width)
// 		{
// 			if (data->map[i][j] == 'N')
// 			{
// 				if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'C')
// 				{
// 					data->map[i][j] = '0';
// 					data->map[i][j - 1] = 'N';
// 					draw_floor(data);
// 					draw_ennemie(data);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
// void	go_right(t_vars *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->map_height)
// 	{
// 		j = 0;
// 		while (j < data->map_width)
// 		{
// 			if (data->map[i][j] == 'N')
// 			{
// 				if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'C')
// 				{
// 					data->map[i][j] = '0';
// 					data->map[i][j + 1] = 'N';
// 					draw_floor(data);
// 					draw_ennemie(data);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	move_enemie(t_vars *data)
// {
// 	static int	e;

// 	if (e < 100)
// 	{
// 		go_left(data);
// 	}
// 	else if (e < 200)
// 	{
// 		go_right(data);
// 		if (e + 1 == 200)
// 		{
// 			e = 0;
// 		}
// 	}
// 	e += 1;
// }

void	check_ennemie_images(t_vars *data)
{
	data->ennemie = mlx_xpm_file_to_image(data->mlx, "./images/ennemie_1.xpm",
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

void	render2(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'N')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, j
					* 60, i * 60);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->ennemie,
					j * 60, i * 60);
			}
			j++;
		}
		i++;
	}
}

void	animate(t_vars *data)
{
	static int	frame;

	check_ennemie_images(data);
	if (frame < 20)
	{
		data->ennemie = mlx_xpm_file_to_image(data->mlx,
				"./images/ennemie_1.xpm", &data->img_width, &data->img_height);
	}
	else if (frame < 40)
	{
		data->ennemie = mlx_xpm_file_to_image(data->mlx,
				"./images/ennemie_2.xpm", &data->img_width, &data->img_height);
	}
	else if (frame < 60)
	{
		data->ennemie = mlx_xpm_file_to_image(data->mlx,
				"./images/ennemie_3.xpm", &data->img_width, &data->img_height);
		if (frame + 1 == 60)
		{
			frame = 0;
		}
	}
	render2(data);
	frame += 1;
}

int	render_ennemie(t_vars *data)
{
	// move_enemie(data);
	animate(data);
	return (0);
}
