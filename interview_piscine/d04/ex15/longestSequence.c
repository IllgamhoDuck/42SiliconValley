/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:34:00 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 15:43:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int add(int pos)
{
	if (pos & 1)
		return add(pos >> 1) << 1;
	return pos | 1;
}

int longestSequence(unsigned int parkingRow)
{
	int count = 0;

	while (parkingRow)
	{
		parkingRow &= (parkingRow << 1);
		count = add(count);
	}
	return count;
}
