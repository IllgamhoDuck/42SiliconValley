/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:40:12 by hypark            #+#    #+#             */
/*   Updated: 2019/08/19 04:17:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static uint8_t		check_valid_file(char *name)
{
	DIR				*dir;

	if (!(dir = opendir(name)))
	{
		no_file_dic(name);
		return (0);
	}
	else
		closedir(dir);
	return (1);
}

static void			store_name_at_ls(t_ls *ls, char **name)
{
	uint8_t			i;
	uint8_t			j;

	if (!(ls->file = (t_file **)malloc(sizeof(t_file *) * (ls->f_num + 1))))
		p_error("Memory allocation failed at t_file *");
	i = -1;
	j = 0;
	while (++i < ls->f_num)
	{
		if (check_valid_file(name[i]))
		{
			if (!(ls->file[j] = (t_file *)malloc(sizeof(t_file))))
				p_error("Memory allocation failed at t_file");
			ls->file[j]->name = name[i];
			j++;
		}
	}
	ls->f_num = j;
	ls->file[ls->f_num] = NULL;
	free(name);
}

int					main(int ac, char **av)
{
	t_ls			*ls;
	uint8_t			i;
	char			**name;

	ls = init_ls();
	name = read_parameter(ac, av, ls);
	store_name_at_ls(ls, name);
	i = 0;
	if (ls->f_num == 1)
		process_ls(copy_ls(ls, 0), 0);
	else if (ls->f_num > 1)
	{
		while (i < ls->f_num)
		{
			process_ls(copy_ls(ls, i), 1);
			i < ls->f_num - 1 ? ft_printf("\n") : 0;
			i++;
		}
	}
	free_ls(ls);
	return (0);
}
