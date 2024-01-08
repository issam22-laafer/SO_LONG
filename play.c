
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
	draw_elements(data);
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
	draw_elements(data);
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
	draw_elements(data);
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
	draw_elements(data);
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
