/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:01:33 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 05:01:51 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

/*
** Plaintext message
** "Illgamho duck was doing crypto project at 42 school!"
** Key - 7770007770700000
** Hexadecimal
** "93 3f 83 fa 0d 94 29 ff" "29 e7 54 df 66 7f 01 99"
** "79 12 83 cf e2 4b fa 5e" "50 06 37 b6 70 c7 e5 81"
** "93 5e e2 94 92 81 4e 7c" "4b a1 27 5f cf 6a d3 eb"
** "5e e8 f6 cc 2c a1 22 a1"
** ======================================================================
** To process like this example we have to swap the bits.
** This is little endian system. So I made every calculation in
** little endian system, but we have to print it out in big endian system
** So we swap the endian again before storing it.
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
		m[0] = swap_endian64(m[0]);
		m[0] = des_process_message(m[0], subkey);
		m[0] = swap_endian64(m[0]);
		block_n++;
	}
	if (ssl->op & CC_D && ((ssl->op & CC_NOPAD) == 0))
		des_remove_padding(des);
}

void					des_ecb(t_ssl *ssl)
{
	t_des				*des;

	des = init_des(ssl);
	des_process(ssl, des);
	if (ssl->op & CC_BP)
	{
		des_print_salt_key_iv(ssl, des);
		free_des(des);
		return ;
	}
	if (ssl->op & CC_NOPAD)
		des_no_pad(des);
	else
		des_padding(ssl, des);
	process_des_ecb(ssl, des);
	if (ssl->op & CC_E && ssl->op & CC_SALT_HEADER)
		des_salt_header(des, 0);
	if (ssl->op & CC_E && ssl->op & CC_A)
		des_encode_base64(ssl, des);
	store_result_des(ssl, des);
	free_des(des);
}
