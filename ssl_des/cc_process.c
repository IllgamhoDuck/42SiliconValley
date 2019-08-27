/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:01:10 by hypark            #+#    #+#             */
/*   Updated: 2019/08/27 00:51:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

char *g_cc_prefix[8] = {"BASE64", "DES", "DES-ECB", "DES-CDC", NULL};
char *g_c_command[8] = {"md5", "des", "des-ecb", "des-cdc", NULL};
t_cc_cipher_algorithm g_cipher_f[8] = {base64, NULL};
int32_t g_cc_cipher_size[7] = {4, 5, 7, 8, 6, 8, 4};

void				cc_stdin_process(t_ssl *ssl)
{
	ssl->ssl_input = read_file(0);
	if (ssl->ssl_input[0])
	{
		g_cipher_f[ssl->mdc](ssl);
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
		ssl->ssl_input = read_file(fd);
		g_cipher_f[ssl->cc](ssl);
		close(fd);
		cc_print_result(ssl, 2);
		free(ssl->ssl_input);
	}
}

void				cc_process(t_ssl *ssl)
{
	if (ssl->p_stdin == 1)
	{
		if (ssl->op & OP_R && ssl->op & OP_P)
			cc_stdin_process(ssl);
		if (!(ssl->op & OP_P) && !(ssl->op & OP_S))
			cc_stdin_process(ssl);
	}
	else
		cc_file_process(ssl);
}
