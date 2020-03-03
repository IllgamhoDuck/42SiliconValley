/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:54:13 by hypark            #+#    #+#             */
/*   Updated: 2020/03/02 19:35:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *getSum(char *a, char *b)
{
	char *result = (char *)malloc(sizeof(char) * 7);
	int i = 5;
	int carry = 0;

	result[6] = '\0';
	while (i >= 0)
	{
		if (a[i] == '0' && b[i] == '0')
		{
			if (carry)
				result[i] = '1';
			else
				result[i] = '0';
			carry = 0;
		}
		else if (a[i] == '1' && b[i] == '1')
		{
			if (carry)
				result[i] = '1';
			else
				result[i] = '0';
			carry = 1;
		}
		else
		{
			if (carry)
			{
				result[i] = '0';
				carry = 1;
			}
			else
			{
				result[i] = '1';
				carry = 0;
			}
		}
		i--;
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
