/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:57 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 00:49:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*str;
	int				i;
	int				j;
	int				k;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	ft_strtrim_help(&s, &i, &j);
	if (i > j)
	{
		if (!(str = ft_strnew(0)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strnew(j - i + 1)))
			return (NULL);
		while (i <= j)
			str[k++] = s[i++];
	}
	return (str);
}
