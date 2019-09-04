/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:01:10 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 05:11:24 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "base64.h"
#include "des.h"

char *g_cc_prefix[11] = {
	"BASE64", "DES-CBC", "DES-ECB", "DES-CBC",
	"DES-CFB", "DES-OFB", "DES3-CBC", "DES3-ECB",
	"DES3-CBC", "DES3-OFB", NULL
};
char *g_c_command[11] = {
	"base64", "des", "des-ecb", "des-cbc",
	"des-cfb", "des-ofb", "des3", "des3-ecb",
	"des3-cbc", "des3-ofb", NULL
};
t_cc_cipher_algorithm g_cipher_f[11] = {
	base64, des_cbc, des_ecb, des_cbc,
	des_cfb, des_ofb, des3_cbc, des3_ecb,
	des3_cbc, des3_ofb, NULL
};

void				cc_stdin_process(t_ssl *ssl)
{
	ssl->ssl_input = read_file(0, ssl);
	if (ssl->ssl_input[0])
	{
		g_cipher_f[ssl->cc](ssl);
		cc_print_result(ssl, 0);
	}
	free(ssl->ssl_input);
}

static void			cc_file_process(t_ssl *ssl)
{
	int16_t			i;
	int16_t			fd;

	i = -1;
	while (++i < ssl->total)
	{
		if ((fd = open(ssl->cc_info->cc_input, O_RDONLY)) < 0)
		{
			no_file_dic(ssl);
			continue ;
		}
		ssl->ssl_input = read_file(fd, ssl);
		g_cipher_f[ssl->cc](ssl);
		cc_print_result(ssl, 0);
		free(ssl->ssl_input);
		close(fd);
	}
}

void				cc_process(t_ssl *ssl)
{
	if (ssl->p_stdin == 1)
		cc_stdin_process(ssl);
	else
		cc_file_process(ssl);
}
