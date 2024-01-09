#include "so_long.h"

void	get_player_position(int *x, int *y, t_vars *data)
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
void	duplicateMap(t_vars *data)
{
	int	i;

	i = 0;
	data->map2 = (char **)malloc(data->map_height * sizeof(char *));
	while (i < data->map_height)
	{
		data->map2[i] = (char *)malloc((data->map_width + 1) * sizeof(char));
		strncpy(data->map2[i], data->map[i], data->map_width);
		data->map2[i][data->map_width] = '\0';
		i++;
	}
}
void	fill(t_vars *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_height || y >= data->map_width
		|| (data->map2[x][y] != '0' && data->map2[x][y] != 'P'
			&& data->map2[x][y] != 'C'))
		return ;
	data->map2[x][y] = 'V';
	fill(data, x - 1, y);
	fill(data, x + 1, y);
	fill(data, x, y - 1);
	fill(data, x, y + 1);
	return ;
}

void	check_c(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map2[i][j] == 'C')
			{
				printf("Error !! The path from the player to colletives is invalide\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	floodfill(t_vars *data)
{
	int x;
	int y;
	get_player_position(&x, &y, data);
	duplicateMap(data);
	fill(data, x, y);
	check_c(data);
}