/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:45:41 by lissam            #+#    #+#             */
/*   Updated: 2024/01/09 09:45:43 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_vars *data)
{
	if (data->count_collectives == data->colletives)
	{
		data->ext = mlx_xpm_file_to_image(data->mlx, "./images/door_open.xpm",
				&data->img_width, &data->img_height);
	}
}
void	close_window_exit(t_vars *data)
{
	ft_putstr("YOU WIN");
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
}
void	close_window_lose(t_vars *data)
{
	ft_putstr("YOU LOSE");
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
}