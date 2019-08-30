/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:01:33 by hypark            #+#    #+#             */
/*   Updated: 2019/08/29 18:11:18 by hypark           ###   ########.fr       */
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
	while (pad_len % 64 != 0)
		pad_len++;
	des->padded_str = (uint8_t *)ft_strnew(pad_len);
	ft_memcpy(des->padded_str, des->str, des->len);
	while (des->len < pad_len)
		des->padded_str[des->len++] = (uint8_t)0;
}

static void				process_des_ecb(t_des *des)
{
	des = 0;
}

void					des_ecb(t_ssl *ssl)
{
	t_des				*des;
	uint16_t			i;

	des = init_des(ssl);
	des_process(ssl, des);
	padding_des_ecb(des);
	i = 0;
	while (i < des->len / 64)
	{
		process_des_ecb(des);
		i++;
	}
	store_result_des(ssl, des);
	free_des(des);
}
