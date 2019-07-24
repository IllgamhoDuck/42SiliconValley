/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:34:39 by hypark            #+#    #+#             */
/*   Updated: 2018/06/06 02:11:59 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				ft_atoi(char **str)
{
	int			result;

	result = 0;
	if (!(**str >= '0' && **str <= '9'))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		result = 10 * result + **str - '0';
		(*str)++;
	}
	return (result);
}

int				ft_info_char(t_map *map)
{
	if (map->empty == map->obstacle)
		return (1);
	if (map->obstacle == map->full)
		return (1);
	if (map->full == map->empty)
		return (1);
	return (0);
}

int				ft_check_map_info(char *str, t_map *map)
{
	map->line = ft_atoi(&str);
	if (map->line == 0)
	{
		write(2, "map error\n", 10);
		return (1);
	}
	if (*(str + 3) != '\n')
	{
		write(2, "map error\n", 10);
		return (1);
	}
	map->empty = *str;
	str++;
	map->obstacle = *str;
	str++;
	map->full = *str;
	if (ft_info_char(map))
	{
		write(2, "map error\n", 10);
		return (1);
	}
	return (0);
}

char			*ft_delete_map_info(char *str)
{
	char		*copy;
	int			len;

	len = 0;
	while (*str != '\n')
		str++;
	str++;
	while (str[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	if (copy)
	{
		while (str[len])
		{
			copy[len] = str[len];
			len++;
		}
		copy[len] = '\0';
	}
	else
		return (0);
	return (copy);
}
