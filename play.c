
#include "so_long.h"

void	move_player(t_vars *data, int keycode)
{
    if(keycode == 13)
    {
        data->player_y -= 60;
    }
    else if(keycode == 1)
    {
        data->player_y += 60;
    }
    else if(keycode == 0)
    {
        data->player_x -= 60;
    }
    else if(keycode == 2)
    {
        data->player_x += 60;
    }
    draw_walls(data);
	draw_collectives(data);
	draw_exit(data);
	draw_floor(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		data->player_x, data->player_y);
}
