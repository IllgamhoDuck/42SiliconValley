/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:10:33 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 03:18:57 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

/*
** READ main arguments & file name from dirent
** ==================================================================
** ls -- treats every parameter coming after as a file or directory
** if there is no specifyied one it just simply print out current one.
** ls - ls --- ls -- - is all treated as an error
*/

static uint8_t			is_dot(char *str)
{
	if (ft_strcmp(str, ".") == 0)
		return (1);
	else if (ft_strcmp(str, "..") == 0)
		return (1);
	else if (str[0] == '.')
		return (1);
	return (0);
}

/*
** mode = 'x' is to check invalid file and go over that
*/

static void				copy_list_to_file(t_ls *ls)
{
	t_flist				*current;
	uint32_t			i;
	uint32_t			len;

	if (!(ls->file = (t_file **)malloc(sizeof(t_file *) * (ls->f_num + 1))))
		p_error("Memory allocation failed at t_file *");
	i = 0;
	current = ls->f_list;
	while (i < ls->f_num)
	{
		if (!(ls->file[i] = (t_file *)malloc(sizeof(t_file))))
			p_error("Memory allocation failed at t_file");
		len = ft_strlen(current->name);
		ls->file[i]->name = ft_strsub(current->name, 0, len);
		ls->file[i]->mode = 'x';
		current = current->next;
		i++;
	}
	ls->file[i] = NULL;
}

void					read_dir(t_ls *ls)
{
	struct dirent		*file;
	t_flist				*current;

	current = NULL;
	while ((file = readdir(ls->dir)))
	{
		if (is_dot(file->d_name) && !(ls->op & OP_A))
			continue ;
		if (current == NULL)
		{
			ls->f_list = init_list(file->d_name);
			current = ls->f_list;
		}
		else
		{
			current->next = init_list(file->d_name);
			current = current->next;
		}
		ls->f_num++;
	}
	copy_list_to_file(ls);
	if (ls->f_list)
		free_list(ls->f_list);
}

static void				store_option(char *str, t_ls *ls)
{
	uint8_t				op_n;

	op_n = 0;
	while (*str)
	{
		*str == '-' ? op_n++ : 0;
		op_n == 2 ? illegal_option('-') : 0;
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
		else if (*str == '-')
			;
		else
			illegal_option(*str);
		str++;
	}
}

/*
** ac + 1 because even there is no parameter input
** we should put a ./ path to it. 
** And for sort we need to put a NULL at the end
** So at least we need 2 spaces for minimum
*/

char					**read_parameter(int ac, char **av, t_ls *ls)
{
	uint8_t				i;
	char				**store_name;

	i = 0;
	if (!(store_name = (char **)malloc(sizeof(char *) * ac)))
		p_error("Memory allocation failed at store_name");
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
			while (++i < ac)
				store_name[ls->f_num++] = av[i];
		else if (ft_strcmp(av[i], "-") == 0)
			while (i < ac)
				store_name[ls->f_num++] = av[i++];
		else if (av[i][0] == '-')
			store_option(av[i], ls);
		else
			while (i < ac)
				store_name[ls->f_num++] = av[i++];
	}
	ls->f_num == 0 ? store_name[0] = "." : 0;
	ls->f_num == 0 ? ls->f_num = 1 : 0;
	return (store_name);
}
