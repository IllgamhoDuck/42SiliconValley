/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:56:14 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 17:24:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it.  The pointer may subse-
** quently be used as an argument to the function free(3).
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
** The strndup() function copies at most n characters from the string s1 always
** NUL terminating the copied string.
*/

char				*ft_strdup(const char *s1)
{
	char			*s2;
	size_t			len;

	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * len);
	if (s2 == NULL)
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
