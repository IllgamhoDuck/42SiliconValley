/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:14:25 by hypark            #+#    #+#             */
/*   Updated: 2019/08/18 20:59:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void				print_ls(t_ls *ls)
{
	uint32_t		i;

	i = 0;
	// put total number
	ls->op & OP_L ? ft_printf("total %d\n", ls->f_num) : 0;
	while (i < ls->f_num)
	{
		if (ls->op & OP_L)
		{
			ft_printf("%c%s  ", ls->file[i]->mode, ls->file[i]->permission);
			ft_printf("%d  %s ", ls->file[i]->link, ls->file[i]->user);
			ft_printf("%s%7d ", ls->file[i]->group, ls->file[i]->size);
			ft_printf("%s %s ", ls->file[i]->month, ls->file[i]->day);
			ft_printf("%s %s\n", ls->file[i]->time, ls->file[i]->name);
		}
		else
			ft_printf("%s\n", ls->file[i]->name);
	i++;
	}
}
