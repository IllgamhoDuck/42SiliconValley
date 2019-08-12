/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:41:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/12 01:15:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					count_d(uintmax_t n)
{
	int				len;
	
	len = 0;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}
