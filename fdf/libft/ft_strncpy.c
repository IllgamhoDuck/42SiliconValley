/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:24:58 by hypark            #+#    #+#             */
/*   Updated: 2019/07/24 23:05:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The stpcpy() and strcpy() functions copy the string src to dst (including
** the terminating `\0' character.)
** The stpncpy() and strncpy() functions copy at most len characters from src
** into dst.  If src is less than len characters long, the remainder of dst is
** filled with `\0' characters.  Otherwise, dst is not terminated.
** The source and destination strings should not overlap, as the behavior is
** undefined.
** The strcpy() and strncpy() functions return dst.  The stpcpy() and stpncpy()
** functions return a pointer to the terminating `\0' character of dst.  If
** stpncpy() does not terminate dst with a NUL character, it instead returns a
** pointer to dst[n] (which does not necessarily refer to a valid memory loca-
** tion.)
*/

char				*ft_strncpy(char *dst, const char *src, size_t len)
{
	char			*tmp;
	size_t			i;

	tmp = dst;
	i = 0;
	while ((i < len) && (*src != '\0'))
	{
		*tmp = *src;
		tmp++;
		src++;
		i++;
	}
	while (i < len)
	{
		*tmp = '\0';
		tmp++;
		i++;
	}
	return (dst);
}
