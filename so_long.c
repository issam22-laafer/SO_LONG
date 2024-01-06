#include "./get_next_line/get_next_line.h"
#include "so_long.h"

int	ft_strlen2(char *str)
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
	int	i;
	int	width;

	width = ft_strlen2(data->map[0]);
	i = 0;
	while (i < data->map_height)
	{
		data->map_width = ft_strlen2(data->map[i]);
		if (data->map_width != width)
		{
			ft_putstr("MAP DIMENSIONS PROBLEM / MAP SHOULD BE RECTANGULAR");
			exit(1);
		}
		i++;
	}
}
void	check_characters_number(t_vars *data)
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
				data->player += 1;
			if (data->map[i][j] == 'E')
				data->exit += 1;
			if (data->map[i][j] == 'C')
				data->colletives += 1;
			j++;
		}
		i++;
	}
	if (data->player != 1 || data->colletives < 1 || data->exit != 1)
	{
		ft_putstr("PLAYER / EXIT / COLLECTIVES PROBLEM");
		exit(1);
	}
}
void	check_characters(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'C' && data->map[i][j] != '1'
				&& data->map[i][j] != '0')
			{
				ft_putstr("MAP CONTAINE INVALIDE CHARACTER");
				exit(1);
			}
			j++;
		}
		i++;
	}
	check_characters_number(data);
}

void	check_walls(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (i == 0 || i == data->map_height - 1)
			{
				if (data->map[i][j] != '1')
				{
					ft_putstr("MAP BOUNDARY WALLS PROBLEM");
					exit(1);
				}
			}
			if (j == 0 || j == data->map_width - 1)
			{
				if (data->map[i][j] != '1')
				{
					ft_putstr("MAP BOUNDARY WALLS PROBLEM");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	map_checker(t_vars *data)
{
	check__dimensions(data);
	check_characters(data);
	check_walls(data);
}

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
}
