/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:30:51 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 16:41:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int correct_value;
	
	if (col >= l)
		correct_value = 0;
	else
		correct_value = 1 << col;

	for (int i = 0; i < dist && row + i < bit->n; i++)
		bit->arr[row + i] |= correct_value;
}
