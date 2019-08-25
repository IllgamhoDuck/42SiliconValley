/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:56:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 16:24:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "md5.h"
#include "sha256.h"

t_hash_algorithm g_hash_f[3] = {md5, sha256, NULL};

static void			string_process(t_ssl *ssl, char *str)
{
	ssl->hash_input = ft_strdup(str);
	if (ssl->mdc != -1)
		g_hash_f[ssl->mdc](ssl);
	print_result(ssl, 1);
	free(ssl->hash_input);
	ssl->op &= ~OP_S;
}

/*
** Original ssl doesn't printout the newline when they are printing out
** the STDIN when there is '-p' option.
** But I changed it to print newline out when there is no newline.
** And don't print newline if there is some.
*/

void				stdin_process(t_ssl *ssl)
{
	ssl->hash_input = read_file(0);
	if (ssl->op & OP_P && ssl->hash_input[0] && !(ssl->op & OP_P_NOPRINT))
	{
		ft_printf("%s", ssl->hash_input);
		ssl->op |= OP_P_NOPRINT;
	}
	if (ssl->mdc != -1)
		g_hash_f[ssl->mdc](ssl);
	print_result(ssl, 0);
	free(ssl->hash_input);
}

static void			file_process(t_ssl *ssl)
{
	int16_t			i;
	int16_t			fd;

	i = -1;
	while (++i < ssl->total)
	{
		ssl->i = i;
		if ((fd = open(ssl->files[i], O_RDONLY)) < 0 || ssl->op & OP_S)
		{
			if (ssl->op & OP_S)
				string_process(ssl, ssl->files[i]);
			else
				no_file_dic(ssl);
			continue ;
		}
		ssl->hash_input = read_file(fd);
		if (ssl->mdc != -1)
			g_hash_f[ssl->mdc](ssl);
		close(fd);
		print_result(ssl, 2);
		free(ssl->hash_input);
	}
}

int					main(int ac, char **av)
{
	t_ssl			*ssl;

	if (ac == 1)
		p_error("usage: ft_ssl command [command opts] [command args]");
	!(ssl = init_ssl()) ? malloc_error("t_ssl") : 0;
	read_input(ac, av, ssl);
	if (ssl->p_stdin == 1)
	{
		if (ssl->op & OP_S)
			s_usage_error(ssl);
		else if (ssl->op & OP_R && ssl->op & OP_P)
			stdin_process(ssl);
		if (!(ssl->op & OP_P))
			stdin_process(ssl);
	}
	else
		file_process(ssl);
	free_ssl(ssl);
	return (0);
}
