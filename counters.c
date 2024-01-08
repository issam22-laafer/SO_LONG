
#include "so_long.h"

void	moves_counter(t_vars *data)
{
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0x00FF0000, "Moves: ");
	mlx_string_put(data->mlx, data->mlx_win, 90, 10, 0x00FF0000,
		ft_itoa(data->count_moves));
	mlx_string_put(data->mlx, data->mlx_win, 10, 30, 0x00FF0000,
		"Number of bananas: ");
	mlx_string_put(data->mlx, data->mlx_win, 200, 30, 0x00FF0000,
		ft_itoa(data->count_collectives));
}