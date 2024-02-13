/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:29:26 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 14:29:29 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr_(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

int	invalid_c(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (map->map_line[x])
	{
		y = 0;
		while (map->map_line[x][y] != '\n' && map->map_line[x][y] != '\0')
		{
			if (ft_strchr_(MAP_CHR, map->map_line[x][y]))
				y++;
			else
			{
				ft_printf("Error\n(.﹒︠₋﹒︡.): Haritada yanlış karakter");
				return (1);
			}
		}
		x++;
	}
	return (0);
}

int	char_c(t_map *map)
{
	character_count(map, 0, 0);
	if (map->exit_count != 1)
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Çıkış sayısı 1 değil!");
		return (1);
	}
	if (map->player_count != 1)
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Oyuncu sayısı 1 değil!");
		return (1);
	}
	if (map->coin_count == 0)
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Toplanabilir sayısı 0!");
		return (1);
	}
	return (0);
}

void	character_count(t_map *map, int x, int y)
{
	map->player_count = 0;
	map->exit_count = 0;
	map->coin_count = 0;
	x = 0;
	while (map->map_line[x])
	{
		y = 0;
		while (map->map_line[x][y])
		{
			if (map->map_line[x][y] == 'E')
				map->exit_count++;
			if (map->map_line[x][y] == 'P')
			{
				map->player_x_local = x;
				map->player_y_local = y;
				map->player_count++;
			}
			if (map->map_line[x][y] == 'C')
				map->coin_count++;
			y++;
		}
		x++;
	}
}
