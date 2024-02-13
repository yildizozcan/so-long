/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:13:54 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 15:14:01 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_reading_control(t_map *map, char *file_name)
{
	map_reading(map, file_name);
	if (!(map->map_line))
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Dosya okunamıyor ya da içi boş");
		return (1);
	}
	if (map->map_line[0][0] == '\n')
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Harita hatalı");
		return (1);
	}
	return (0);
}

int	map_reading(t_map *map, char *file_name)
{
	int		fd;
	int		i;

	i = 0;
	map_r_c(map, file_name);
	if (!(map->map_line || map->map_x_line <= 0))
		return (1);
	fd = open(file_name, O_RDONLY);
	map->map_line[i] = get_next_line(fd);
	if (map->map_line[i] == (void *)0)
	{
		free(map->map_line);
		map->map_line = NULL;
		return (1);
	}
	while (map->map_line[i++])
	map->map_line[i] = get_next_line(fd);
	close (fd);
	return (0);
}

int	map_r_c(t_map *map, char *file_name)
{
	int		len;
	int		fd;
	char	c;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		map->map_x_line = 0;
		return (1);
	}
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		len++;
	}
	len++;
	close (fd);
	map->map_line = malloc(sizeof(char *) * (len + 1));
	if (!map->map_line)
		return (1);
	map->map_line[len + 1] = NULL;
	map->map_x_line = len;
	return (0);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->map_x_line)
	{
		free(map->map_line[i]);
		i++;
	}
	free(map->map_line);
}
