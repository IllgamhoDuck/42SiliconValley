/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:42:46 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 15:14:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int add(int pos)
{
	if (pos & 1)
		return add(pos >> 1) << 1;
	return pos | 1;
}

int rightmostCar(unsigned int parkingRow)
{
	int pos = 0;
	int zero = 1;

	if (parkingRow)
		zero = 0;
	if (zero)
		return -1;
	while (parkingRow)
	{
		if (parkingRow & 1)
			break ;
		parkingRow >>= 1;
		pos = add(pos);
	}
	return pos;
}
