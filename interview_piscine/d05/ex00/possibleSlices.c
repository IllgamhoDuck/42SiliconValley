/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:02:57 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 23:38:50 by hypark           ###   ########.fr       */
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

	for (int pizza_slice = 1; pizza_slice < pizzaSize; pizza_slice++)
	{
		arrayAppend((new_arr = arrayClone(arr)), pizza_slice);
		recursiveSlice(pizzaSize - pizza_slice, new_arr);
	}
	arrayAppend(arr, pizzaSize);
	arrayPrint(arr);
}

void printPossibleSlices(int pizzaSize)
{
	struct s_array *arr = arrayInit();

	recursiveSlice(pizzaSize, arr);
}
