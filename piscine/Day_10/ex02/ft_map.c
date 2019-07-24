/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:40:45 by hypark            #+#    #+#             */
/*   Updated: 2018/05/28 18:44:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_map(int *tab, int length, int (*f)(int))
{
	int		*map;
	int		i;

	i = 0;
	map = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		map[i] = f(tab[i]);
		i++;
	}
	return (map);
}
