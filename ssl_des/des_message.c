/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 02:01:49 by hypark            #+#    #+#             */
/*   Updated: 2019/09/02 21:15:14 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

static uint64_t		des_apply_ip(uint64_t m)
{
	uint64_t		result;
	int8_t			i;

	result = 0;
	i = -1;
	while (++i < 64)
		FINDBIT64(m, g_ip1[i]) ? PUTBIT64(result, i) : 0;
	return (result);
}

static uint64_t		des_apply_expand(uint64_t r)
{
	uint64_t		result;
	int8_t			i;

	result = 0;
	i = -1;
	while (++i < 48)
		FINDBIT64(r, g_expand[i]) ? PUTBIT64(result, i) : 0;
	return (result);
}

static uint64_t		des_apply_p(uint64_t s)
{
	uint64_t		result;
	int8_t			i;

	result = 0;
	i = -1;
	while (++i < 32)
		FINDBIT64(s, g_p[i]) ? PUTBIT64(result, i) : 0;
	return (result);
}

static uint64_t		des_feistel(uint64_t r, uint64_t subkey)
{
	uint64_t		result;
	uint64_t		b[8];
	uint64_t		s[8];
	int8_t			i;
	
	r = des_apply_expand(r);
	result = subkey ^ r;
	i = -1;
	while (++i < 8)
		b[i] = ((result << (i * 6)) & 0xfc00000000000000);
	i = -1;
	while (++i < 8)
	{
		s[i] = g_s[i][(FINDBIT64(b[i], 1) * 2 + FINDBIT64(b[i], 6)) * 16 \
				+ ((b[i] >> 59) & 0xf)];
		s[i] <<= 60;
	}
	result = 0;
	i = -1;
	while (++i < 8)
		result |= (s[i] >> (i * 4));
	result = des_apply_p(result);
	return (result);
}

uint64_t				des_process_message(uint64_t m, uint64_t *subkey)
{
	uint64_t			l[16];
	uint64_t			r[16];
	uint64_t			result;
	int8_t				i;
	
	m = des_apply_ip(m);
	l[0] = m & 0xffffffff00000000;
	r[0] = m << 32;
	l[1] = r[0];
	r[1] = l[0] ^ des_feistel(r[0], subkey[0]);
	l[0] = l[1];
	r[0] = r[1];
	i = -1;
	while (++i < 15)
	{
		l[i + 1] = r[i];
		r[i + 1] = l[i] ^ des_feistel(r[i], subkey[i + 1]);
	}
	r[15] |= (l[15] >> 32);
	result = 0;
	i = -1;
	while (++i < 64)
		FINDBIT64(r[15], g_ip2[i]) ? PUTBIT64(result, i) : 0;
	return (result);
}
