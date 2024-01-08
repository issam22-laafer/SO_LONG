
#include "so_long.h"

void	up(t_vars *data)
{
	if (data->map[(data->player_y - 60) / 60][data->player_x / 60] == '0')
	{
		data->map[(data->player_y - 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[(data->player_y - 60) / 60][data->player_x / 60] == 'C')
	{
		data->map[(data->player_y - 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[(data->player_y - 60) / 60][data->player_x / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[(data->player_y - 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}
void	down(t_vars *data)
{
	if (data->map[(data->player_y + 60) / 60][data->player_x / 60] == '0')
	{
		data->map[(data->player_y + 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[(data->player_y + 60) / 60][data->player_x / 60] == 'C')
	{
		data->map[(data->player_y + 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[(data->player_y + 60) / 60][data->player_x / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[(data->player_y + 60) / 60][data->player_x / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}
void	right(t_vars *data)
{
	if (data->map[data->player_y / 60][(data->player_x + 60) / 60] == '0')
	{
		data->map[data->player_y / 60][(data->player_x + 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[data->player_y / 60][(data->player_x + 60) / 60] == 'C')
	{
		data->map[data->player_y / 60][(data->player_x + 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[data->player_y / 60][(data->player_x + 60) / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[data->player_y / 60][(data->player_x + 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}
void	left(t_vars *data)
{
	if (data->map[data->player_y / 60][(data->player_x - 60) / 60] == '0')
	{
		data->map[data->player_y / 60][(data->player_x - 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
	}
	else if (data->map[data->player_y / 60][(data->player_x - 60) / 60] == 'C')
	{
		data->map[data->player_y / 60][(data->player_x - 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		data->count_collectives += 1;
	}
	else if (data->map[data->player_y / 60][(data->player_x - 60) / 60] == 'E'
		&& data->count_collectives == data->colletives)
	{
		data->map[data->player_y / 60][(data->player_x - 60) / 60] = 'P';
		data->map[data->player_y / 60][data->player_x / 60] = '0';
		close_window_exit(data);
	}
	check_exit(data);
	draw_elements(data);
	data->count_moves += 1;
}

void	move_player(t_vars *data, int keycode)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	if (keycode == 13)
		up(data);
	else if (keycode == 1)
	{
		down(data);
	}
	else if (keycode == 0)
	{
		left(data);
	}
	else if (keycode == 2)
	{
		right(data);
	}
}
