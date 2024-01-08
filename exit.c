#include "so_long.h"

void check_exit(t_vars *data)
{
    if(data->count_collectives == data->colletives)
    {
        ft_putstr("YOU WIN");
        data->ext = mlx_xpm_file_to_image(data->mlx, "./images/door_open.xpm",
			&data->img_width, &data->img_height);
    }
}
void close_window_exit(t_vars *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    free(data->mlx);
    exit(0);
}