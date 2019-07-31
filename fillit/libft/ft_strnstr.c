/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:43:59 by hypark            #+#    #+#             */
/*   Updated: 2019/07/27 21:11:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function locates the first occurrence of the null-termi-
** nated string needle in the string haystack, where not more than len
** haracters are searched.  Characters that appear after a `\0' character
** are not searched.  Since the strnstr() function is a FreeBSD specific
** API, it should only be used when portability is not a concern.
*/

char					*ft_strnstr(const char *haystack, const char *needle,
									size_t len)
{
	size_t			i;
	size_t			size;
	char			first_c;
	char			*w_haystack;

	i = 0;
	size = ft_strlen(needle);
	first_c = *needle;
	if (size == 0)
		return ((char *)haystack);
	w_haystack = ft_strnew(size);
	ft_strcpy(w_haystack, haystack);
	w_haystack[len] = '\0';
	while (w_haystack[i] && i < len)
	{
		if (w_haystack[i] == first_c)
			if (ft_strncmp(w_haystack + i, needle, size) == 0)
				return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
