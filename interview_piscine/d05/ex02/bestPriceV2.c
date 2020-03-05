/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrices.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:05:59 by hypark            #+#    #+#             */
/*   Updated: 2020/03/04 23:31:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

double bestPriceV2(int pizzaSize, double *prices, double *cache)
{
	double best_price = prices[pizzaSize];
	double price;

	if (cache[pizzaSize])
		return cache[pizzaSize];
	for (int pizza_slice = 1; pizza_slice <= pizzaSize / 2; pizza_slice++)
	{
		price = bestPriceV2(pizza_slice, prices, cache) + \
				bestPriceV2(pizzaSize - pizza_slice, prices, cache);
		best_price = best_price < price ? price : best_price;
	}
	if (cache[pizzaSize] < best_price)
		cache[pizzaSize] = best_price;
	return best_price;
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double *cache = (double *)malloc(sizeof(double) * pizzaSize);

	memset(cache, 0., pizzaSize);
	return bestPriceV2(pizzaSize, prices, cache);
}
