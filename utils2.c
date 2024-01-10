/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:12 by lissam            #+#    #+#             */
/*   Updated: 2024/01/10 21:18:23 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_vars *data)
{
	if (!data->mlx_win || !data->ext || !data->player || !data->clc
		|| !data->floor || !data->walls || !data->ennemie)
	{
		ft_putstr("Error in images");
		free_map1(data);
		exit(1);
	}
}

void	free_map1(t_vars *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_map2(t_vars *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map2[i]);
		i++;
	}
	free(data->map2);
}
