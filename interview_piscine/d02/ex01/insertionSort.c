/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:06:00 by hypark            #+#    #+#             */
/*   Updated: 2020/02/27 16:29:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void insertionSort(struct s_player **players)
{
	struct s_player *tmp;
	int complete_i;
	int i;
	char *star = "⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐";

	printf("sorting %s\n", star);
	complete_i = 0;
	while (players[complete_i + 1])
	{
		i = complete_i + 1;
		while (i - 1 >= 0 && players[i - 1]->score < players[i]->score)
		{
			tmp = players[i - 1];
			players[i - 1] = players[i];
			players[i] = tmp;
			i -= 1;
		}
		complete_i += 1;
	}
}
