/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:53:52 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 04:47:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

t_p					*init_print(t_ls *ls)
{
	t_p				*print;
	uint32_t		i;

	if (!(print = (t_p *)malloc(sizeof(t_p))))
		p_error("Memory allocation failed at t_print");
	i = 0;
	print->is_c_d = 0;
	while (i < ls->f_num)
	{
		if (ls->file[i]->mode == 'c' || ls->file[i]->mode == 'b')
		{
			print->is_c_d = 1;
			break ;
		}
		i++;
	}
	print->m_l = 0;
	print->m_u = 0;
	print->m_g = 0;
	print->m_major = 0;
	print->m_minor = 0;
	return (print);
}

t_ls				*init_ls(void)
{
	t_ls			*ls;

	if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
		p_error("Memory allocation failed at ls");
	ls->prefix = NULL;
	ls->current = NULL;
	ls->file = NULL;
	ls->op = 0;
	ls->f_list = NULL;
	ls->f_num = 0;
	ls->dir = NULL;
	ls->depth = 0;
	ls->col_len = 0;
	ls->col = 0;
	ls->row = 0;
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
	if (ft_strcmp(copy->prefix, ls->file[i]->name) == 0)
		copy->current = ls->file[i]->name;
	else
		copy->current = copy->prefix;
	copy->name = ls->file[i]->name;
	copy->file = NULL;
	copy->f_list = NULL;
	copy->f_num = 0;
	copy->depth = ls->depth + 1;
	return (copy);
}

t_flist				*init_list(char *name)
{
	t_flist			*list;
	uint16_t		len;

	len = ft_strlen(name);
	if (!(list = (t_flist *)malloc(sizeof(t_flist))))
		p_error("Memory allocation failed at t_list");
	list->name = ft_strsub(name, 0, len);
	list->next = NULL;
	return (list);
}
