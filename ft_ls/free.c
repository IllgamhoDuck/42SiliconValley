/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:33:28 by hypark            #+#    #+#             */
/*   Updated: 2019/08/19 22:15:39 by hypark           ###   ########.fr       */
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

void				free_ls(t_ls *ls)
{
	uint32_t		i;

	if (ls)
	{
		if (ls->prefix && ls->depth > 1)
			free(ls->prefix);
		if (ls->file)
		{
			i = 0;
			while (i < ls->f_num)
				free(ls->file[i++]);
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
