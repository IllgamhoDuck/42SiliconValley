/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:50:58 by hypark            #+#    #+#             */
/*   Updated: 2020/03/02 20:53:04 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *getXor(char *a, char *b)
{
	char *result = (char *)malloc(sizeof(char) * 7);
	int i = -1;

	result[6] = '\0';
	while (++i < 6)
	{
		if (a[i] == '0' && b[i] == '1')
			result[i] = '1';
		else if (a[i] == '1' && b[i] == '0')
			result[i] = '1';
		else
			result[i] = '0';
	}
	return result;
}

int toInt(char *bits)
{
	int result = 0;
	unsigned int bit_i;

	bit_i = -1;
	while (++bit_i < 6)
		if (bits[bit_i] - '0')
			result |= (1 << (5 - bit_i));
	return result;
}
