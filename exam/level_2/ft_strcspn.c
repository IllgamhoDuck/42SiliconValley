/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:56:46 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 10:24:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int					ft_strchr(char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

size_t				ft_strcspn(const char *s, const char *reject)
{
	size_t			i;

	i = 0;
	while (*s)
	{
		if (ft_strchr(*s, reject))
			return (i);
		i++;
		s++;
	}
	return (i);
}
