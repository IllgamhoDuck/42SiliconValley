/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:50:45 by hypark            #+#    #+#             */
/*   Updated: 2019/07/27 20:48:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strstr() function locates the first occurrence of the null-termi-
** nated string needle in the null-terminated string haystack.
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.
*/

char					*ft_strstr(const char *haystack, const char *needle)
{
	size_t			i;
	size_t			size;
	char			first_c;

	i = 0;
	size = ft_strlen(needle);
	first_c = *needle;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == first_c)
			if (ft_strncmp(haystack + i, needle, size) == 0)
				return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
