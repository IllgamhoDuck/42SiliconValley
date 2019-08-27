/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:16:14 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 03:15:24 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	 The memcpy() function copies n bytes from memory area src to memory area
**    dst.  If dst and src overlap, behavior is undefined.  Applications in
**    which dst and src might overlap should use memmove(3) instead.
**    The memcpy() function returns the original value of dst.
*/

void				*ft_memcpy(void *restrict dst,
								const void *restrict src,
								size_t n)
{
	unsigned char					*t_dst;
	const unsigned char				*t_src;
	size_t							i;

	if (n == 0 || dst == src)
		return (dst);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return (dst);
}
