
#include "so_long.h"
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
				data->p += 1;
			if (data->map[i][j] == 'E')
				data->exit += 1;
			if (data->map[i][j] == 'C')
				data->colletives += 1;
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->colletives < 1 || data->exit != 1)
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
	int i;
	int j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (i == 0 || i == data->map_height - 1)
			{
				if (data->map[i][j] != '1')
                    print_walls_error();
			}
			if (j == 0 || j == data->map_width - 1)
			{
				if (data->map[i][j] != '1')
                    print_walls_error();
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