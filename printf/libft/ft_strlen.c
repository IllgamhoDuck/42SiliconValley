/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:38:35 by hypark            #+#    #+#             */
/*   Updated: 2019/07/24 21:46:16 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlen() function computes the length of the string s.  The strnlen()
** function attempts to compute the length of s, but never scans beyond the
** first maxlen bytes of s.
** The strlen() function returns the number of characters that precede the
** terminating NUL character. The strnlen() function returns either the same
** result as strlen() or maxlen, whichever is smaller.
*/

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
