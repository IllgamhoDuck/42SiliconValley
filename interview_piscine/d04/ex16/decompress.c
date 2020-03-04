/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:02:02 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 16:17:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

/*
** l is 32, n is 21
** l is bit width
** n is total bit number
*/

int	**pianoDecompress(struct s_bit *bit, int l)
{
	int **sheet = (int **)malloc(sizeof(int *) * bit->n);

	for (int i = 0; i < bit->n; i++)
	{
		sheet[i] = (int *)malloc(sizeof(int) * l);
		for (int j = 0; j < l; j++)
		{
			sheet[i][j] = bit->arr[i] & 1;
			bit->arr[i] >>= 1;
		}
	}
	return sheet;
}
