/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:31:34 by hypark            #+#    #+#             */
/*   Updated: 2019/08/31 11:15:54 by hypark           ###   ########.fr       */
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

	if (ssl->op & CC_P && !(ssl->op & CC_NOSALT))
		ssl->op |= CC_SALT_HEADER;
	if (!(des = (t_des *)ft_memalloc(sizeof(t_des))))
		malloc_error("t_des");
	des->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	des->len = ft_strlen((char *)des->str);
	if (ssl->op & CC_D && ssl->op & CC_A)
		des_decode_base64(ssl, des);
	if (ssl->op & CC_D && ssl->op & CC_SALT_HEADER)
		des_salt_header(des, 1);
	des->password = (uint8_t *)ssl->cc_info->cc_password;
	return (des);
}

void				store_result_des(t_ssl *ssl, t_des *des)
{
	if (ssl->op & CC_E)
		ssl->cc_output = (uint8_t *)ft_strdup((char *)des->encode);
	if (ssl->op & CC_D)
		ssl->cc_output = (uint8_t *)ft_strdup((char *)des->decode);
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
