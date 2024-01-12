/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:49 by lissam            #+#    #+#             */
/*   Updated: 2024/01/11 18:06:11 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PLAYER_SPEED 200

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map2;
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
	int		player_x;
	int		player_y;
	int		count_moves;
	void	*walls;
	void	*floor;
	void	*player;
	void	*clc;
	void	*ext;
	void	*ennemie;
	int		count_collectives;
}			t_vars;

void		free_map1(t_vars *data);
void		free_map2(t_vars *data);
void		free_images(t_vars *data);
int			close_window(t_vars *vars);
int			key_press(int keycode, t_vars *data);
void		ft_putstr(char *s);
int			ft_strcmp(char *ptr1, char *ptr2);
void		*ft_memset(void *ptr, int value, size_t num);
int			get_map_height(char *path);
void		map_checker(t_vars *data);
void		floodfill_collectives(t_vars *data);
void		flood_fill_exit(t_vars *data);
void		floodfill_exit(t_vars *data);
int			ft_strlen2(char *str);
void		print_walls_error(t_vars *data);
void		draw(t_vars *data);
void		draw_elements(t_vars *data);
void		draw_exit(t_vars *data);
void		draw_player(t_vars *data);
void		draw_collectives(t_vars *data);
void		draw_floor(t_vars *data);
void		draw_walls(t_vars *data);
void		draw_ennemie(t_vars *data);
void		move_player(t_vars *data, int keycode);
void		check_exit(t_vars *data);
void		check_images(t_vars *data);
void		close_window_exit(t_vars *data);
void		close_window_lose(t_vars *data);
void		freeMap2(t_vars *data);
void		moves_counter(t_vars *data);
char		*ft_itoa(int n);
void		draw_walls(t_vars *data);
int			render_ennemie(t_vars *data);
#endif
