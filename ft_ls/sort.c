/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:05:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 16:16:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** The OP_MAIN_LS_SORT is used for to sort the ls that is used at very first
** The files and directorys are all mixed up so it has to be sorted special.
** symbolic files treated as a file when -l options is ON
** But treated as a folder when -l option is OFF
*/

static uint8_t			compare_file(t_file *f1, t_file *f2, uint32_t op)
{
	if (op & OP_MAIN_LS)
	{
		if (f1->mode != 'd' && f2->mode == 'd' && op & OP_L)
			return (1);
		if ((f1->mode != 'd' && f1->mode != 'l') && \
			(f2->mode == 'd' || f2->mode == 'l') && !(op & OP_L))
			return (1);
	}
	else if (op & OP_T && !(op & OP_U))
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
	if (ls->op & OP_SR && !(ls->op & OP_MAIN_LS))
		reverse_ls(ls);
}
