/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:47 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 15:08:50 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "mlx/mlx.h"

# define MAP_CHR "01CEP"

typedef struct s_map
{
	void	*img_player;
	void	*img_wall;
	void	*img_exit;
	void	*img_back;
	void	*img_coin;
	int		player_x_local;
	int		player_y_local;
	int		exit_count;
	int		player_count;
	int		coin_count;
	int		p_move_count;
	int		map_x_line;
	char	*file_name;
	void	*mlx;
	void	*mlx_win;
	char	**map_line;
}				t_map;

int		file_control(int argc, char *argv);
int		ft_strlenn(char *str);
int		ft_strcmp(char *str, char *ptr);
int		map_reading_control(t_map *map, char *file_name);
int		map_reading(t_map *map, char *file_name);
int		map_r_c(t_map *map, char *file_name);
int		map_control(t_map *map);
int		rectangle_c(t_map *map);
int		wall_c(t_map *map);
int		wall_first_last(t_map *map, int x);
int		wall_middle(t_map *map, int x);
char	*ft_strchr_(const char *s, int c);
int		invalid_c(t_map *map);
int		char_c(t_map *map);
void	character_count(t_map *map, int x, int y);
int		travel_c(t_map *map);
void	recursive_p(t_map *map, int x, int y);
int		coin_status(t_map *map);
int		exit_status(t_map *map);
int		map_init(t_map *map, char *argc);
int		create_xpm(t_map *map);
int		window_put_image(t_map *map);
void	ft_put(t_map *map, void *img, int x, int y);
int		ft_move(int key, t_map *map);
void	map_move(t_map *map, int x, int y);
char	*ft_itoa(int n);
int		ft_exit(t_map *map);
void	free_map(t_map *map);

#endif
