/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 23:50:01 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 22:13:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "libft.h"

static uint8_t g_r[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

/*
** We can't use math.h so store it as a number
**for i from 0 to 63
**    k[i] := floor(abs(sin(i + 1)) × (2 pow 32))
*/

static uint32_t g_k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static void				padding_md5(t_md5 *md5)
{
	uint64_t			bit_len;
	uint32_t			pad_len;

	bit_len = md5->len * 8;
	pad_len = md5->len + 1;
	while (pad_len % 64 != 56)
		pad_len++;
	md5->padded_str = (uint8_t *)ft_strnew(pad_len + 8);
	ft_bzero(md5->padded_str, pad_len + 8);
	ft_memcpy(md5->padded_str, md5->str, md5->len);
	md5->padded_str[md5->len] = (uint8_t)128;
	while (++(md5->len) < pad_len)
		md5->padded_str[md5->len] = (uint8_t)0;
	ft_memcpy(md5->padded_str + pad_len, &bit_len, 8);
	md5->len += 8;
}

static void				fill_md5(t_md5 *md5, uint16_t block_n)
{
	uint32_t			*word;
	int8_t				i;

	word = (uint32_t *)(md5->padded_str + (block_n * 64));
	i = -1;
	while (++i < 16)
		md5->w[i] = word[i];
	i = -1;
	while (++i < 4)
		md5->abcd[i] = md5->h[i];
}

static void				process_md5(t_md5 *md5)
{
	int8_t				i;
	uint32_t			temp;

	i = -1;
	while (++i < 64)
	{
		if (i >= 0 && i <= 15)
			temp = R1_MD5(md5->abcd[0], md5->abcd[1], md5->abcd[2],
					md5->abcd[3], md5->w[i], g_k[i], g_r[i]);
		else if (i >= 16 && i <= 31)
			temp = R2_MD5(md5->abcd[0], md5->abcd[1], md5->abcd[2],
					md5->abcd[3], md5->w[(5 * i + 1) % 16], g_k[i], g_r[i]);
		else if (i >= 32 && i <= 47)
			temp = R3_MD5(md5->abcd[0], md5->abcd[1], md5->abcd[2],
					md5->abcd[3], md5->w[(3 * i + 5) % 16], g_k[i], g_r[i]);
		else if (i >= 48 && i <= 63)
			temp = R4_MD5(md5->abcd[0], md5->abcd[1], md5->abcd[2],
					md5->abcd[3], md5->w[(7 * i) % 16], g_k[i], g_r[i]);
		md5->abcd[0] = md5->abcd[3];
		md5->abcd[3] = md5->abcd[2];
		md5->abcd[2] = md5->abcd[1];
		md5->abcd[1] = temp;
	}
}

void					md5(t_ssl *ssl)
{
	t_md5				*md5;
	uint16_t			i;
	uint16_t			j;

	md5 = init_md5(ssl);
	padding_md5(md5);
	i = 0;
	while (i < md5->len / 64)
	{
		fill_md5(md5, i);
		process_md5(md5);
		j = -1;
		while (++j < ssl->hash_size)
			md5->h[j] += md5->abcd[j];
		i++;
	}
	store_result_md5(ssl, md5);
	free_md5(md5);
}
