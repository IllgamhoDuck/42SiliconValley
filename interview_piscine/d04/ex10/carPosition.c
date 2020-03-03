/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:04:36 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 01:37:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int add(int pos)
{
	if (pos & 1)
		return add(pos >> 1) << 1;
	return pos | 1;
}

int carPosition(unsigned int parkingRow)
{
	int count = 0;
	int current_pos = 0;
	int pos = 0;
	int zero = 1;

	if (parkingRow)
		zero = 0;
	if (zero)
		return -1;
	while (parkingRow)
	{
		if (parkingRow & 1)
		{
			if (count)
				return -1;
			count |= 1;
			pos = current_pos;
		}
		current_pos = add(current_pos);
		parkingRow >>= 1;
	}
	return pos;
}
