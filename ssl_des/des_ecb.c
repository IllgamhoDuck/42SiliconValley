/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:01:33 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 17:51:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

/*
** padding number is chosen by how many pads we need to put on
** asdfasdf -> pad number 0  asdfasdf 
** asdf -> pad number 4 ---- asdf 04 04 04 04
** a -> pad_number 7 ------- a 07 07 07 07 07 07 07
*/

/*
** If the input is exactly 8 then pad eight 08
*/

static void				padding_des_ecb(t_ssl *ssl, t_des *des)
{
	uint32_t			pad_len;
	uint8_t				pad_number;

	pad_len = des->len;
	if (ssl->op & CC_D && pad_len % 8)
		des_invalid_input(1);
	if (ssl->op & CC_E)
		while (pad_len % 8 != 0 || pad_len == 0)
			pad_len++;
	if (ssl->op & CC_D)
		while (pad_len % 8 != 0)
			pad_len--;
	if (ssl->op & CC_E && des->len == pad_len)
		pad_len += 8;
	des->padded_str = (uint8_t *)ft_strnew(pad_len);
	ssl->op & CC_E ? ft_memcpy(des->padded_str, des->str, des->len) : 0;
	ssl->op & CC_D ? ft_memcpy(des->padded_str, des->str, pad_len) : 0;
	if (ssl->op & CC_D)
		return ;
	pad_number = pad_len - des->len;
	while (des->len < pad_len)
		des->padded_str[des->len++] = pad_number;
}

static void				remove_padding_des_ecb(t_des *des)
{
	uint32_t			i;
	uint32_t			pad_len;
	char				*temp;

	i = des->len - 1;
	pad_len = 0;
	if (des->padded_str[i] >= 1 && des->padded_str[i] <= 8)
		pad_len = des->padded_str[i];
	else
		des_invalid_input(3);
	des->len -= pad_len;
	temp = ft_strnew(des->len);
	ft_memcpy(temp, des->padded_str, des->len);
	free(des->padded_str);
	des->padded_str = (uint8_t *)temp;
}

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
	ssl->op & CC_D ? remove_padding_des_ecb(des) : 0;
	ssl->op & CC_E ? des->encode = (uint8_t *)ft_strnew(des->len) : 0;
	ssl->op & CC_D ? des->decode = (uint8_t *)ft_strnew(des->len) : 0;
	ssl->op & CC_E ? ft_memcpy(des->encode, des->padded_str, des->len) : 0;
	ssl->op & CC_D ? ft_memcpy(des->decode, des->padded_str, des->len) : 0;
}

void					des_ecb(t_ssl *ssl)
{
	t_des				*des;

	des = init_des(ssl);
	des_process(ssl, des);
	padding_des_ecb(ssl, des);
	process_des_ecb(ssl, des);
	if (ssl->op & CC_BP) 
	{
		des_print_salt_key(des);
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
