#include "./get_next_line/get_next_line.h"
#include "so_long.h"


int	get_map_height(char *path)
{
	int	height;
	int	fd;

	fd = open(path, O_RDONLY);
	height = 0;
	if (fd < 0)
	{
		ft_putstr("MAP PATH IMVALIDE");
		exit(1);
	}
	while (get_next_line(fd) != NULL)
	{
		height++;
	}
	if (height == 0)
	{
		ft_putstr("MAP VIDE  PROBLEM");
		exit(1);
	}
	close(fd);
	return (height);
}

char	**get_map(char *path, t_vars *data)
{
	int	i;
	int	fd;

	data->map_height = get_map_height(path);
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0 || data->map_height == 0)
	{
		return (NULL);
	}
	data->map = (char **)malloc((data->map_height + 1) * sizeof(char *));
	if (!data->map)
	{
		free(path);
		return (NULL);
	}
	while (i < data->map_height)
	{
		data->map[i] = get_next_line(fd);
		printf("added %d => %s\n", i, data->map[i]);
		i++;
	}
	return (data->map);
}

int	check_path(char *path)
{
	return (ft_strcmp(&path[ft_strlen(path) - 4], ".ber") == 0);
}

int	main(int argc, char *argv[])
{
	t_vars	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc != 2 || !check_path(argv[1]))
	{
		ft_putstr("NUMBER OF PARAMS PROBLEM");
		return (1);
	}
	get_map(argv[1], &data);
	map_checker(&data);
	draw(&data);
}
