/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:42:39 by hypark            #+#    #+#             */
/*   Updated: 2019/08/28 01:34:50 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "base64.h"

/*
** Count the characters without space
*/

int32_t				cc_count_valid_char(t_ssl *ssl, uint8_t *str)
{
	int32_t			len;

	len = 0;
	while (*str)
	{
		if (ssl->cc == 0 && is_valid_char_base64(*str))
			len++;
		str++;
	}
	return (len);
}

uint8_t				*cc_insert_newline(uint8_t *str, int32_t len, int16_t n)
{
	int32_t			newline;
	uint8_t			*result;
	uint8_t			*temp;
	int16_t			i;
	int16_t			j;

	newline = len / n;
	if (newline == 0)
		return ((uint8_t *)ft_strjoin((char *)str, "\n"));
	result = (uint8_t *)ft_strnew(len + newline);
	i = -1;
	j = 0;
	while (++i < len)
	{
		result[i + j] = str[i];
		if (i > 0 && ((i + 1) % n == 0))
			result[i + ++j] = '\n';
	}
	if (len % n == 0)
		return (result);
	else
		temp = result;
	result = (uint8_t *)ft_strjoin((char *)result, "\n");
	free(temp);
	return (result);
}
