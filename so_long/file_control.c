/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:20:46 by yozcan            #+#    #+#             */
/*   Updated: 2023/04/14 14:20:54 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlenn(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str, char *ptr)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && ptr[i] != '\0' && str[i] == ptr[i])
		i++;
	return (str[i] - ptr[i]);
}

int	file_control(int argc, char *argv)
{
	int		len;

	len = 0;
	if (argc != 2)
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Argüman sayısı hatası!");
		return (1);
	}
	len = ft_strlenn(argv);
	if (len < 5 || ft_strcmp(argv + len - 4, ".ber") != 0)
	{
		ft_printf("Error\n(.﹒︠₋﹒︡.): Dosya uzantı hatası!");
		return (1);
	}
	return (0);
}
