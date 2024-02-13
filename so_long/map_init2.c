/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:26:06 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 15:26:09 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_move(t_map *map, int x, int y)
{
	if (map->map_line[x][y] != '1' && map->map_line[x][y] != 'E')
	{
		ft_printf("Moves : %d\n", ++map->p_move_count);
		if (map->map_line[x][y] == 'C')
			map->coin_count--;
		map->map_line[map->player_x_local][map->player_y_local] = '0';
		map->map_line[x][y] = 'P';
		map->player_x_local = x;
		map->player_y_local = y;
	}
	else if (map->map_line[x][y] == 'E' && map->coin_count == 0)
	{
		ft_printf("Moves : %d\n", ++map->p_move_count);
		ft_exit(map);
	}
	if (map->map_line[x][y] == 'E' && map->coin_count > 0)
		ft_printf("Kapı kapalı.");
}

int	ft_exit(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_back);
	mlx_destroy_image(map->mlx, map->img_wall);
	mlx_destroy_image(map->mlx, map->img_exit);
	mlx_destroy_image(map->mlx, map->img_player);
	mlx_destroy_image(map->mlx, map->img_coin);
	mlx_clear_window(map->mlx, map->mlx_win);
	free_map(map);
	exit(0);
	return (0);
}
