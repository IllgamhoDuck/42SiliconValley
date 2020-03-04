/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:02:57 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 22:50:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

static void recursiveSlice(int pizzaSize, struct s_array *arr)
{
	struct s_array *new_arr;
	int left_slice = pizzaSize - arr->sum;
	int pizza_slice = 0;

	while (++pizza_slice < (left_slice / 2) + 1)
	{
		arrayAppend((new_arr = arrayClone(arr)), pizza_slice);
		recursiveSlice(pizzaSize, new_arr);
		if (pizza_slice == left_slice - pizza_slice)
			continue ;
		arrayAppend((new_arr = arrayClone(arr)), left_slice - pizza_slice);
		recursiveSlice(pizzaSize, new_arr);
	}
	arrayAppend(arr, left_slice);
	arrayPrint(arr);
}

void printPossibleSlices(int pizzaSize)
{
	struct s_array *arr = arrayInit();

	recursiveSlice(pizzaSize, arr);
}
