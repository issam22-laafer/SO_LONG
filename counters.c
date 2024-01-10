/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:45:25 by lissam            #+#    #+#             */
/*   Updated: 2024/01/10 10:07:46 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_counter(t_vars *data)
{
	char	*moves;
	char	*colletives;
	moves = ft_itoa(data->count_moves);
	colletives = ft_itoa(data->count_collectives);
	ft_putstr("Moves: ");
	ft_putstr(moves);
	ft_putstr("\n");
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0x00FF0000, "Moves: ");
	mlx_string_put(data->mlx, data->mlx_win, 90, 10, 0x00FF0000,
		moves);
	mlx_string_put(data->mlx, data->mlx_win, 10, 30, 0x00FF0000,
		"Number of bananas: ");
	mlx_string_put(data->mlx, data->mlx_win, 200, 30, 0x00FF0000,
		colletives);
	free(moves);
	free(colletives);
}
