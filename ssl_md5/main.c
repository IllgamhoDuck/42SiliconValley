/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:56:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 01:29:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "md5.h"
#include "sha256.h"

hash_algorithm g_hash_f[3] = {md5, sha256, NULL};
int32_t g_mdc_hash_size[2] = {4, 8};

static void			string_process(t_ssl *ssl, char *str)
{
	ssl->hash_input = ft_strdup(str);
	if (ssl->mdc != -1)
		g_hash_f[ssl->mdc](ssl);
	print_hash(ssl, 1);
	ssl->op &= ~OP_S;
}

static void			stdin_process(t_ssl *ssl)
{
	ssl->hash_input = read_file(0);
	if (ssl->op & OP_P)
		ft_printf("%s\n", ssl->hash_input);
	if (ssl->mdc != -1)
		g_hash_f[ssl->mdc](ssl);
	print_hash(ssl, 0);
}

static void			file_process(t_ssl *ssl)
{
	int16_t			i;
	int16_t			fd;

	i = -1;
	while (++i < ssl->total)
	{
		if ((fd = open(ssl->files[i], O_RDONLY)) < 0)
		{
			if (ssl->op & OP_S)
				string_process(ssl, ssl->files[i]);
			else
				no_file_dic(ssl->files[i]);
			continue ;
		}
		ssl->op &= ~OP_S;
		ssl->hash_input = read_file(fd);
		if (ssl->mdc != -1)
			g_hash_f[ssl->mdc](ssl);
		close(fd);
		print_hash(ssl, 2);
	}
}

int					main(int ac, char **av)
{
	t_ssl			*ssl;

	if (ac == 1)
		p_error("usage: ft_ssl command [command opts] [command args]");
	!(ssl = init_ssl()) ? malloc_error("t_ssl") : 0;
	read_input(ac, av, ssl);
	if (ssl->mdc != -1)
		ssl->hash_size = g_mdc_hash_size[ssl->mdc];
	if (ssl->p_stdin == 1 || ssl->op & OP_P)
		stdin_process(ssl);
	else
		file_process(ssl);
	free_ssl(ssl);
	return (0);
}
