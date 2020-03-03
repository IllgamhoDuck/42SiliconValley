/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:44:37 by hypark            #+#    #+#             */
/*   Updated: 2020/03/03 01:52:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int carPosition(unsigned int parkingRow)
{
	double decimal;

	if (modf(log2(parkingRow), &decimal))
		return ~0;
	if (parkigRow)
		return (int)decimal;
	return ~0;
}
