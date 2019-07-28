/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:24:54 by hypark            #+#    #+#             */
/*   Updated: 2019/07/27 01:42:05 by hypark           ###   ########.fr       */
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

char				*ft_strrchr(const char *s, int c)
{
	char			find;
	int				i;

	find = (char)c;
	i = 0;
	while (s[i])
		i++;
	if (find == '\0')
		return ((char *)(s + i));
	i--;
	while (s[i] && i > -1)
	{
		if (s[i] == find)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
