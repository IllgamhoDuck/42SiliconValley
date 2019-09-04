/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 03:48:57 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 05:28:41 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"
#include "md5.h"

void				des3_d1_key(t_des *des, t_ssl *ssl, char *s, uint32_t len)
{
	uint64_t		*n64;
	char			*d_1;

	n64 = (uint64_t *)ssl->hash_output32;
	n64[0] = swap_endian64(n64[0]);
	n64[1] = swap_endian64(n64[1]);
	d_1 = ft_strnew(16 + len);
	ft_memcpy(d_1, n64, 8);
	ft_memcpy(d_1 + 8, n64 + 1, 8);
	ft_memcpy(d_1 + 16, s, len);
	ssl->ssl_input = d_1;
	ssl->mut_len = len + 16;
	md5(ssl);
	n64[0] = swap_endian64(n64[0]);
	n64[1] = swap_endian64(n64[1]);
	des->key3 = n64[0];
	des->iv = n64[1];
	free(d_1);
}

void				des3_key(t_ssl *ssl, t_des *des)
{
	char			*key1;
	char			*key2;
	char			*key3;

	ssl->cc_info->cc_key = cc_pad_zero(ssl->cc_info->cc_key, 48);
	key1 = ft_strnew(16);
	key2 = ft_strnew(16);
	key3 = ft_strnew(16);
	ft_memcpy(key1, ssl->cc_info->cc_key, 16);
	ft_memcpy(key2, ssl->cc_info->cc_key + 16, 16);
	ft_memcpy(key3, ssl->cc_info->cc_key + 32, 16);
	des->key1 = cc_atoi_base(key1, 16);
	des->key2 = cc_atoi_base(key2, 16);
	des->key3 = cc_atoi_base(key3, 16);
	free(ssl->cc_info->cc_key);
	free(key1);
	free(key2);
	free(key3);
}

void				des3_reverse_key(t_ssl *ssl, t_des *des)
{
	uint64_t		temp_key;

	if (ssl->op & CC_E)
		return ;
	temp_key = des->key1;
	des->key1 = des->key3;
	des->key3 = temp_key;
}

void				des3_key_setting(t_ssl *ssl, t_des *des, uint64_t k[3][16])
{
	des_generate_subkey(k[0], des->key1);
	des_generate_subkey(k[1], des->key2);
	des_generate_subkey(k[2], des->key3);
	if (ssl->cc == 9)
	{
		des_decode_reverse_subkey(k[1]);
		return ;
	}
	ssl->op & CC_E ? des_decode_reverse_subkey(k[1]) : 0;
	ssl->op & CC_D ? des_decode_reverse_subkey(k[0]) : 0;
	ssl->op & CC_D ? des_decode_reverse_subkey(k[2]) : 0;
}
