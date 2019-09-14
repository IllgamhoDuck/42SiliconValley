/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:38:32 by hypark            #+#    #+#             */
/*   Updated: 2019/07/24 21:37:07 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcmp() function compares byte string s1 against byte string s2.  Both
** strings are assumed to be n bytes long.
** The memcmp() function returns zero if the two strings are identical, other-
** wise returns the difference between the first two differing bytes (treated
** as unsigned char values, so that `\200' is greater than `\0', for example).
** Zero-length strings are always identical.  This behavior is not required by
** C and portable code should only depend on the sign of the returned value.
*/

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*t_s1;
	const unsigned char		*t_s2;
	size_t					i;

	t_s1 = s1;
	t_s2 = s2;
	i = 0;
	while ((i < n) && (t_s1[i] == t_s2[i]))
		i++;
	if (i == n)
		return (0);
	return (t_s1[i] - t_s2[i]);
}
