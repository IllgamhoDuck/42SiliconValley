/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:02:32 by hypark            #+#    #+#             */
/*   Updated: 2019/07/24 20:19:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**   The memchr() function locates the first occurrence of c
**   (converted to an unsigned char) in string s.
**   The memchr() function returns a pointer to the byte located,
**   or NULL if no such byte exists within n bytes.
*/

void				*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*t_s;
	unsigned char			stop_w;
	size_t					i;

	t_s = s;
	stop_w = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (t_s[i] == stop_w)
			return ((void *)(t_s + i));
		i++;
	}
	return (NULL);
}
