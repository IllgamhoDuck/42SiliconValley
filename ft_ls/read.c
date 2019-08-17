/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:10:33 by hypark            #+#    #+#             */
/*   Updated: 2019/08/17 02:21:28 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** ls -- treats every parameter coming after as a file or directory
** if there is no specifyied one it just simply print out current one.
** ls - ls --- ls -- - is all treated as an error
*/

static void				store_option(char *str, t_ls *ls)
{
	uint8_t				op_n;
	
	op_n = 0;
	while (*str)
	{
		*str == '-' ? op_n++ : 0;
		op_n == 2 ? illegal_option(ls) : 0;
		if (*str == '1')
			ls->op |= OP_1;
		else if (*str == 'l')
			ls->op |= OP_L;
		else if (*str == 'R')
			ls->op |= OP_R;
		else if (*str == 'a')
			ls->op |= OP_A;
		else if (*str == 'r')
			ls->op |= OP_SR;
		else if (*str == 't')
			ls->op |= OP_T;
		str++;
	}
}

void					read_parameter(int ac, char **av, t_ls *ls)
{
	uint8_t				i;
	uint8_t				file_num;

	i = 1;
	file_num = 0;
	if (!(ls->file = (char **)malloc(sizeof(char *) * (ac - 1))))
		p_error("Memory allocation failed at ls->file", ls);
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			while (++i < ac)
				ls->file[file_num++] = av[i];
		}
		else if (av[i][0] == '-')
			store_option(av[i], ls);
		else
			ls->file[file_num++] = av[i];
		i++;
	}
	ls->file[file_num] = NULL;
	ls->f_num = file_num;
}
