/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:05:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/19 22:53:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static uint8_t			compare_file(t_file *f1, t_file *f2, uint32_t op)
{
	if (op & OP_T && !(op & OP_U))
	{
		if (f1->mtime == f2->mtime)
			return (f1->mtimensec < f2->mtimensec);
		return (f1->mtime < f2->mtime);
	}
	else if (op & OP_T && op & OP_U)
		return (0); // BONUS
	else if (!(op & OP_T) && !(op & OP_U))
		return (ft_strcmp(f1->name, f2->name) > 0);
	return (0);
}

static void				reverse_ls(t_ls *ls)
{
	t_file				*temp;
	uint32_t			i;

	i = 0;
	while (i < ls->f_num - 1 - i)
	{
		temp = ls->file[ls->f_num - 1 - i];
		ls->file[ls->f_num - 1 - i] = ls->file[i];
		ls->file[i] = temp;
		i++;
	}
}

void					sort_ls(t_ls *ls)
{
	t_file				*temp;
	uint8_t				finish;
	uint32_t			i;

	finish = 1;
	while (finish)
	{
		finish = 0;
		i = 0;
		while (i < ls->f_num - 1)
		{
			if (compare_file(ls->file[i], ls->file[i + 1], ls->op))
			{
				temp = ls->file[i + 1];
				ls->file[i + 1] = ls->file[i];
				ls->file[i] = temp;
				finish = 1;
			}
			i++;
		}
	}
	if (ls->op & OP_SR)
		reverse_ls(ls);
}

void					sort_main_ls(t_ls *ls)
{
	t_file				*temp;
	uint8_t				finish;
	uint32_t			i;

	finish = 1;
	while (finish)
	{
		finish = 0;
		i = 0;
		while (i < ls->f_num - 1)
		{
			if (compare_file(ls->file[i], ls->file[i + 1], ls->op))
			{
				temp = ls->file[i + 1];
				ls->file[i + 1] = ls->file[i];
				ls->file[i] = temp;
				finish = 1;
			}
			i++;
		}
	}
	if (ls->op & OP_SR)
		reverse_ls(ls);
}
