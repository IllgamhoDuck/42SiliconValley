/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:42:07 by hypark            #+#    #+#             */
/*   Updated: 2018/05/23 15:18:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_ultimate_range(int **range, int min, int max)
{
	int		len;
	int		i;

	if (max <= min)
		*range = 0;
	i = 0;
	len = max - min;
	*range = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		range[0][i] = min + i;
		i++;
	}
	if (len <= 0)
		return (0);
	else
		return (len);
}
