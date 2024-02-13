/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:46:40 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 14:46:42 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (file_control(argc, argv[1]))
		return (1);
	if (map_reading_control(&map, argv[1]))
		return (1);
	if (map_control(&map))
		return (1);
	if (map_init(&map, argv[1]))
		return (1);
	return (0);
}
