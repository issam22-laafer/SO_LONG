/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:12 by lissam            #+#    #+#             */
/*   Updated: 2024/01/09 10:07:28 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_vars *data)
{
	if (!data->mlx_win || !data->ext || !data->player || !data->clc
		|| !data->floor || !data->walls || !data->ennemie)
	{
		ft_putstr("Error in images");
		free(data->mlx);
		exit(1);
	}
}
