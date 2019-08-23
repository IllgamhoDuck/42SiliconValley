/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:33:28 by hypark            #+#    #+#             */
/*   Updated: 2019/08/22 00:53:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

/*
** Depth means the depth of the tree
** The top node of tree is 1 and 2 ... 3... following
** The first node ls->prefix is not a malloc so should not free it.
*/

static void			free_file(t_ls *ls)
{
	uint32_t		i;

	i = -1;
	while (++i < ls->f_num)
	{
		if (ls->file[i]->name && (ls->depth > 0))
			free(ls->file[i]->name);
		if (ls->file[i]->mode != 'x')
		{
			if (ls->file[i]->user)
				free(ls->file[i]->user);
			if (ls->file[i]->group)
				free(ls->file[i]->group);
			if (ls->file[i]->permission)
				free(ls->file[i]->permission);
		}
		free(ls->file[i]);
	}
}

void				free_ls(t_ls *ls)
{
	if (ls)
	{
		if (ls->prefix && ls->depth > 1)
			free(ls->prefix);
		if (ls->file)
		{
			free_file(ls);
			free(ls->file);
		}
		free(ls);
	}
}

void				free_list(t_flist *list)
{
	if (list->next)
		free_list(list->next);
	free(list->name);
	free(list);
}
