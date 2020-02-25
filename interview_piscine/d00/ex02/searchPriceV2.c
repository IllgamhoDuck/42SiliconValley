/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:08:03 by hypark            #+#    #+#             */
/*   Updated: 2020/02/24 22:29:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int					arrlen(struct s_art **arts)
{
	int			i = -1;
	int			count = 0;

	while(1)
	{
		i++;
		if (arts[i] == NULL)
			return (count);
		count++;
	}
}

int search(struct s_art **arts, int min, int max, char *name)
{
	int		result;

	if (min > max)
		return -1;
	result = strcmp(arts[(max + min) / 2]->name, name);
	if (result == 0)
		return arts[(max + min) / 2]->price;
	else if (result > 0)
		return search(arts, min, (max + min) / 2 - 1, name);
	else
		return search(arts, (max + min) / 2 + 1, max, name);
}

int searchPrice(struct s_art **arts, int n, char *name)
{
	return search(arts, 0, n - 1, name);
}
