/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:09:56 by hypark            #+#    #+#             */
/*   Updated: 2020/02/27 23:04:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void countSort(unsigned char *utensils, int n)
{
	unsigned char *count_list;
	int total_count;
	int i;
	int j;

	count_list = (unsigned char *)malloc(sizeof(unsigned char) * n);
	bzero(count_list, sizeof(unsigned char) * n);
	i = -1;
	while (++i < n)
		count_list[utensils[i] - 1] += 1; 
	i = -1;
	j = -1;
	while (++i < n)
	{
		total_count = count_list[i];
		while (total_count--)
			utensils[++j] = i + 1;
	}
}
