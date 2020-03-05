/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:03:54 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 17:09:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...

void aloneCan(int *arr, int n)
{
	int result = 0;

	for (int i = 0; i < n; i++)
		result ^= arr[i];
	printf("%d\n", result);
}