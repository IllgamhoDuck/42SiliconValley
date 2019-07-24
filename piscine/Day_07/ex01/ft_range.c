/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:54:12 by hypark            #+#    #+#             */
/*   Updated: 2018/05/23 14:31:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_range(int min, int max)
{
	int		*add_int;
	int		len;
	int		i;

	if (max <= min)
		return (0);
	i = 0;
	len = max - min;
	add_int = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		add_int[i] = min + i;
		i++;
	}
	return (add_int);
}
