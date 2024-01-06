#include "./get_next_line/get_next_line.h"
#include "so_long.h"

int ft_strlenN(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	check__dimensions(t_vars *data)
{
    int i;
	int width;
	int width_checker;

	width = ft_strlenN(data->map[0]);
	i = 0;
	// if(data->map_height > width)
	// {
	// 	ft_putstr("MAP SHOULD BE RECTANGULAR");
	// 	exit(1);
	// }
	while(i < data->map_height)
	{
		width_checker = ft_strlenN(data->map[i]);
		if(width_checker != width)
		{
			ft_putstr("MAP DIMENSIONS PROBLEM / MAP SHOULD BE RECTANGULAR");
			exit(1);
		}
		i++;
	}
	
}

void	map_checker(t_vars *data)
{
	check__dimensions(data);
}

int	get_map_height(char *path)
{
	int	height;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("MAP PATH IMVALIDE");
		exit(1);
	}
	while (get_next_line(fd) != NULL)
	{
		height++;
	}
	if(height == 0)
	{
		ft_putstr("MAP VIDE  PROBLEM");
		exit(1);
	}
	close(fd);
	return (height);
}

char	**get_map(char *path, t_vars *data)
{
	int	map_height;
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
	int		i;
	char	**res;

	if (argc != 2 || !check_path(argv[1]))
	{
		ft_putstr("NUMBER OF PARAMS PROBLEM");
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
