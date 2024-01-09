/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:44:42 by lissam            #+#    #+#             */
/*   Updated: 2024/01/09 09:44:43 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_ennemie(t_vars *data)
{
	int i;
	int j;

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