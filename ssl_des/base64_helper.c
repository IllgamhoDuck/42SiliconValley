/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:48:25 by hypark            #+#    #+#             */
/*   Updated: 2019/08/28 13:10:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "base64.h"

int8_t				is_valid_char_base64(uint8_t c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c == '+' || c == '/' || c == '=')
		return (1);
	return (0);
}

static void			preprocess_base64_decode_input(t_ssl *ssl, t_base64 *base64)
{
	int16_t			len;
	uint8_t			*decode;
	int16_t			decode_len;
	int16_t			i;
	int16_t			j;

	decode_len = cc_count_valid_char(ssl, base64->str);
	if (!(decode = (uint8_t *)malloc(sizeof(uint8_t) * (decode_len + 1))))
		malloc_error("preprocess_base64_decode_input");
	len = ft_strlen((char *)base64->str);
	i = -1;
	j = -1;
	while (++i < len)
		if (is_valid_char_base64(base64->str[i]))
			decode[++j] = base64->str[i];
	decode[++j] = '\0';
	free(base64->str);
	base64->str = decode;
	base64->len = ft_strlen((char *)base64->str);
}

/*
** base64->len == 0 is important because NULL value is 0 so
** it can bypass the base64->len % 4 != 0.
** process_input_base64 function will be broke at
** base64->str[base64->len - 1] == '=' when the NULL value goes there
*/

t_base64			*init_base64(t_ssl *ssl)
{
	t_base64		*base64;

	if (!(base64 = (t_base64 *)ft_memalloc(sizeof(t_base64))))
		malloc_error("t_base64");
	base64->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	if (ssl->op & CC_E)
		base64->len = ft_strlen((char *)base64->str);
	if (ssl->op & CC_D)
		preprocess_base64_decode_input(ssl, base64);
	if (ssl->op & CC_D)
	{
		if (base64->len % 4 != 0 || base64->len == 0)
		{
			free(base64->str);
			base64->str = NULL;
		}
	}
	return (base64);
}

/*
** Why are we adding "\n" to the encode value?
** It is not part of the key but it makes us easy to look at when we print out
** And the "\n" will be deleted while decoding process so it has no problem
*/

void				store_result_base64(t_ssl *ssl, t_base64 *base64)
{
	int32_t		len;

	if (ssl->op & CC_E)
	{
		len = ft_strlen((char *)base64->encode);
		ssl->cc_output = cc_insert_newline(base64->encode, len, 64);
	}
	if (ssl->op & CC_D)
		ssl->cc_output = (uint8_t *)ft_strdup((char *)base64->decode);
}

void				free_base64(t_base64 *base64)
{
	if (base64)
	{
		if (base64->str)
			free(base64->str);
		if (base64->encode)
			free(base64->encode);
		if (base64->decode)
			free(base64->decode);
		free(base64);
	}
}
