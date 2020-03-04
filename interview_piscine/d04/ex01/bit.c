/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:38:04 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 20:23:23 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *getAnd(char *a, char *b)
{
	char *result = (char *)malloc(sizeof(char) * 5);
	int i = 3;

	result[4] = '\0';
	while (i >= 0)
	{
		if (a[i] == '1' && b[i] == '1')
			result[i] = '1';
		else
			result[i] = '0';
		i--;
	}
	return result;
}

char *getOr(char *a, char *b)
{
	char *result = (char *)malloc(sizeof(char) * 5);
	int i = 3;

	result[4] = '\0';
	while (i >= 0)
	{
		if (a[i] == '0' && b[i] == '0')
			result[i] = '0';
		else
			result[i] = '1';
		i--;
	}
	return result;
}

int toInt(char *bits)
{
	int result = 0;
	unsigned int bit_i;

	bit_i = -1;
	while (++bit_i < 4)
		if (bits[bit_i] - '0')
			result |= (1 << (3 - bit_i));
	return result;
}
