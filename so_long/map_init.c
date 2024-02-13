/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:23:09 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 15:23:11 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_map *map, char *argc)
{
	int		y;

	map_reading_control(map, argc);
	map->p_move_count = 0;
	map->mlx = mlx_init();
	y = ft_strlenn(map->map_line[0]) - 1;
	map->mlx_win = mlx_new_window(map->mlx, \
		64 * y, 64 * map->map_x_line, "so_long");
	if (!map->mlx || !map->mlx_win || create_xpm(map))
	{
		ft_printf("Mlx Hatası");
		return (1);
	}
	window_put_image(map);
	mlx_string_put(map->mlx, map->mlx_win, 15, 15, 16777215, "0");
	mlx_hook(map->mlx_win, 2, 1L << 2, ft_move, map);
	mlx_hook(map->mlx_win, 17, 1L << 2, ft_exit, map);
	mlx_loop(map->mlx);
	return (0);
}

int	create_xpm(t_map *map)
{
	int		x;
	int		y;

	map->img_exit = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm", &x, &y);
	map->img_coin = mlx_xpm_file_to_image(map->mlx, "./img/coin.xpm", &x, &y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &x, &y);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "./img/py.xpm", &x, &y);
	map->img_back = mlx_xpm_file_to_image(map->mlx, "./img/back.xpm", &x, &y);
	if (!map->img_exit || !map->img_coin || !map->img_wall || \
	!map->img_player || !map->img_back)
		return (1);
	return (0);
}

int	window_put_image(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map->map_line[x][y])
	{
		if (map->map_line[x] && map->map_line[x][y] == '\n')
		{
			x++;
			y = 0;
		}
		if (map->map_line[x][y] == 'E')
			ft_put(map, map->img_exit, y, x);
		if (map->map_line[x][y] == 'C')
			ft_put(map, map->img_coin, y, x);
		if (map->map_line[x][y] == 'P')
			ft_put(map, map->img_player, y, x);
		if (map->map_line[x][y] == '0')
			ft_put(map, map->img_back, y, x);
		if (map->map_line[x][y] == '1')
			ft_put(map, map->img_wall, y, x);
		y++;
	}
	return (0);
}

void	ft_put(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, 64 * x, 64 * y);
}

int	ft_move(int key, t_map *map)
{
	int		x;
	int		y;
	char	*move;

	x = map->player_x_local;
	y = map->player_y_local;
	if (key == 13 || key == 126)
		x--;
	else if (key == 1 || key == 125)
		x++;
	else if (key == 2 || key == 124)
		y++;
	else if (key == 0 || key == 123)
		y--;
	else if (key == 53)
		ft_exit(map);
	else
		return (0);
	mlx_clear_window(map->mlx, map->mlx_win);
	map_move(map, x, y);
	window_put_image(map);
	move = ft_itoa(map->p_move_count);
	mlx_string_put(map->mlx, map->mlx_win, 63, 15, 16777215, move);
	free(move);
	return (0);
}
