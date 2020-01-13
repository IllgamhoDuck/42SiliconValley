/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:51:56 by hypark            #+#    #+#             */
/*   Updated: 2019/09/20 21:54:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The atoi() function converts the initial portion of the string pointed
** to by str to int representation.
*/

int				ft_atoi(const char *str)
{
	long		result;
	long long	i;
	long long	mul;

	result = 0;
	i = 0;
	mul = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i - 1] == '-')
		mul = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return ((int)(result * mul));
}
