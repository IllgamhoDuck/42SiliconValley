/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_cbc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:01:33 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 23:01:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

/*
** The plaintext message "Your lips are smoother than vaseline" is,
** in hexadecimal,
** "596F7572206C6970 732061726520736D 6F6F746865722074
** 68616E2076617365 6C696E650D0A"
** ======================================================================
** To process like this example we have to swap the bits.
** This is little endian system. So I made every calculation in
** little endian system, but we have to print it out in big endian system
** So we swap the endian again before storing it.
*/

static void				process_des_cbc(t_ssl *ssl, t_des *des)
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
		m[0] = swap_endian64(m[0]);
		ssl->op & CC_E ? m[0] ^= des->iv : 0;
		ssl->op & CC_D ? des->prev_m = m[0] : 0;
		m[0] = des_process_message(m[0], subkey);
		ssl->op & CC_E ? des->iv = m[0] : 0;
		ssl->op & CC_D ? m[0] ^= des->iv : 0;
		ssl->op & CC_D ? des->iv = des->prev_m : 0;
		m[0] = swap_endian64(m[0]);
		block_n++;
	}
	if (ssl->op & CC_D && ((ssl->op & CC_NOPAD) == 0))
		des_remove_padding(des);
}

void					des_cbc(t_ssl *ssl)
{
	t_des				*des;

	des = init_des(ssl);
	des_process(ssl, des);
	if (ssl->op & CC_NOPAD)
		des_no_pad(des);
	else
		des_padding(ssl, des);
	process_des_cbc(ssl, des);
	if (ssl->op & CC_BP) 
	{
		des_print_salt_key(ssl, des);
		free_des(des);
		return ;
	}
	if (ssl->op & CC_E && ssl->op & CC_SALT_HEADER)
		des_salt_header(des, 0);
	if (ssl->op & CC_E && ssl->op & CC_A)
		des_encode_base64(ssl, des);
	store_result_des(ssl, des);
	free_des(des);
}
