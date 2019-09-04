/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3_ofb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 05:10:41 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 05:15:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

static void				process_des3_ofb(t_ssl *ssl, t_des *des)
{
	uint64_t			*m;
	uint8_t				block_n;
	uint64_t			subkey[3][16];

	des3_key_setting(ssl, des, subkey);
	block_n = 0;
	while (block_n < des->len / 8 + (des->len % 8 ? 1 : 0))
	{
		m = (uint64_t *)(des->padded_str + (block_n * 8));
		m[0] = swap_endian64(m[0]);
		des->iv = des_process_message(des->iv, subkey[0]);
		des->iv = des_process_message(des->iv, subkey[1]);
		des->iv = des_process_message(des->iv, subkey[2]);
		m[0] ^= des->iv;
		m[0] = swap_endian64(m[0]);
		block_n++;
	}
}

void					des3_ofb(t_ssl *ssl)
{
	t_des				*des;

	des = init_des(ssl);
	des3_process(ssl, des);
	if (ssl->op & CC_BP)
	{
		des_print_salt_key_iv(ssl, des);
		free_des(des);
		return ;
	}
	des_zero_pad(des);
	process_des3_ofb(ssl, des);
	if (ssl->op & CC_E && ssl->op & CC_SALT_HEADER)
		des_salt_header(des, 0);
	if (ssl->op & CC_E && ssl->op & CC_A)
		des_encode_base64(ssl, des);
	store_result_des(ssl, des);
	free_des(des);
}
