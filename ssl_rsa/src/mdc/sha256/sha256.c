/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:16:55 by hypark            #+#    #+#             */
/*   Updated: 2019/08/28 00:26:45 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"
#include "libft.h"

/*
** We can't use math.h so store it as a number
** first 32 bits of the fractional parts of the cube roots
** of the first 64 primes 2..311:
*/

static uint32_t g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void				padding_sha256(t_sha256 *sha256)
{
	uint64_t			bit_len;
	uint32_t			pad_len;

	bit_len = sha256->len * 8;
	pad_len = sha256->len + 1;
	while (pad_len % 64 != 56)
		pad_len++;
	sha256->padded_str = (uint8_t *)ft_strnew(pad_len + 8);
	ft_memcpy(sha256->padded_str, sha256->str, sha256->len);
	sha256->padded_str[sha256->len] = (uint8_t)128;
	while (++(sha256->len) < pad_len)
		sha256->padded_str[sha256->len] = (uint8_t)0;
	bit_len = swap_endian64(bit_len);
	ft_memcpy(sha256->padded_str + pad_len, &bit_len, 8);
	sha256->len += 8;
}

static void				fill_sha256(t_sha256 *sha256, uint16_t block_n)
{
	uint32_t			*word;
	int8_t				i;

	word = (uint32_t *)(sha256->padded_str + (block_n * 64));
	i = -1;
	while (++i < 16)
		sha256->w[i] = swap_endian32(word[i]);
	i = 15;
	while (++i < 64)
		sha256->w[i] = WI_SHA256(sha256->w[i - 2], sha256->w[i - 7],
							sha256->w[i - 15], sha256->w[i - 16]);
	i = -1;
	while (++i < 8)
		sha256->words[i] = sha256->h[i];
}

/*
** words - abcdefgh
*/

static void				process_sha256(t_sha256 *sha256)
{
	int8_t				i;
	uint32_t			temp_1;
	uint32_t			temp_2;

	i = -1;
	while (++i < 64)
	{
		temp_1 = T1_SHA256(sha256->words[4], sha256->words[5],
				sha256->words[6], sha256->words[7],
				g_k[i], sha256->w[i]);
		temp_2 = T2_SHA256(sha256->words[0], sha256->words[1],
				sha256->words[2]);
		sha256->words[7] = sha256->words[6];
		sha256->words[6] = sha256->words[5];
		sha256->words[5] = sha256->words[4];
		sha256->words[4] = sha256->words[3] + temp_1;
		sha256->words[3] = sha256->words[2];
		sha256->words[2] = sha256->words[1];
		sha256->words[1] = sha256->words[0];
		sha256->words[0] = temp_1 + temp_2;
	}
}

void					sha256(t_ssl *ssl)
{
	t_sha256			*sha256;
	uint16_t			i;
	uint16_t			j;

	sha256 = init_sha256(ssl);
	padding_sha256(sha256);
	i = 0;
	while (i < sha256->len / 64)
	{
		fill_sha256(sha256, i);
		process_sha256(sha256);
		j = -1;
		while (++j < ssl->hash_size)
			sha256->h[j] += sha256->words[j];
		i++;
	}
	store_result_sha256(ssl, sha256);
	free_sha256(sha256);
}
