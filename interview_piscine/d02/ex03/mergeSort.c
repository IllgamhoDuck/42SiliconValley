/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:17:16 by hypark            #+#    #+#             */
/*   Updated: 2020/02/27 21:09:10 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

static struct s_player **merge_sort(struct s_player **players, int end)
{
	struct s_player **merge;
	struct s_player **left;
	struct s_player **right;
	int middle;
	int i;
	int left_i;
	int right_i;

	if (end == 0)
		return players;
	middle = end / 2;
	left = (struct s_player **)malloc(sizeof(struct s_player *) * middle + 1);
	right = (struct s_player **)malloc(sizeof(struct s_player *) * (end - middle));
	merge = (struct s_player **)malloc(sizeof(struct s_player *) * (end + 1));
	i = -1;
	while (++i < middle + 1)
		left[i] = players[i];
	i = -1;
	while (++i < end - middle)
		right[i] = players[i + middle + 1];
	free(players);
	left = merge_sort(left, middle);
	right = merge_sort(right, end - middle - 1);
	i = -1;
	left_i = 0;
	right_i = 0;
	while (left_i <= middle || right_i <= end - middle - 1)
	{
		i++;
		if (right_i == end - middle - 1 && right[right_i] == NULL)
		{
			if (left_i <= middle)
				merge[i] = left[left_i++];
			else
				merge[i] = right[right_i++];
		}
		else if (left_i > middle)
			merge[i] = right[right_i++];
		else if (right_i > end - middle - 1)
			merge[i] = left[left_i++];
		else if (right[right_i]->score > left[left_i]->score)
			merge[i] = right[right_i++];
		else
			merge[i] = left[left_i++];
	}
	return merge;
}

struct s_player **mergeSort(struct s_player **players)
{
	int len = 0;

	while (players[len])
		len++;
	return merge_sort(players, len);
}
