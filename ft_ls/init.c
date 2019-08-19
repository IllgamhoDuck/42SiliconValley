/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:53:52 by hypark            #+#    #+#             */
/*   Updated: 2019/08/18 19:40:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

t_ls				*init_ls(void)
{
	t_ls			*ls;

	if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
		p_error("Memory allocation failed at ls");
	ls->prefix = NULL;
	ls->current = NULL;
	ls->file = NULL;
	ls->op = 0;
	ls->op |= OP_1;
	ls->f_list = NULL;
	ls->f_num = 0;
	ls->dir = NULL;
	ls->depth = 0;
	return (ls);
}

t_ls				*copy_ls(t_ls *ls, uint32_t i)
{
	t_ls			*copy;
	char			*temp;

	if (!(copy = (t_ls *)malloc(sizeof(t_ls))))
		p_error("Memory allocation failed at ls");
	if (ls->prefix == NULL)
		copy->prefix = ls->file[i]->name;
	else
	{
		temp = ft_strjoin(ls->prefix, "/");
		copy->prefix = ft_strjoin(temp, ls->file[i]->name);
		free(temp);
	}
	copy->op = ls->op;
	copy->current = ls->file[i]->name;
	copy->file = NULL;
	copy->f_list = NULL;
	copy->f_num = 0;
	copy->depth = ls->depth + 1;
	return (copy);
}

t_flist				*init_list(char *name)
{
	t_flist			*list;

	if (!(list = (t_flist *)malloc(sizeof(t_flist))))
		p_error("Memory allocation failed at t_list");
	list->name = name;
	list->next = NULL;
	return (list);
}
