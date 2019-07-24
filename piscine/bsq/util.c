/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:06:06 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 23:13:12 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			set_bit(unsigned int *bit_array, unsigned int index)
{
	bit_array[index / UINT_SIZE] |= 1 << (index % UINT_SIZE);
}

t_u8			get_bit(unsigned int *bit_array, unsigned int index)
{
	return ((bit_array[index / UINT_SIZE] >> (index % UINT_SIZE)) & 1);
}
