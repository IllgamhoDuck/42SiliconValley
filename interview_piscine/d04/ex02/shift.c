/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:27:39 by hypark            #+#    #+#             */
/*   Updated: 2020/03/02 20:47:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *leftShift(char *bin, int k)
{
	char *result = (char *)malloc(sizeof(char) * 7);
	int lsb = '0';
	int i = -1;

	k = k >= 6 ? 6 : k;
	result[6] = '\0';
	while (++i < k)
		result[5 - i] = lsb;
	i--;
	while (++i < 6)
		result[5 - i] = bin[5 - i + k];
	return result;
}

char *rightShift(char *bin, int k)
{
	char *result = (char *)malloc(sizeof(char) * 7);
	int msb = bin[0];
	int i = -1;

	k = k >= 6 ? 6 : k;
	result[6] = '\0';
	while (++i < k)
		result[i] = msb;
	i--;
	while (++i < 6)
		result[i] = bin[i - k];
	return result;
}

int toInt(char *bits)
{
	int result = 0;
	unsigned int bit_i;

	bit_i = -1;
	while (++bit_i < 5)
		if (bits[bit_i + 1] - '0')
			result |= (1 << (4 - bit_i));
	if (bits[0] - '0')
		result -= 32;
	return result;
}
