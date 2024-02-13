/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:14:28 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 14:14:32 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

int	map_control(t_map *map)
{
	if (rectangle_c(map) || wall_c(map) || invalid_c(map) || \
		char_c(map) || travel_c(map))
	{
		free_map (map);
		return (1);
	}
	free_map(map);
	return (0);
}

int	rectangle_c(t_map *map)
{
	int		x;
	int		y;
	int		len;

	len = ft_strlenn(map->map_line[0]) - 1;
	x = 1;
	while (x < map->map_x_line)
	{
		y = 0;
		while (map->map_line[x] && map->map_line[x][y] != '\n' && \
			y < (int)(ft_strlenn(map->map_line[x])))
			y++;
		if (y != len)
		{
			ft_printf("Error\n(.﹒︠₋﹒︡.): Dikdörtgen Hatası");
			return (1);
		}
		x++;
	}
	return (0);
}

int	wall_c(t_map *map)
{
	int		x;
	int		value1;
	int		value2;

	x = 0;
	value1 = wall_first_last(map, x);
	x = 1;
	value2 = wall_middle(map, x);
	if (value1 != 0 || value2 != 0)
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Duvar Hatası");
		return (1);
	}
	return (0);
}

int	wall_first_last(t_map *map, int x)
{
	int		y;
	int		len;

	len = map->map_x_line;
	y = 0;
	while (map->map_line[x][y] != '\n')
	{
		if (map->map_line[0][y] != '1')
			return (1);
		if (map->map_line[len - 1][y] != '1')
			return (len);
		y++;
	}
	return (0);
}

int	wall_middle(t_map *map, int x)
{
	int		len;

	len = ft_strlenn(map->map_line[0]) - 2;
	while (map->map_line[x] != 0)
	{
		if (map->map_line[x][0] != '1' || map->map_line[x][len] != '1')
			return (x + 1);
		x++;
	}
	return (0);
}
