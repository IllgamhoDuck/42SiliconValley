/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:21:23 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 00:41:41 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit_help(char ***l, char const **s, char c)
{
	size_t			i;
	size_t			j;
	size_t			k;

	i = 0;
	j = 0;
	while ((*s)[i])
	{
		if ((*s)[i] != c)
		{
			if (!((*l)[j] = (char *)malloc(ft_strcct(*s, c, i) + 1)))
				return (NULL);
			k = 0;
			while ((*s)[i] != c && (*s)[i])
				(*l)[j][k++] = (*s)[i++];
			(*l)[j++][k] = '\0';
		}
		else
			i++;
	}
	(*l)[j] = NULL;
	return (*l);
}
