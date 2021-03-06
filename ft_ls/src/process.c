/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:59:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/23 23:16:23 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void			search_ls(t_ls *ls)
{
	uint32_t		i;

	i = -1;
	while (++i < ls->f_num)
	{
		if (ls->file[i]->mode == 'x')
			continue ;
		if (ft_strcmp(ls->file[i]->name, ".") == 0)
			continue ;
		else if (ft_strcmp(ls->file[i]->name, "..") == 0)
			continue ;
		else if (ls->file[i]->mode == 'd')
		{
			ft_printf("\n");
			process_ls(copy_ls(ls, i), 1);
		}
	}
}

void				process_ls(t_ls *ls, uint8_t print)
{
	if (print)
		ft_printf("%s:\n", ls->current);
	if (!(ls->dir = opendir(ls->current)))
	{
		ft_printf("%2@ls: %s: ", ls->name);
		perror("");
		free_ls(ls);
		return ;
	}
	read_dir(ls);
	fill_info_ls(ls);
	if (ls->file[0] && ls->file[1])
		sort_ls(ls);
	print_ls(ls);
	closedir(ls->dir);
	if (ls->op & OP_R)
		search_ls(ls);
	free_ls(ls);
}
