/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:42:39 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 05:03:39 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "base64.h"

/*
** Count the characters without space
*/

uint64_t			cc_atoi_base(char *str, uint8_t base)
{
	uint64_t		result;
	uint16_t		len;
	uint16_t		i;

	result = 0;
	i = 0;
	len = ft_strlen(str);
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

char				*cc_pad_zero(char *str, int16_t len)
{
	char			*zero;
	char			*result;
	int16_t			zero_len;
	int16_t			i;

	zero_len = len - ft_strlen(str);
	if (zero_len <= 0)
		return (ft_strsub(str, 0, len));
	zero = ft_strnew(zero_len);
	i = -1;
	while (++i < zero_len)
		zero[i] = '0';
	result = ft_strjoin(str, zero);
	free(zero);
	return (result);
}

int8_t				cc_is_hex_str(char *str)
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

int32_t				cc_count_valid_char(t_ssl *ssl, uint8_t *str, uint32_t len)
{
	uint32_t		i;
	uint32_t		valid_len;

	i = 0;
	valid_len = 0;
	while (i < len)
	{
		if (ssl->cc == 0 && is_valid_char_base64(str[i]))
			valid_len++;
		i++;
	}
	return (valid_len);
}

char				*cc_insert_newline(uint8_t *str, int32_t len, int16_t n)
{
	int32_t			newline;
	char			*result;
	char			*temp;
	int16_t			i;
	int16_t			j;

	newline = len / n;
	if (newline == 0)
		return (ft_strjoin((char *)str, "\n"));
	result = ft_strnew(len + newline);
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
	result = ft_strjoin(result, "\n");
	free(temp);
	return (result);
}
