/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:38:47 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 14:38:49 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	travel_c(t_map *map)
{
	recursive_p(map, map->player_x_local, map->player_y_local);
	if (coin_status(map) || exit_status(map))
		return (1);
	return (0);
}

void	recursive_p(t_map *map, int x, int y)
{
	if (map->map_line[x][y + 1] == '0' || map->map_line[x][y + 1] == 'C')
	{
		map->map_line[x][y + 1] = 'P';
		recursive_p(map, x, y + 1);
	}
	if (map->map_line[x][y - 1] == '0' || map->map_line[x][y - 1] == 'C')
	{
		map->map_line[x][y - 1] = 'P';
		recursive_p(map, x, y - 1);
	}
	if (map->map_line[x + 1][y] == '0' || map->map_line[x + 1][y] == 'C')
	{
		map->map_line[x + 1][y] = 'P';
		recursive_p(map, x + 1, y);
	}
	if (map->map_line[x - 1][y] == '0' || map->map_line[x - 1][y] == 'C')
	{
		map->map_line[x - 1][y] = 'P';
		recursive_p(map, x - 1, y);
	}
}

int	coin_status(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (map->map_line[x])
	{
		y = 0;
		while (map->map_line[x][y] != 0 && map->map_line[x][y] != '\n')
		{
			if (map->map_line[x][y] == 'C')
			{
				ft_printf("Error\nHata:Oyuncu toplanabilir eşyaya ulaşamıyor");
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	exit_status(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (map->map_line[x])
	{
		y = 0;
		while (map->map_line[x][y] != '\n')
		{
			if (map->map_line[x][y] == 'E')
				break ;
			y++;
		}
		if (map->map_line[x][y] == 'E')
			break ;
		x++;
	}
	if (map->map_line[x][y + 1] == 'P' || map->map_line[x][y - 1] == 'P' || \
		map->map_line[x + 1][y] == 'P' || map->map_line[x - 1][y] == 'P')
		return (0);
	ft_printf("Error\n(.﹒︠₋﹒︡.): Oyuncu çıkışa ulaşamıyor!");
	return (1);
}
