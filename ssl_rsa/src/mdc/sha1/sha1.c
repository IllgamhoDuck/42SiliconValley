/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:23:28 by hypark            #+#    #+#             */
/*   Updated: 2019/08/28 00:26:18 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha1.h"
#include "libft.h"

/*
** We can't use math.h so store it as a number
** first 32 bits of the fractional parts of the cube roots
** of the first 64 primes 2..311:
*/

static void				padding_sha1(t_sha1 *sha1)
{
	uint64_t			bit_len;
	uint32_t			pad_len;

	bit_len = sha1->len * 8;
	pad_len = sha1->len + 1;
	while (pad_len % 64 != 56)
		pad_len++;
	sha1->padded_str = (uint8_t *)ft_strnew(pad_len + 8);
	ft_memcpy(sha1->padded_str, sha1->str, sha1->len);
	sha1->padded_str[sha1->len] = (uint8_t)128;
	while (++(sha1->len) < pad_len)
		sha1->padded_str[sha1->len] = (uint8_t)0;
	bit_len = swap_endian64(bit_len);
	ft_memcpy(sha1->padded_str + pad_len, &bit_len, 8);
	sha1->len += 8;
}

static void				fill_sha1(t_sha1 *sha1, uint16_t block_n)
{
	uint32_t			*word;
	int8_t				i;

	word = (uint32_t *)(sha1->padded_str + (block_n * 64));
	i = -1;
	while (++i < 16)
		sha1->w[i] = swap_endian32(word[i]);
	i = 15;
	while (++i < 80)
		sha1->w[i] = WI_SHA1(sha1->w[i - 3], sha1->w[i - 8],
							sha1->w[i - 14], sha1->w[i - 16]);
	i = -1;
	while (++i < 5)
		sha1->words[i] = sha1->h[i];
}

/*
** words - abcde
*/

static void				move_data_sha1(t_sha1 *sha1, uint32_t temp)
{
	sha1->words[4] = sha1->words[3];
	sha1->words[3] = sha1->words[2];
	sha1->words[2] = ROTL32(sha1->words[1], 30);
	sha1->words[1] = sha1->words[0];
	sha1->words[0] = temp;
}

static void				process_sha1(t_sha1 *sha1)
{
	int8_t				i;
	uint32_t			temp;

	i = -1;
	while (++i < 80)
	{
		if (i >= 0 && i <= 19)
			temp = R1_SHA1(sha1->words[0], sha1->words[1], sha1->words[2],
					sha1->words[3], sha1->words[4],
					0x5A827999, sha1->w[i]);
		else if (i >= 20 && i <= 39)
			temp = R2_SHA1(sha1->words[0], sha1->words[1], sha1->words[2],
					sha1->words[3], sha1->words[4],
					0x6ED9EBA1, sha1->w[i]);
		else if (i >= 40 && i <= 59)
			temp = R3_SHA1(sha1->words[0], sha1->words[1], sha1->words[2],
					sha1->words[3], sha1->words[4],
					0x8F1BBCDC, sha1->w[i]);
		else if (i >= 60 && i <= 79)
			temp = R4_SHA1(sha1->words[0], sha1->words[1], sha1->words[2],
					sha1->words[3], sha1->words[4],
					0xCA62C1D6, sha1->w[i]);
		move_data_sha1(sha1, temp);
	}
}

void					sha1(t_ssl *ssl)
{
	t_sha1				*sha1;
	uint16_t			i;
	uint16_t			j;

	sha1 = init_sha1(ssl);
	padding_sha1(sha1);
	i = 0;
	while (i < sha1->len / 64)
	{
		fill_sha1(sha1, i);
		process_sha1(sha1);
		j = -1;
		while (++j < ssl->hash_size)
			sha1->h[j] += sha1->words[j];
		i++;
	}
	store_result_sha1(ssl, sha1);
	free_sha1(sha1);
}
