/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:34:39 by hypark            #+#    #+#             */
/*   Updated: 2018/06/05 18:05:20 by hypark           ###   ########.fr       */
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

int				ft_check_map_info(char *str, t_map *map)
{
	int			line;

	line = ft_atoi(&str);
	if (line == 0)
		return (1);
	map->line = line;
	if (*(str + 3) != '\n')
		return (1);
	map->empty = *str;
	str++;
	map->obstacle = *str;
	str++;
	map->full = *str;
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
