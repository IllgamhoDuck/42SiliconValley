/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:00:47 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 18:35:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "base64.h"

uint8_t g_encode_base64[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
	'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', '+', '/'
};

uint8_t g_decode_base64[123] = {
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 62, ' ',
	' ', ' ', 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, ' ', ' ',
	' ', ' ', ' ', ' ', ' ', 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	25, ' ', ' ', ' ', ' ', ' ', ' ', 26, 27, 28, 29, 30, 31, 32, 33,
	34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
	49, 50, 51
};

static void				padding_encode_input_base64(t_base64 *base64)
{
	uint32_t			encode_len;
	uint8_t				*padded_str;
	int8_t				i;

	base64->pad_len = 0;
	while (!(((base64->len + base64->pad_len) / 3) >= 1) || \
			!(((base64->len + base64->pad_len) % 3) == 0))
		base64->pad_len++;
	padded_str = (uint8_t *)ft_strnew(base64->len + base64->pad_len);
	ft_memcpy(padded_str, base64->str, base64->len);
	i = -1;
	while (++i < base64->pad_len)
		padded_str[base64->len + i] = (uint8_t)0;
	free(base64->str);
	base64->str = padded_str;
	encode_len = (base64->len + base64->pad_len) / 3 * 4;
	base64->encode = (uint8_t *)ft_strnew(encode_len);
}

static void				process_encode_base64(t_base64 *base64)
{
	int16_t				i;
	int16_t				total;

	i = -1;
	total = (base64->len + base64->pad_len) / 3;
	while (++i < total)
	{
		base64->encode[4 * i] |= base64->str[3 * i] >> 2;
		base64->encode[4 * i + 1] |= ((base64->str[3 * i] & 0x03) << 4);
		base64->encode[4 * i + 1] |= (base64->str[3 * i + 1] >> 4);
		base64->encode[4 * i + 2] |= ((base64->str[3 * i + 1] & 0x0F) << 2);
		base64->encode[4 * i + 2] |= (base64->str[3 * i + 2] >> 6);
		base64->encode[4 * i + 3] |= (base64->str[3 * i + 2] & 0x3F);
		base64->encode[4 * i] = g_encode_base64[base64->encode[4 * i]];
		base64->encode[4 * i + 1] = g_encode_base64[base64->encode[4 * i + 1]];
		base64->encode[4 * i + 2] = g_encode_base64[base64->encode[4 * i + 2]];
		base64->encode[4 * i + 3] = g_encode_base64[base64->encode[4 * i + 3]];
	}
	if (base64->pad_len >= 1)
		base64->encode[(total - 1) * 4 + 3] = '=';
	if (base64->pad_len == 2)
		base64->encode[(total - 1) * 4 + 2] = '=';
}

static void				decode_input_base64(t_base64 *base64)
{
	uint32_t			decode_len;

	base64->pad_len = 0;
	decode_len = (base64->len / 4) * 3;
	if (base64->str[base64->len - 1] == '=')
		base64->pad_len++;
	if (base64->str[base64->len - 2] == '=')
		base64->pad_len++;
	base64->decode = (uint8_t *)ft_strnew(decode_len - base64->pad_len);
}

static void				process_decode_base64(t_base64 *base64)
{
	int16_t				i;
	int16_t				total;

	i = -1;
	total = base64->len / 4;
	while (++i < total)
	{
		base64->str[4 * i] = g_decode_base64[base64->str[4 * i]];
		base64->str[4 * i + 1] = g_decode_base64[base64->str[4 * i + 1]];
		base64->decode[3 * i] |= (base64->str[4 * i] << 2);
		base64->decode[3 * i] |= ((base64->str[4 * i + 1] & 0x30) >> 4);
		if (base64->str[4 * i + 2] == '=')
			continue ;
		base64->str[4 * i + 2] = g_decode_base64[base64->str[4 * i + 2]];
		base64->decode[3 * i + 1] |= ((base64->str[4 * i + 1] & 0x0F) << 4);
		base64->decode[3 * i + 1] |= (base64->str[4 * i + 2] >> 2);
		if (base64->str[4 * i + 3] == '=')
			continue ;
		base64->str[4 * i + 3] = g_decode_base64[base64->str[4 * i + 3]];
		base64->decode[3 * i + 2] |= (base64->str[4 * i + 2] << 6);
		base64->decode[3 * i + 2] |= base64->str[4 * i + 3];
	}
}

/*
** If decoding is active when the input is not valid it will
** store NULL at base64->str. So it will turn without processing.
** 1. The length of decode input will be multiple of 4
** 2. The str of decode should not end with ' '
** 3. ' ' is allowed between the decode string
*/

void					base64(t_ssl *ssl)
{
	t_base64			*base64;

	base64 = init_base64(ssl);
	if (base64->str == NULL && ssl->op & CC_D)
		base64_invalid_decode_value();
	if (ssl->op & CC_E)
	{
		padding_encode_input_base64(base64);
		process_encode_base64(base64);
	}
	else if (ssl->op & CC_D)
	{
		decode_input_base64(base64);
		process_decode_base64(base64);
	}
	store_result_base64(ssl, base64);
	free_base64(base64);
}
