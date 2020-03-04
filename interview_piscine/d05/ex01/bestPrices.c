/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrices.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:05:59 by hypark            #+#    #+#             */
/*   Updated: 2020/03/04 00:12:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

double bestPrice(int pizzaSize, double *prices)
{
	double best_price = -1.0;
	double price;

	if (pizzaSize == 0)
		return 0;
	if (pizzaSize == 1)
		return prices[1];
	for (int pizza_slice = 1; pizza_slice <= pizzaSize; pizza_slice++)
	{
		price = prices[pizza_slice] + bestPrice(pizzaSize - pizza_slice, prices);
		best_price = best_price < price ? price : best_price;
	}
	return best_price;
}
