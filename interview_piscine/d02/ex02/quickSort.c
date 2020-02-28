/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:37:41 by hypark            #+#    #+#             */
/*   Updated: 2020/02/27 18:02:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

static int partition(struct s_player **players, int start, int end, int pivot)
{
	struct s_player *tmp;
	int i;
	int j;

	i = start - 1;
	j = start - 1;
	while (++j <= end)
	{
		if (players[j]->score > pivot)
		{
			++i;
			tmp = players[j];
			players[j] = players[i];
			players[i] = tmp;
		}
	}
	tmp = players[i + 1];
	players[i + 1] = players[end + 1];
	players[end + 1] = tmp;
	return i + 1;
}

static void quick_sort(struct s_player **players, int start, int end)
{
	int pivot;
	int swap_i;

	if (start >= end)
		return ;
	pivot = players[end]->score;
	swap_i = partition(players, start, end - 1, pivot);
	quick_sort(players, start, swap_i - 1);
	quick_sort(players, swap_i + 1, end);
}

void quickSort(struct s_player **players)
{
	int	len = 0;

	while (players[len])
		len++;
	quick_sort(players, 0, len - 1);
}
