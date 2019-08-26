/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:43:50 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 20:06:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "md5.h"
#include "sha256.h"

t_mdc_hash_algorithm g_mdc_hash_f[3] = {md5, sha256, NULL};

void				mdc_string_process(t_ssl *ssl, char *str)
{
	ssl->ssl_input = ft_strdup(str);
	g_mdc_hash_f[ssl->mdc](ssl);
	mdc_print_result(ssl, 1);
	free(ssl->ssl_input);
}

/*
** Original ssl doesn't printout the newline when they are printing out
** the STDIN when there is '-p' option.
** But I changed it to print newline out when there is no newline.
** And don't print newline if there is some.
*/

void				mdc_stdin_process(t_ssl *ssl)
{
	ssl->ssl_input = read_file(0);
	if (ssl->op & OP_P && ssl->ssl_input[0] && !(ssl->op & OP_P_NOPRINT))
	{
		ft_printf("%s", ssl->ssl_input);
		ssl->op |= OP_P_NOPRINT;
	}
	g_mdc_hash_f[ssl->mdc](ssl);
	mdc_print_result(ssl, 0);
	free(ssl->ssl_input);
}

static void			mdc_file_process(t_ssl *ssl)
{
	int16_t			i;
	int16_t			fd;

	i = -1;
	while (++i < ssl->total)
	{
		ssl->i = i;
		if ((fd = open(ssl->files[i], O_RDONLY)) < 0)
		{
			no_file_dic(ssl);
			continue ;
		}
		ssl->ssl_input = read_file(fd);
		g_mdc_hash_f[ssl->mdc](ssl);
		close(fd);
		mdc_print_result(ssl, 2);
		free(ssl->ssl_input);
	}
}

void				mdc_process(t_ssl *ssl)
{
	if (ssl->p_stdin == 1)
	{
		if (ssl->op & OP_R && ssl->op & OP_P)
			mdc_stdin_process(ssl);
		if (!(ssl->op & OP_P) && !(ssl->op & OP_S))
			mdc_stdin_process(ssl);
	}
	else
		mdc_file_process(ssl);
}
