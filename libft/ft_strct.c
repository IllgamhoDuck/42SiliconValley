/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:27:12 by hypark            #+#    #+#             */
/*   Updated: 2019/07/26 21:27:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** count how many strings are between the delimiter
*/

int				ft_strct(char const *s, char c)
{
	size_t		num;
	size_t		i;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			num++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (num);
}
