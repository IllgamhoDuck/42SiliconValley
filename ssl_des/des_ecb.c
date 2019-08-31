/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:01:33 by hypark            #+#    #+#             */
/*   Updated: 2019/08/31 11:04:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"
#include "des_ecb.h"

static void				padding_des_ecb(t_des *des)
{
	uint32_t			pad_len;

	pad_len = des->len;
	while (pad_len % 8 != 0 || pad_len == 0)
		pad_len++;
	des->padded_str = (uint8_t *)ft_strnew(pad_len);
	ft_memcpy(des->padded_str, des->str, des->len);
	while (des->len < pad_len)
		des->padded_str[des->len++] = (uint8_t)0;
}

/*
** The plaintext message "Your lips are smoother than vaseline" is, in hexadecimal,
** "596F7572206C6970 732061726520736D 6F6F746865722074 68616E2076617365 6C696E650D0A"
** ===============================================================================
** To process like this example we have to swap the bits.
** This is little endian system
*/

static void				process_des_ecb(t_ssl *ssl, t_des *des)
{
	uint64_t			*m;
	uint8_t				block_n;
	uint64_t			subkey[16];

	des_generate_subkey(subkey, des->key);
	if (ssl->op & CC_D)
		des_decode_reverse_subkey(subkey);
	block_n = 0;
	while (block_n < des->len / 8)
	{
		m = (uint64_t *)(des->padded_str + (block_n * 8));
		//ssl->op & CC_E ? m[0] = swap_endian64(m[0]) : 0;
		m[0] = des_process_message(m[0], subkey);
		//ssl->op & CC_D ? m[0] = swap_endian64(m[0]) : 0;
		block_n++;
	}
	if (ssl->op & CC_E)
		des->encode = (uint8_t *)ft_strdup((char *)des->padded_str);
	if (ssl->op & CC_D)
		des->decode = (uint8_t *)ft_strdup((char *)des->padded_str);
}

void					des_ecb(t_ssl *ssl)
{
	t_des				*des;

	des = init_des(ssl);
	des_process(ssl, des);
	padding_des_ecb(des);
	process_des_ecb(ssl, des);
	if (ssl->op & CC_E && ssl->op & CC_SALT_HEADER)
		des_salt_header(des, 1);
	if (ssl->op & CC_E && ssl->op & CC_A)
		des_encode_base64(ssl, des);
	store_result_des(ssl, des);
	free_des(des);
}
