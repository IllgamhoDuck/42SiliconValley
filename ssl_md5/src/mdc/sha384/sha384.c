/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:58:34 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:55:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha384.h"
#include "libft.h"

/*
** We can't use math.h so store it as a number
** first 64 bits of the fractional parts of the cube roots
** of the first 80 primes 2..409:
*/

static uint64_t g_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

static void				padding_sha384(t_sha384 *sha384)
{
	uint64_t			bit_len;
	uint64_t			pad_len;

	bit_len = sha384->len * 8;
	pad_len = sha384->len + 1;
	while (pad_len % 128 != 112)
		pad_len++;
	sha384->padded_str = (uint8_t *)ft_strnew(pad_len + 16);
	ft_bzero(sha384->padded_str, pad_len + 16);
	ft_memcpy(sha384->padded_str, sha384->str, sha384->len);
	sha384->padded_str[sha384->len] = (uint8_t)128;
	while (++(sha384->len) < pad_len)
		sha384->padded_str[sha384->len] = (uint8_t)0;
	bit_len = swap_endian64(bit_len);
	ft_memcpy(sha384->padded_str + pad_len + 8, &bit_len, 8);
	sha384->len += 16;
}

static void				fill_sha384(t_sha384 *sha384, uint16_t block_n)
{
	uint64_t			*word;
	int8_t				i;

	word = (uint64_t *)(sha384->padded_str + (block_n * 128));
	i = -1;
	while (++i < 16)
		sha384->w[i] = swap_endian64(word[i]);
	i = 15;
	while (++i < 80)
		sha384->w[i] = WI_SHA384(sha384->w[i - 2], sha384->w[i - 7],
							sha384->w[i - 15], sha384->w[i - 16]);
	i = -1;
	while (++i < 8)
		sha384->words[i] = sha384->h[i];
}

/*
** words - abcdefgh
*/

static void				process_sha384(t_sha384 *sha384)
{
	int8_t				i;
	uint64_t			temp_1;
	uint64_t			temp_2;

	i = -1;
	while (++i < 80)
	{
		temp_1 = T1_SHA384(sha384->words[4], sha384->words[5],
				sha384->words[6], sha384->words[7],
				g_k[i], sha384->w[i]);
		temp_2 = T2_SHA384(sha384->words[0], sha384->words[1],
				sha384->words[2]);
		sha384->words[7] = sha384->words[6];
		sha384->words[6] = sha384->words[5];
		sha384->words[5] = sha384->words[4];
		sha384->words[4] = sha384->words[3] + temp_1;
		sha384->words[3] = sha384->words[2];
		sha384->words[2] = sha384->words[1];
		sha384->words[1] = sha384->words[0];
		sha384->words[0] = temp_1 + temp_2;
	}
}

void					sha384(t_ssl *ssl)
{
	t_sha384			*sha384;
	uint16_t			i;
	uint16_t			j;

	sha384 = init_sha384(ssl);
	padding_sha384(sha384);
	i = 0;
	while (i < sha384->len / 128)
	{
		fill_sha384(sha384, i);
		process_sha384(sha384);
		j = -1;
		while (++j < 8)
			sha384->h[j] += sha384->words[j];
		i++;
	}
	store_result_sha384(ssl, sha384);
	free_sha384(sha384);
}
