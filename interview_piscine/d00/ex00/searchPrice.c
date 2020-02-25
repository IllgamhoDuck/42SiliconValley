/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:40:07 by hypark            #+#    #+#             */
/*   Updated: 2020/02/24 17:49:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int			searchPrice(struct s_art **arts, char *name)
{
	int		i;

	i = -1;
	while (1)
	{
		i++;
		if (arts[i] == NULL)
			return (-1);
		if (strcmp(arts[i]->name, name) == 0)
			return (arts[i]->price);
	}
}
