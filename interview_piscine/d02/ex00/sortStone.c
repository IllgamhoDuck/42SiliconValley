/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:44:04 by hypark            #+#    #+#             */
/*   Updated: 2020/02/27 15:59:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void sortStones(struct s_stone **stone)
{
	struct s_stone *start;
	struct s_stone *prev;
	struct s_stone *current_start;
	struct s_stone *current_end;
	struct s_stone *next_start;
	struct s_stone *next_end;
	int	sort_end;

	start = *stone;
	sort_end = 1;
	while (sort_end)
	{
		current_start = start;
		current_end = start;
		prev = start;
		sort_end = 0;
		while (current_end->next)
		{
			next_start = current_end->next;
			if (current_end->size == next_start->size)
				current_end = next_start;
			else if (current_end->size > next_start->size)
			{
				sort_end = 1;
				next_end = next_start;
				while (next_end->next)
				{
					if (next_start->size == next_end->next->size)
						next_end = next_end->next;
					else
						break ;
				}
				if (prev == start)
				{
					current_end->next = next_end->next;
					next_end->next = current_start;
					prev = next_end;
					start = next_start;
				}
				else
				{
					current_end->next = next_end->next;
					next_end->next = current_start;
					prev->next = next_start;
					prev = next_end;
				}
			}
			else
			{
				prev = current_end;
				current_end = next_start;
				current_start = current_end;
			}
		}
	}
	*stone = start;
}
