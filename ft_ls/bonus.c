/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:27:52 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 04:22:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/ioctl.h>

void				fill_mtime(t_file *file, char *time)
{
	ft_strncpy(file->mmonth, time + 4, 3);
	ft_strncpy(file->mday, time + 8, 2);
	ft_strncpy(file->myear, time + 20, 4);
	ft_strncpy(file->mmtime, time + 11, 5);
	file->mmonth[3] = '\0';
	file->mday[2] = '\0';
	file->myear[4] = '\0';
	file->mmtime[5] = '\0';
}

void				fill_atime(t_file *file, char *time)
{
	ft_strncpy(file->amonth, time + 4, 3);
	ft_strncpy(file->aday, time + 8, 2);
	ft_strncpy(file->ayear, time + 20, 4);
	ft_strncpy(file->aatime, time + 11, 5);
	file->amonth[3] = '\0';
	file->aday[2] = '\0';
	file->ayear[4] = '\0';
	file->aatime[5] = '\0';
}

/*
** Based on the column.
** col_len is 10 and window width size is 55
** Find the max column size and calculate the max fit on one line
** Based on upper example col is 5, and f_num is 28 than row number is 6
** ====================================================================
** Their are special cases when the col_len is bigger than one line
** then the ls->col = i - 1 might crash. So we treat this case special
** whatever their is a file then column number should be at least 1
*/

static void			multi_column_cal(t_ls *ls)
{
	struct ttysize	tty;
	uint16_t		width;
	uint16_t		max_file_len;
	uint32_t		i;

	i = -1;
	max_file_len = 0;
	ioctl(0, TIOCGWINSZ, &tty);
	width = tty.ts_cols;
	while (++i < ls->f_num && ls->file[i]->mode != 'x')
	{
		if (ft_strlen(ls->file[i]->name) > max_file_len)
			max_file_len = ft_strlen(ls->file[i]->name);
	}
	if (max_file_len != 0)
	{
		ls->col_len = max_file_len + 1;
		i = 0;
		while (++i * ls->col_len < width)
			;
		ls->col = (ls->col_len && i == 1) ? i : i - 1;
		ls->row = ls->f_num / ls->col;
		if (ls->f_num % ls->col)
			ls->row++;
	}
}

static void			print_multi_column(t_ls *ls)
{
	uint32_t		i;
	uint32_t		j;
	uint32_t		limit;

	i = -1;
	while (++i < ls->row)
	{
		j = -1;
		while (++j < ls->col)
		{
			limit = ls->row * j + i;
			if (limit < ls->f_num && ls->file[limit]->mode != 'x')
			{
				if (ls->op & OP_G)
					multi_col_color(ls->file[limit], ls->col_len);
				else
					ft_printf("%-*s", ls->col_len, ls->file[limit]->name);
			}
		}
		ft_printf("\n");
	}
}

void				print_single_multi(t_ls *ls)
{
	uint32_t		i;

	i = -1;
	if (ls->op & OP_1)
	{
		while (++i < ls->f_num && ls->file[i]->mode != 'x')
		{
			ls->op & OP_G ? print_color(ls->file[i]) \
				: ft_printf("%s", ls->file[i]->name);
			ft_printf("\n");
		}
	}
	else
	{
		ls->col = 0;
		ls->row = 0;
		ls->col_len = 0;
		multi_column_cal(ls);
		if (ls->col == 0)
			return ;
		print_multi_column(ls);
	}
}
