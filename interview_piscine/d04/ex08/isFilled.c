/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 23:12:04 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 00:15:57 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...

//static void printBits(unsigned int num)
//{
//	int i = -1;
//	while (++i < 32)
//	{
//		printf("%i", (num >> (31 - i) & 1));
//		if ((i + 1) % 8 == 0)
//			printf(" ");
//	}
//	printf("\n");
//}

int isFilled(unsigned int parkingRow)
{
	if (parkingRow)
		return parkingRow & 1 & isFilled(parkingRow >> 1);
	return 1;
}
