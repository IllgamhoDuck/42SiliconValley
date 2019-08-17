/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:35:08 by hypark            #+#    #+#             */
/*   Updated: 2019/07/27 23:18:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlcat() appends string src to the end of dst.  It will append at
** most dstsize - strlen(dst) - 1 characters.  It will then NUL-termi-
** nate, unless dstsize is 0 or the original dst string was longer than
** dstsize (in practice this should not happen as it means that either
** dstsize is incorrect or that dst is not a proper string).
** If the src and dst strings overlap, the behavior is undefined.
** Besides quibbles over the return type (size_t versus int) and signal
** handler safety (snprintf(3) is not entirely safe on some systems), the
** following two are equivalent:
** n = strlcpy(dst, src, len);
** n = snprintf(dst, len, "%s", src);
** Like snprintf(3), the strlcpy() and strlcat() functions return the
** total length of the string they tried to create.  For strlcpy() that
** means the length of src.  For strlcat() that means the initial length
** of dst plus the length of src.
** If the return value is >= dstsize, the output string has been trun-
** cated.  It is the caller's responsibility to handle this.
*/

size_t				ft_strlcat(char *restrict dst, const char *restrict src,
								size_t dstsize)
{
	int				dst_s;
	int				src_s;
	int				i;
	int				size;

	dst_s = ft_strlen(dst);
	src_s = ft_strlen(src);
	i = 0;
	size = (int)dstsize;
	if (size - 1 <= dst_s)
		return (size + src_s);
	while (i < size - dst_s - 1)
	{
		dst[dst_s + i] = src[i];
		i++;
	}
	dst[dst_s + i] = '\0';
	return (dst_s + src_s);
}
