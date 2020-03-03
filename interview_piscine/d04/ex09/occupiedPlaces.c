/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 00:28:44 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 01:01:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int add(int count)
{
	if (count & 1)
		return add(count >> 1) << 1;
	return count | 1;
}

int occupiedPlaces(unsigned int parkingRow)
{
	int count = 0;

	while (parkingRow)
	{
		if (parkingRow & 1)
			count = add(count);
		parkingRow >>= 1;
	}
	return count;
}
