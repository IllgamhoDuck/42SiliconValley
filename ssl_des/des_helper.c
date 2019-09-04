/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:31:34 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 16:16:16 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "des.h"

/*
** If there is password there is a salt
** -nosalt option isn't builtin yet but maybe later
*/

t_des			*init_des(t_ssl *ssl)
{
	t_des		*des;

	if ((ssl->op & CC_P && !(ssl->op & CC_NOSALT)) || !(ssl->op & CC_K))
		ssl->op |= CC_SALT_HEADER;
	if (!(des = (t_des *)ft_memalloc(sizeof(t_des))))
		malloc_error("t_des");
	if (ssl->p_mutual)
		des->len = ssl->mut_len;
	else
		des->len = ssl->read_len;
	des->str = (uint8_t *)ft_strnew(des->len);
	ft_memcpy(des->str, ssl->ssl_input, des->len);
	if (ssl->op & CC_D && ssl->op & CC_A)
		des_decode_base64(ssl, des);
	if (ssl->op & CC_D && ssl->op & CC_SALT_HEADER)
		des_salt_header(des, 1);
	return (des);
}

void				store_result_des(t_ssl *ssl, t_des *des)
{
	ssl->cc_output = ft_strnew(des->len);
	ssl->op & CC_E ? ft_memcpy(ssl->cc_output, des->encode, des->len) : 0;
	ssl->op & CC_D ? ft_memcpy(ssl->cc_output, des->decode, des->len) : 0;
	ssl->cc_len = des->len;
}

void				free_des(t_des *des)
{
	if (des)
	{
		if (des->str)
			free(des->str);
		if (des->padded_str)
			free(des->padded_str);
		if (des->prev_block)
			free(des->prev_block);
		if (des->encode)
			free(des->encode);
		if (des->decode)
			free(des->decode);
		if (des->password)
			free(des->password);
		free(des);
	}
}
