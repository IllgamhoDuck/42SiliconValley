/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:56:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/24 00:47:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "md5.h"
#include "sha256.h"

hash_algorithm g_hash_f[3] = {md5, sha256, NULL};

static void			hash_process(t_ssl *ssl)
{
	int16_t			i;
	uint16_t		fd;

	i = -1;
	{
		if (ssl->op & OP_P)
			ft_printf("printing out the option -p stdin\n");
		while (++i < ssl->total)
		{
			if (!(fd = open(ssl->files[i], O_RDONLY)))
			{
				no_file_dic(ssl->files[i]);
				continue ;
			}
			ssl->str = read_file(fd);
			if (ssl->mdc != -1)
				g_hash_f[ssl->mdc](ssl);
		}
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
		ft_printf("printing out stdin\n");
	else
		hash_process(ssl);
	free_ssl(ssl);
	return (0);
}
