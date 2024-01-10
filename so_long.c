/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:32:20 by lissam            #+#    #+#             */
/*   Updated: 2024/01/10 09:43:30 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "so_long.h"

int	get_map_height(char *path)
{
	int	height;
	int	fd;
	char	*line;

	fd = open(path, O_RDONLY);
	height = 0;
	if (fd < 0)
	{
		ft_putstr("MAP PATH IMVALIDE");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (height == 0)
	{
		ft_putstr("MAP VIDE  PROBLEM");
		exit(1);
	}
	close(fd);
	return (height);
}

void	get_map(char *path, t_vars *data)
{
	int	i;
	int	fd;
	char	*line;

	data->map_height = get_map_height(path);
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0 || data->map_height == 0)
	{
		exit(1);
	}
	data->map = (char **)malloc((data->map_height) * sizeof(char *));
	if (!data->map)
	{
		free_map1(data);
		exit(1);
	}
	line = get_next_line(fd);
	while (i < data->map_height && line)
	{
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
}

void	check_path(char *path)
{
	if (ft_strcmp(&path[ft_strlen(path) - 4], ".ber") != 0)
	{
		ft_putstr("MAP PATH IMVALIDE");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc != 2)
	{
		ft_putstr("NUMBER OF PARAMS PROBLEM");
		return (1);
	}
	check_path(argv[1]);
	get_map(argv[1], &data);
	map_checker(&data);
	floodfill_collectives(&data);
	flood_fill_exit(&data);
	draw(&data);
	free_map1(&data);
}
