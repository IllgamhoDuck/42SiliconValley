/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:31:34 by hypark            #+#    #+#             */
/*   Updated: 2019/08/29 17:55:05 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "des.h"

int8_t				is_valid_char_des(uint8_t c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c == '+' || c == '/' || c == '=')
		return (1);
	return (0);
}

static void			preprocess_des_decode_input(t_ssl *ssl, t_des *des)
{
	int16_t			len;
	uint8_t			*decode;
	int16_t			decode_len;
	int16_t			i;
	int16_t			j;

	decode_len = cc_count_valid_char(ssl, des->str);
	if (!(decode = (uint8_t *)malloc(sizeof(uint8_t) * (decode_len + 1))))
		malloc_error("preprocess_des_decode_input");
	len = ft_strlen((char *)des->str);
	i = -1;
	j = -1;
	while (++i < len)
		if (is_valid_char_des(des->str[i]))
			decode[++j] = des->str[i];
	decode[++j] = '\0';
	free(des->str);
	des->str = decode;
	des->len = ft_strlen((char *)des->str);
}

t_des			*init_des(t_ssl *ssl)
{
	t_des		*des;

	if (!(des = (t_des *)ft_memalloc(sizeof(t_des))))
		malloc_error("t_des");
	des->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	if (ssl->op & CC_E)
		des->len = ft_strlen((char *)des->str);
	if (ssl->op & CC_D)
		preprocess_des_decode_input(ssl, des);
	if (ssl->op & CC_D)
	{
		if (des->len % 4 != 0 || des->len == 0)
		{
			free(des->str);
			des->str = NULL;
		}
	}
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
