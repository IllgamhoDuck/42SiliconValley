/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:44:43 by hypark            #+#    #+#             */
/*   Updated: 2019/08/29 20:36:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"
#include "md5.h"
#include "base64.h"

/*
** Password and salt is to generate KEY
** If key is provided the password will be used? -> "NO!!!"
** If key is provided the salt will be used? -> "NO!!!"
** "But here is what the real weird act of openssl begins"
** ======================================================
** There is a weird behavior in openssl when Key is provided
** Key exist and salt is there then the salted value added to encode
** Then you should decode with the salt.
** The salt will only considered when the password exist
** If you encode with salt you must decode with salt.
** Whatever salt and password value you put on it while
** encoding and decoding the output will be always the same
** It 100% depends on the Key
** ======================================================
** WEIRD ACT EXAMPLE "=======Salted__ appear=============="
** plain text - duck
** ENCODE - KEY 1 SALT 2124 PASSWORD 12124124
** enc text - Salted__Q%Q%� 1���
** DECODE - KEY 1 SALT 12412125 PASSWORD 1212
** plain text - duck
*/

static void			des_password(t_ssl *ssl, t_des *des)
{
	char			*password;

	if (ssl->op & CC_P)
	{
		des->password = (uint8_t *)ft_strdup((char *)des->password);
		return ;
	}
	ft_printf("enter %s ", g_c_command[ssl->cc]);
	password = ft_strdup(getpass("encryption password: "));
	ft_printf("Verifying - enter %s ", g_c_command[ssl->cc]);
	if (ft_strcmp(password,	getpass("encryption password: ")))
			des_invalid_password();
	des->password = (uint8_t *)password;
}

static void			des_salt(t_ssl *ssl, t_des *des)
{
	int16_t			random_file;
	uint64_t		temp;
	char			buff[8];

	if (ssl->op & CC_S)
	{
		if (ft_strlen((char *)des->salt) > 16)
			des_invalid_salt(0);
		if (cc_is_hex_str(des->salt) == 0)
			des_invalid_salt(1);
		des->salt = cc_pad_zero(des->salt, 16);
		temp = swap_endian64(cc_atoi_base(des->salt, 16));
		ft_memcpy(des->salt, &temp, 8);
		des->salt[8] = '\0';
	}
	else
	{
		if ((random_file = open("/dev/urandom", O_RDONLY)) < 0)
			p_error("Failed while opening the /dev/urandom");
		if (read(random_file, buff, 8) != 8)
			p_error("Failed to read enough 8 Bytes data from /dev/urandom");
		des->salt = (uint8_t *)ft_strsub(buff, 0, 8);
		close(random_file);
	}
}

static void			des_iv(t_ssl *ssl, t_des *des)
{
	uint64_t		temp;

	if ((ssl->op & CC_V) && (ssl->cc != 2))
	{
		if (ft_strlen((char *)des->iv) > 32)
			des_invalid_iv(0);
		if (cc_is_hex_str(des->iv) == 0)
			des_invalid_iv(1);
		des->iv = cc_pad_zero(des->iv, 16);
		temp = swap_endian64(cc_atoi_base(des->iv, 16));
		ft_memcpy(des->iv, &temp, 8);
		des->iv[8] = '\0';
	}
	else if (ssl->cc != 2)
		des_invalid_iv(2);
}

static void			des_create_key_iv(t_des *des, char *pw_salt)
{
	t_ssl			*md5_ssl;
	uint64_t		*n64;

	md5_ssl = init_ssl();
	md5_ssl->ssl_input = pw_salt;
	md5_ssl->hash_size = 4;
	md5(md5_ssl);
	n64 = (uint64_t *)md5_ssl->hash_output32;
	des->key = (uint8_t *)ft_strnew(8);
	des->iv = (uint8_t *)ft_strnew(8);
	ft_memcpy(des->key, n64, 8);
	ft_memcpy(des->iv, n64 + 1, 8);
	free_ssl(md5_ssl);
}

void				des_process(t_ssl *ssl, t_des *des)
{
	char			*pw_salt;
	uint64_t		temp;

	if (ssl->op & CC_K)
	{
		if (cc_is_hex_str(des->key) == 0)
			des_invalid_key();
		des->key = cc_pad_zero(des->key, 16);
		temp = swap_endian64(cc_atoi_base(des->key, 16));
		ft_memcpy(des->key, &temp, 8);
		des->key[8] = '\0';
		des_iv(ssl, des);
	}
	else
	{
		des_password(ssl, des);
		des_salt(ssl, des);
		pw_salt = ft_strjoin((char *)des->password, (char *)des->salt);
		des_create_key_iv(des, pw_salt);
		free(pw_salt);
	}
}
