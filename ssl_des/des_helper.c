/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:31:34 by hypark            #+#    #+#             */
/*   Updated: 2019/08/30 04:07:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "des.h"

t_des			*init_des(t_ssl *ssl)
{
	t_des		*des;

	if (!(des = (t_des *)ft_memalloc(sizeof(t_des))))
		malloc_error("t_des");
	des->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	if (ssl->op & CC_A && ssl->op & CC_D)
		des_decode_base64(ssl, des);
	if (ssl->op & CC_A && ssl->op & CC_D)
		des_decode_base64(ssl, des);
	des->len = ft_strlen((char *)des->str);
	des->key = (uint8_t *)ssl->cc_info->cc_key;
	des->password = (uint8_t *)ssl->cc_info->cc_password;
	des->salt = (uint8_t *)ssl->cc_info->cc_salt;
	des->iv = (uint8_t *)ssl->cc_info->cc_iv;
	return (des);
}

void				store_result_des(t_ssl *ssl, t_des *des)
{
	int32_t		len;

	if (ssl->op & CC_E)
	{
		len = ft_strlen((char *)des->encode);
		ssl->cc_output = cc_insert_newline(des->encode, len, 64);
	}
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
		if (des->key)
			free(des->key);
		if (des->password)
			free(des->password);
		if (des->salt)
			free(des->salt);
		if (des->iv)
			free(des->iv);
		free(des);
	}
}
