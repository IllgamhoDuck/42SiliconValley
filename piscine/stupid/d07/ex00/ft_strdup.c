/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:26:12 by hypark            #+#    #+#             */
/*   Updated: 2018/05/23 11:50:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int count_char;

	count_char = 0;
	while (*str)
	{
		count_char += 1;
		str++;
	}
	return (count_char);
}

char		*ft_strcpy(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*src != '\0')
	{
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\0';
	return (dest);
}

char		*ft_strdup(char *src)
{
	char	*cpm;

	cpm = (char *)malloc(sizeof(src) * (ft_strlen(src) + 1));
	cpm = ft_strcpy(cpm, src);
	return (cpm);
}
