/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:06:44 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 17:22:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strchr() function locates the first occurrence of c (converted to
** a char) in the string pointed to by s.  The terminating null character
** is considered to be part of the string; therefore if c is `\0', the
** functions locate the terminating `\0'.
** The strrchr() function is identical to strchr(), except it locates the
** last occurrence of c.
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/

char				*ft_strchr(const char *s, int c)
{
	char			find;

	find = (char)c;
	if (find == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
