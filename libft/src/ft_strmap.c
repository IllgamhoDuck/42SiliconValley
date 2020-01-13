/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:45:22 by hypark            #+#    #+#             */
/*   Updated: 2019/07/26 00:09:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	size_t			str_size;
	size_t			i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str_size = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (str_size + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
