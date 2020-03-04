/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:11:49 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 19:38:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...

void aloneCans(int *arr, int n)
{
	int rightmost;
	int can_1 = 0;
	int can_2 = 0;
	int xor = 0;

	for (int i = 0; i < n; i++)
		xor ^= arr[i];
	rightmost = xor & ~(xor - 1);
	for (int i = 0; i < n; i++)
	{
		if (rightmost & arr[i])
			can_1 ^= arr[i];
		else
			can_2 ^= arr[i];
	}
	printf("%d\n%d\n", can_1, can_2);
}
