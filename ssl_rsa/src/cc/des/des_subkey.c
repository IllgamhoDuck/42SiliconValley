/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_subkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:31:06 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 04:59:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

static uint64_t		des_apply_pc1(uint64_t key)
{
	uint64_t		result;
	int8_t			i;

	result = 0;
	i = -1;
	while (++i < 56)
		FINDBIT64(key, g_pc1[i]) ? PUTBIT64(result, i) : 0;
	return (result);
}

static uint64_t		des_apply_pc2(uint64_t c, uint64_t d)
{
	uint64_t		result;
	uint64_t		key;
	int8_t			i;

	key = (c | d >> 28);
	result = 0;
	i = -1;
	while (++i < 48)
		FINDBIT64(key, g_pc2[i]) ? PUTBIT64(result, i) : 0;
	return (result);
}

void				des_generate_subkey(uint64_t *subkey, uint64_t key)
{
	uint64_t		c[16];
	uint64_t		d[16];
	uint64_t		pc1;
	int8_t			i;

	pc1 = des_apply_pc1(key);
	c[0] = pc1 & 0xfffffff000000000;
	d[0] = pc1 << 28;
	c[0] = ROTL28(c[0], g_shift[0]);
	d[0] = ROTL28(d[0], g_shift[0]);
	i = -1;
	while (++i < 15)
	{
		c[i + 1] = ROTL28(c[i], g_shift[i + 1]);
		d[i + 1] = ROTL28(d[i], g_shift[i + 1]);
	}
	i = -1;
	while (++i < 16)
		subkey[i] = des_apply_pc2(c[i], d[i]);
}
