/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:43:28 by hypark            #+#    #+#             */
/*   Updated: 2020/03/05 00:03:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	swap(char *c1, char *c2)
{
	char	tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	permute(char *str, int start, int end)
{
	if (start == end)
		printf("%s\n", str);
	else
	{
		for (int i = start; i <= end; i++)
		{
			swap(str + start, str + i);
			permute(str, start + 1, end);
			swap(str + start, str + i);
		}
	}
}

void	printPermutations(char *str)
{
	permute(str, 0, strlen(str) - 1);
}
