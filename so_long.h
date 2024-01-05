/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:49 by lissam            #+#    #+#             */
/*   Updated: 2024/01/05 14:29:57 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 800
# define PLAYER_SPEED 10

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	void	*walls;
	void	*character;
	void	*player;
	void	*enemies[3];
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		count_mouves;
}			t_vars;

int			key_hook(int keycode, t_vars *vars);
int			close_window(t_vars *vars);
int			key_press(int keycode, t_vars *data);
void		ft_putstr(char *s);
int	ft_memcmp(char *ptr1,char *ptr2);
#endif
