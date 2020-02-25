/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:53:47 by hypark            #+#    #+#             */
/*   Updated: 2020/02/24 21:03:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include "header.h"

int					compare(struct s_art *a1, struct s_art *a2) { return strcmp(a1->name, a2->name); }

void				swap(struct s_art **arts, int i, int j)
{
	struct s_art	*tmp;

	tmp = arts[i];
	arts[i] = arts[j];
	arts[j] = tmp;
}

int					partition(struct s_art **arts, int low, int high)
{
	struct s_art	*pivot;
	int				i;
	int				j;

	pivot = arts[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (compare(arts[j], pivot) < 0 && ++i >= 0)
			swap(arts, i, j);
		j++;
	}
	swap(arts, i + 1, high);
	return (i + 1);
}

void				quickSort(struct s_art **arts, int low, int high)
{
	int				partition_i;

	if (low < high)
	{
		partition_i = partition(arts, low, high);
		quickSort(arts, low, partition_i - 1);
		quickSort(arts, partition_i + 1, high);
	}
}

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

void				sortArts(struct s_art **arts)
{
	quickSort(arts, 0, arrlen(arts) - 1);
}
