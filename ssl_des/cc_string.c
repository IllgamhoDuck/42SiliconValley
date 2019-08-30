/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:42:39 by hypark            #+#    #+#             */
/*   Updated: 2019/08/29 19:37:34 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "base64.h"

/*
** Count the characters without space
*/

uint64_t			cc_atoi_base(uint8_t *str, uint8_t base)
{
	uint64_t		result;
	uint16_t		len;
	uint16_t		i;

	result = 0;
	i = 0;
	len = ft_strlen((char *)str);
	while (i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * base + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * base + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * base + (str[i] - 'A' + 10);
		i++;
	}
	return (result);
}

uint8_t				*cc_pad_zero(uint8_t *str, int16_t len)
{
	uint8_t			*zero;
	uint8_t			*result;
	int16_t			zero_len;
	int16_t			i;
	
	zero_len = len - ft_strlen((char *)str);
	if (zero_len <= 0)
		return ((uint8_t *)ft_strsub((char *)str, 0, len));
	zero = (uint8_t *)ft_strnew(zero_len);
	i = -1;
	while (++i < zero_len)
		zero[i] = '0';
	result = (uint8_t *)ft_strjoin((char *)str, (char *)zero);
	free(zero);
	return (result);
}

int8_t				cc_is_hex_str(uint8_t *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && !(*str >= 'a' && *str <= 'f') && \
				!(*str >= 'A' && *str <= 'F'))
			return (0);
		str++;
	}
	return (1);
}

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
