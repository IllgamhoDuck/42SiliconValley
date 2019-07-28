/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:03:55 by hypark            #+#    #+#             */
/*   Updated: 2019/07/24 19:31:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  	The memccpy() function copies bytes from string src to string dst.
**		If the character c (as converted to an unsigned char) occurs
**		in the string src, the copy stops and a pointer to the byte
**		after the copy of c in the string dst is returned.
**		Otherwise, n bytes are copied, and a NULL pointer is returned.
**     The source and destination strings should not overlap,
**		as the behavior is undefined.
*/

void				*ft_memccpy(void *restrict dst, const void *restrict src,
								int c, size_t n)
{
	unsigned char	*restrict		t_dst;
	const unsigned char	*restrict	t_src;
	unsigned char					stop_w;
	size_t							i;

	t_dst = dst;
	t_src = src;
	stop_w = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		if (t_src[i] == stop_w)
			return (t_dst + i + 1);
		i++;
	}
	return (NULL);
}
