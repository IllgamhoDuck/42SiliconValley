/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:40:12 by hypark            #+#    #+#             */
/*   Updated: 2019/08/18 04:36:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** if there is no option it is treated as a file or directory.
** if it is not a directory it should turn the error message
*/

static void			store_name_at_ls(t_ls *ls, char **name)
{
	uint8_t			i;

	if (!(ls->file = (t_file **)malloc(sizeof(t_file *) * (ls->f_num + 1))))
		p_error("Memory allocation failed at t_file *");
	i = -1;
	while (++i < ls->f_num)
	{
		if (!(ls->file[i] = (t_file *)malloc(sizeof(t_file))))
			p_error("Memory allocation failed at t_file");
		ls->file[i]->name = name[i];
	}
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
			process_ls(copy_ls(ls, i++), 1);
	}
	free_ls(ls);
	return (0);
}
