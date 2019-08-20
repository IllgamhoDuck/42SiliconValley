/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:40:12 by hypark            #+#    #+#             */
/*   Updated: 2019/08/19 23:25:56 by hypark           ###   ########.fr       */
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

/*
** the prefix is all different at files! so fill the file one by one
** [a, b, c] - fill the a & move <-
** [b, c, a] - fill the b & move <-
** [c, a, b] - fill the c & move <-
** [a, b, c] - ready to sort!
*/

static void			fill_main_info_ls(t_ls *ls, char *path)
{
	struct stat		file_stat;

	if (lstat(path, &file_stat) < 0)
		p_error("lstat failed while reading the file status");
	ls->file[0]->mode = fill_file_mode(file_stat.st_mode);
	ls->file[0]->permission = fill_permission(file_stat.st_mode);
	ls->file[0]->link = file_stat.st_nlink;
	ls->file[0]->size = file_stat.st_size;
	fill_user_group(ls->file[0], &file_stat);
	fill_date(ls->file[0], &file_stat);
}

static void			process_main_ls(t_ls *ls)
{
	uint32_t		i;
	uint32_t		j;
	t_file			*temp;

	i = -1;
	while (++i < ls->f_num)
	{
		fill_main_info_ls(ls, ls->file[0]->name);
		j = -1;
		while (++j < ls->f_num - 1)
		{
			temp = ls->file[j + 1];
			ls->file[j + 1] = ls->file[j];
			ls->file[j] = temp;
		}
	}
	sort_ls(ls);
}

int					main(int ac, char **av)
{
	t_ls			*ls;
	uint8_t			i;

	ls = init_ls();
	store_name_at_ls(ls, read_parameter(ac, av, ls));
	if (ls->file[0] && ls->file[1])
		process_main_ls(ls);
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
