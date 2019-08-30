/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_subkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:31:06 by hypark            #+#    #+#             */
/*   Updated: 2019/08/30 01:20:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

static uint64_t		des_apply_pc1(t_des *des)
{
	uint64_t		result;
	uint64_t		*key;
	int8_t			i;

	key = (uint64_t *)des->key;
	key[0] = swap_endian64(key[0]);
	result = 0;
	i = -1;
	while (++i < 56)
		FINDBIT64(key[0], g_pc1[i]) ? PUTBIT64(result, i) : 0;
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

void				des_generate_subkey(t_des *des)
{
	uint64_t		c[16];
	uint64_t		d[16];
	uint64_t		pc1;
	int8_t			i;
	
	pc1 = des_apply_pc1(des);
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
	{
		des->subkey[i] = des_apply_pc2(c[i], d[i]);
		des->subkey[i] = swap_endian64(des->subkey[i]);
	}
}
