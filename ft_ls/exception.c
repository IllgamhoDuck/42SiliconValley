/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 02:38:36 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 16:24:24 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** case 1 print out ls -l symbolic as just a file, but if not a -l just do it
** case 2 print out the file names at the first. 
** -> sort the ls to the files and directorys.
** -> make another ls and handle files at FILE LS
** -> == ORIGINAL LS == SPLITED TO == TWO LS == FOLDER LS == FILE LS == 
** -> FILE LS files name memory is at FOLDER LS files
** -> and we will changed the FOLDER LS f_num depending on the count_d_len
** -> the file names at FOLDER LS will be freed at free_ls(file_ls)
** ========================================================================
** -> and case 1 will be treated at here! 
** -> ls -l symbolic is treated as file
** -> ls no -l symbolic is treated as folder
*/

static uint32_t		count_d_len(t_ls *ls)
{
	uint32_t		len;
	uint32_t		i;

	i = 0;
	len = 0;
	while (i < ls->f_num)
	{
		if (ls->file[i]->mode == 'x')
		{
			i++;
			continue ;
		}
		if (ls->file[i]->mode == 'd')
			len++;
		else if (ls->file[i]->mode == 'l' && !(ls->op & OP_L))
			len++;
		i++;
	}
	return (len);
}

static void			move_file_info(t_ls *ls1, t_ls *ls2, uint32_t len)
{
	uint32_t		i;

	i = -1;
	while (++i < len)
		ls2->file[i] = ls1->file[ls1->f_num + i];
	ls2->op = ls1->op;
}

void				print_file_symbol(t_ls *ls)
{
	t_ls			*file_ls;
	uint32_t		len;

	ls->op |= OP_MAIN_LS;
	len = count_d_len(ls);
	file_ls = init_ls();
	file_ls->f_num  = ls->f_num - len;
	if (!(file_ls->file = (t_file **)malloc(sizeof(t_file *) * file_ls->f_num)))
		p_error("Memory allocation failed at file_ls");
	sort_ls(ls);
	ls->f_num = len;
	move_file_info(ls, file_ls, file_ls->f_num);
	print_ls(file_ls);
	ls->op &= ~(OP_MAIN_LS);
	if (ls->f_num > 0 && file_ls->f_num > 0)
	{
		ls->op |= OP_PRINT;
		ft_printf("\n");
	}
	free_ls(file_ls);
}
