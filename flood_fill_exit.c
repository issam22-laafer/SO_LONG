/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:04:37 by lissam            #+#    #+#             */
/*   Updated: 2024/01/10 21:19:01 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(int *x, int *y, t_vars *data)
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
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

static void	duplicatemap(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	data->map2 = (char **)malloc(data->map_height * sizeof(char *));
	if (!data->map2)
	{
		free_map1(data);
		free_map2(data);
		exit(1);
	}
	while (i < data->map_height)
	{
		data->map2[i] = (char *)malloc((data->map_width + 1) * sizeof(char));
		j = 0;
		while (j < data->map_width)
		{
			data->map2[i][j] = data->map[i][j];
			j++;
		}
		data->map2[i][data->map_width] = '\0';
		i++;
	}
}

static void	fill(t_vars *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_height || y >= data->map_width
		|| (data->map2[x][y] != '0' && data->map2[x][y] != 'P'
			&& data->map2[x][y] != 'C' && data->map2[x][y] != 'E'))
		return ;
	data->map2[x][y] = 'V';
	fill(data, x - 1, y);
	fill(data, x + 1, y);
	fill(data, x, y - 1);
	fill(data, x, y + 1);
	return ;
}

static void	check_c(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map2[i][j] == 'E')
			{
				ft_putstr("Exit path is invalide\n");
				free_map1(data);
				free_map2(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_exit(t_vars *data)
{
	int	x;
	int	y;

	get_player_position(&x, &y, data);
	duplicatemap(data);
	fill(data, x, y);
	check_c(data);
	free_map2(data);
}
