/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:29:21 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 03:15:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**    The memmove() function copies len bytes from string src to string dst.
**    The two strings may overlap; the copy is always done in a
**    non-destructive manner.
**    The memmove() function returns the original value of dst.
*/

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dst_t;
	const unsigned char		*src_t;
	size_t					i;

	if (dst == src)
		return (dst);
	dst_t = dst;
	src_t = src;
	i = 0;
	if (dst_t > src_t)
		while (len--)
			dst_t[len] = src_t[len];
	else
		while (i < len)
		{
			dst_t[i] = src_t[i];
			i++;
		}
	return (dst);
}
