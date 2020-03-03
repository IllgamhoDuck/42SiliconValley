/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:03:10 by hypark            #+#    #+#             */
/*   Updated: 2020/03/02 23:03:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (value)
		return parkingRow | (1 << pos);
	else
		return parkingRow & ~(1 << pos);
}
