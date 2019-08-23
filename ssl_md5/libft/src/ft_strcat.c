/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:14:19 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 16:33:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcat() and strncat() functions append a copy of the null-termi-
** nated string s2 to the end of the null-terminated string s1, then add
** a terminating `\0'.  The string s1 must have sufficient space to hold
** the result.
** The strncat() function appends not more than n characters from s2, and
** then adds a terminating `\0'.
** The source and destination strings should not overlap, as the behavior
** is undefined.
** The strcat() and strncat() functions return the pointer s1.
*/

char				*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
