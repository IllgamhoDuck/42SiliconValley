/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:59:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/18 20:56:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

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
	fill_info_ls(ls);
	sort_ls(ls);
	print_ls(ls);
	closedir(ls->dir);
	// recurse at here to process_ls!!!
}
