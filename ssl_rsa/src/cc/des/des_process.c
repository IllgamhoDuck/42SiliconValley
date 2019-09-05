/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:44:43 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 02:07:13 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"
#include "md5.h"

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
		des->password = (uint8_t *)ft_strdup(ssl->cc_info->cc_password);
		return ;
	}
	ft_printf("enter %s ", g_c_command[ssl->cc]);
	ssl->op & CC_E ? password = ft_strdup(getpass("encryption password: ")) : 0;
	ssl->op & CC_D ? password = ft_strdup(getpass("decryption password: ")) : 0;
	if (ssl->op & CC_D)
	{
		des->password = (uint8_t *)password;
		return ;
	}
	ft_printf("Verifying - enter %s ", g_c_command[ssl->cc]);
	if (ft_strcmp(password, getpass("encryption password: ")))
		des_invalid_password();
	des->password = (uint8_t *)password;
}

/*
** Salt will have to be same as big endian order
** when user input 0xAAAAAAAAFFFFFFFF
** The memory order should be "AAAAAAAAFFFFFFFF"
** So we should swap the endian after cc_atoi_base
*/

static void			des_salt(t_ssl *ssl, t_des *des)
{
	int16_t			random_file;
	char			buff[8];

	if ((ssl->op & CC_S) && (ssl->op & CC_SALT_HEADER))
	{
		if (ft_strlen(ssl->cc_info->cc_salt) > 16)
			des_invalid_salt(0);
		if (cc_is_hex_str(ssl->cc_info->cc_salt) == 0)
			des_invalid_salt(1);
		ssl->cc_info->cc_salt = cc_pad_zero(ssl->cc_info->cc_salt, 16);
		des->salt = swap_endian64(cc_atoi_base(ssl->cc_info->cc_salt, 16));
		free(ssl->cc_info->cc_salt);
	}
	else
	{
		if ((random_file = open("/dev/urandom", O_RDONLY)) < 0)
			p_error("Failed while opening the /dev/urandom");
		if (read(random_file, buff, 8) != 8)
			p_error("Failed to read enough 8 Bytes data from /dev/urandom");
		ft_memcpy(&des->salt, buff, 8);
		close(random_file);
	}
}

static void			des_iv(t_ssl *ssl, t_des *des)
{
	if ((ssl->op & CC_V) && (ssl->cc != 2))
	{
		if (ft_strlen((char *)ssl->cc_info->cc_iv) > 32)
			des_invalid_iv(0);
		if (cc_is_hex_str(ssl->cc_info->cc_iv) == 0)
			des_invalid_iv(1);
		ssl->cc_info->cc_iv = cc_pad_zero(ssl->cc_info->cc_iv, 16);
		des->iv = cc_atoi_base(ssl->cc_info->cc_iv, 16);
		free(ssl->cc_info->cc_iv);
	}
	else if ((ssl->op & CC_K) && (ssl->cc != 2))
		des_invalid_iv(2);
}

static void			des_create_key_iv(t_des *des, char *pw_salt, uint32_t len)
{
	t_ssl			*md5_ssl;
	uint64_t		*n64;

	md5_ssl = init_ssl();
	md5_ssl->ssl_input = pw_salt;
	md5_ssl->hash_size = 4;
	md5_ssl->mut_len = len;
	md5_ssl->p_mutual = 1;
	md5(md5_ssl);
	n64 = (uint64_t *)md5_ssl->hash_output32;
	n64[0] = swap_endian64(n64[0]);
	n64[1] = swap_endian64(n64[1]);
	des->key = n64[0];
	des->iv = n64[1];
	free_ssl(md5_ssl);
}

void				des_process(t_ssl *ssl, t_des *des)
{
	char			*pw_salt;
	uint32_t		pass_len;

	if (ssl->op & CC_K)
	{
		if (cc_is_hex_str(ssl->cc_info->cc_key) == 0)
			des_invalid_key();
		ssl->cc_info->cc_key = cc_pad_zero(ssl->cc_info->cc_key, 16);
		des->key = cc_atoi_base(ssl->cc_info->cc_key, 16);
		free(ssl->cc_info->cc_key);
		ssl->op & CC_NOSALT ? 0 : des_salt(ssl, des);
		des_iv(ssl, des);
		return ;
	}
	des_password(ssl, des);
	ssl->op & CC_D && ssl->op & CC_SALT_HEADER ? 0 : des_salt(ssl, des);
	pass_len = ft_strlen((char *)des->password);
	pw_salt = ft_strnew(pass_len + (ssl->op & CC_NOSALT ? 0 : 8));
	ft_memcpy(pw_salt, des->password, pass_len);
	ssl->op & CC_NOSALT ? 0 : ft_memcpy(pw_salt + pass_len, &des->salt, 8);
	des_create_key_iv(des, pw_salt, pass_len + (ssl->op & CC_NOSALT ? 0 : 8));
	des_iv(ssl, des);
	free(pw_salt);
}
