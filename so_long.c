#include "./get_next_line/get_next_line.h"
#include "so_long.h"

int	check__dimensions(t_vars *data)
{
    
}

int	map_checker(t_vars *data)
{
	check__dimensions(data);
}

int	get_map_height(char *path)
{
	int	height;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd) != NULL)
	{
		height++;
	}
	close(fd);
	return (height);
}

char	**get_map(char *path, t_vars *data)
{
	int	map_height;
	int	i;
	int	fd;

	map_height = get_map_height(path);
	i = 0;
	fd = open(path, O_RDONLY);
	if (map_height == 0 || fd < 0)
	{
		return (NULL);
	}
	data->map = (char **)malloc((map_height + 1) * sizeof(char *));
	if (!data->map)
	{
		free(path);
		return (NULL);
	}
	while (i < map_height)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	return (data->map);
}

int	check_path(char *path)
{
	if (ft_strcmp(&path[ft_strlen(path) - 4], ".ber"))
		return (0);
	else
		return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	data;
	int		i;
	char	**res;

	if (argc == 1 || argc > 2 || !check_path(argv[1]) || !get_map(argv[1],
			&data))
	{
		ft_putstr("PATH OR NUMBER OF PARAMS PROBLEM");
		return (1);
	}
	get_map(argv[1], &data);
	map_checker(&data);
	// i = 0;
	// res = get_map(argv[1], &data);
	// while (res[i])
	// {
	// 	printf("%s", res[i]);
	// 	i++;
	// }
}
