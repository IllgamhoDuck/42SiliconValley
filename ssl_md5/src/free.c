/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:57:26 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 00:26:48 by hypark           ###   ########.fr       */
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

void				free_ssl(t_ssl *ssl)
{
	if (ssl)
	{
		if (ssl->files)
			free(ssl->files);
		free(ssl);
	}
}