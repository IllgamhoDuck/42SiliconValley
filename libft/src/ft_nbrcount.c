/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:44:44 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 04:06:05 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return size of the number.
** for example -123 is 4 and 123 is 3
*/

int				ft_nbrcount(int n)
{
	int				len;
	unsigned int	tmp;

	tmp = 0;
	len = 0;
	if (n < 0)
	{
		tmp = (unsigned int)(n * -1);
		len++;
	}
	else
		tmp = (unsigned int)n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	len++;
	return (len);
}
