/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:59:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/18 05:03:33 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void			print_ls(t_ls *ls)
{
	uint32_t		i;

	i = 0;
	while (i < ls->f_num)
	{
		if (ls->op & OP_L)
			ft_printf("printing out ls -l information\n");
		else
			ft_printf("%s\n", ls->file[i]->name); 
		i++;
	}
}

void				process_ls(t_ls *ls, uint8_t print)
{
	if (!(ls->dir = opendir(ls->current)))
	{
		no_file_dic(ls->current);
		return ;
	}
	if (print)
		ft_printf("%s:\n", ls->current);
	read_dir(ls);
	ft_printf("the file total number is %d\n", ls->f_num);
	sort_ls(ls);
	print_ls(ls);
	closedir(ls->dir);
}
