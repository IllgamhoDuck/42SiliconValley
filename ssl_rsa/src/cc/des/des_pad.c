/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:57:09 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 04:59:49 by hypark           ###   ########.fr       */
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
** asdfasdf 08 08 08 08 08 08 08 08
*/

void					des_padding(t_ssl *ssl, t_des *des)
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

void					des_zero_pad(t_des *des)
{
	uint32_t			pad_len;

	pad_len = des->len;
	while (pad_len % 8 != 0)
		pad_len++;
	des->padded_str = (uint8_t *)ft_strnew(pad_len);
	ft_memcpy(des->padded_str, des->str, des->len);
}

void					des_no_pad(t_des *des)
{
	uint32_t			pad_len;

	pad_len = des->len;
	if (pad_len % 8)
		des_invalid_input(1);
	while (pad_len % 8 != 0)
		pad_len--;
	des->padded_str = (uint8_t *)ft_strnew(pad_len);
	ft_memcpy(des->padded_str, des->str, pad_len);
	des->len = pad_len;
}

void					des_remove_padding(t_des *des)
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
