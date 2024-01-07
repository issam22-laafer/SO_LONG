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

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PLAYER_SPEED 200

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
	char	**map;
	int		map_width;
	int		map_height;
	int		one;
	int		zero;
	int		character;
	int		p;
	int		exit;
	int		colletives;
	int		img_width;
	int		img_height;
	void	*player;
	int		player_x;
	int		player_y;
	int		count_mouves;
	void	*walls;
	void	*enemies[3];
}			t_vars;

int			key_hook(int keycode, t_vars *vars);
int			close_window(t_vars *vars);
int			key_press(int keycode, t_vars *data);
void		ft_putstr(char *s);
int			ft_strcmp(char *ptr1, char *ptr2);
void		*ft_memset(void *ptr, int value, size_t num);
void		map_checker(t_vars *data);
int			ft_strlen2(char *str);
void		print_walls_error(void);
void		draw(t_vars *data);
#endif
