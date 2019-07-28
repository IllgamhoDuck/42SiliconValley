/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:15:52 by hypark            #+#    #+#             */
/*   Updated: 2019/07/24 23:36:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** he strcmp() and strncmp() functions lexicographically compare the null-ter-
** minated strings s1 and s2.
** The strncmp() function compares not more than n characters.  Because
** strncmp() is designed for comparing strings rather than binary data, charac-
** ters that appear after a `\0' character are not compared.
** The strcmp() and strncmp() functions return an integer greater than, equal
** to, or less than 0, according as the string s1 is greater than, equal to, or
** less than the string s2.  The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/

int				ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*s1_c;
	const unsigned char	*s2_c;

	s1_c = (unsigned char*)s1;
	s2_c = (unsigned char*)s2;
	while (*s1_c == *s2_c && *s1_c != '\0')
	{
		s1_c++;
		s2_c++;
	}
	return (*s1_c - *s2_c);
}
