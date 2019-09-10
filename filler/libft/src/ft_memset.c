/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:58:49 by hypark            #+#    #+#             */
/*   Updated: 2019/07/24 17:53:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	  The memset() function writes len bytes of value c
**     (converted to an unsigned char) to the string b.
**	   The memset() function returns its first argument.
*/

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	w_char;
	unsigned char	*address;

	w_char = (unsigned char)c;
	address = b;
	while (len-- > 0)
		address[len] = w_char;
	return (b);
}
