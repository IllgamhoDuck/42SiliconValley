/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:35:29 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 04:14:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char				*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	tmp;

	tmp = 0;
	len = ft_nbrcount(n);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		tmp = (unsigned int)(n * -1);
	else
		tmp = (unsigned int)n;
	s[len] = '\0';
	while (--len >= 1)
	{
		s[len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n >= 0)
		s[len] = tmp % 10 + '0';
	else
		s[len] = '-';
	return (s);
}
