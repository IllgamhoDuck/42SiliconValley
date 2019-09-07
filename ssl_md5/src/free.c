/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:57:26 by hypark            #+#    #+#             */
/*   Updated: 2019/09/06 21:14:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void				free_reader(t_reader *r)
{
	free(r->buff);
	free(r);
}

void				free_c_list(t_c_list *c_list)
{
	if (c_list)
	{
		if (c_list->next)
			free_c_list(c_list->next);
		free(c_list);
	}
}

int					free_av_ac(t_ssl *ssl, int ac, char **av)
{
	int				i;

	i = -1;
	if (ssl->op & OP_STDIN_CM)
	{
		if (av)
		{
			while (++i < ac)
			{
				if (av[i])
					free(av[i]);
			}
		}
		free(av);
	}
	return (1);
}

void				free_ssl(t_ssl *ssl)
{
	if (ssl)
	{
		if (ssl->files)
			free(ssl->files);
		free(ssl);
	}
}
