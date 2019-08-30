/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:01:33 by hypark            #+#    #+#             */
/*   Updated: 2019/08/30 04:08:10 by hypark           ###   ########.fr       */
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

static void				process_des_ecb(t_des *des, uint16_t block_n)
{
	uint64_t			*m;
	uint64_t			result;

	m = (uint64_t *)(des->padded_str + (block_n * 8));
	result = des_process_message(des, m[0]);
	ft_printf("result : %llx", result);
	ft_printf("result : %s", result);
}

void					des_ecb(t_ssl *ssl)
{
	t_des				*des;
	uint8_t				i;

	des = init_des(ssl);
	des_process(ssl, des);
	padding_des_ecb(des);
	des_generate_subkey(des);
	if (ssl->op & CC_D)
		des_decode_reverse_subkey(des);
	i = 0;
	while (i < des->len / 8)
	{
		process_des_ecb(des, i);
		i++;
	}
	if (ssl->op & CC_E && ssl->op & CC_A)
		des_encode_base64(ssl, des);
	store_result_des(ssl, des);
	free_des(des);
}
