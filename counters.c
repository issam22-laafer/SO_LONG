/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:45:25 by lissam            #+#    #+#             */
/*   Updated: 2024/01/10 18:58:40 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_counter(t_vars *data)
{
	char	*moves;
	char	*colletives;
	char	*colletives_max;

	moves = ft_itoa(data->count_moves);
	colletives = ft_itoa(data->count_collectives);
	colletives_max = ft_itoa(data->colletives);
	ft_putstr("Moves: ");
	ft_putstr(moves);
	ft_putstr("\n");
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0x00FF0000, "Moves: ");
	mlx_string_put(data->mlx, data->mlx_win, 90, 10, 0x00FF0000, moves);
	mlx_string_put(data->mlx, data->mlx_win, 10, 30, 0x00FF0000,
		"Number of bananas: ");
	mlx_string_put(data->mlx, data->mlx_win, 200, 30, 0x00FF0000, colletives);
	mlx_string_put(data->mlx, data->mlx_win, 220, 30, 0x00FF0000, "/");
	mlx_string_put(data->mlx, data->mlx_win, 240, 30, 0x00FF0000,
		colletives_max);
	free(moves);
	free(colletives);
	free(colletives_max);
}
