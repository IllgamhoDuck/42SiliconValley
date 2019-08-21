/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:14:25 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 20:10:03 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "time.h"

/*
** ft_printf(" %#010X", ls->file[i]->minor);
** this function was made tto treat the "autofs_nowait" weird minor number
** do the 0x when it is the max minor number. But not for below 4
** =======================================================================
** crw-rw-rw-  1 root    wheel       32,  47 Aug 18 21:39 autofs_notrigger
** crw-rw-rw-  1 root    wheel       31, 0x000011b7 Aug 18 21:39 autofs_nowait
** crw-------  1 root    wheel       23,   0 Aug 18 21:39 bpf0
*/

static void			print_c_d(t_ls *ls, t_p *p, uint32_t i)
{
	uint8_t			len;

	len = ft_strlen(ls->file[i]->group);
	ft_printf("%s", ls->file[i]->group);
	if (ls->file[i]->mode == 'c' || ls->file[i]->mode == 'b')
	{
		ft_printf("%*d,", p->m_major + 3 - len, ls->file[i]->major);
		if (p->m_minor == n_len(ls->file[i]->minor) &&\
				n_len(ls->file[i]->minor) > 3)
			ft_printf(" %#010x", ls->file[i]->minor);
		else
			ft_printf("%*d", p->m_minor, ls->file[i]->minor);
	}
	else
	{
		ft_printf("%*c ", p->m_major + 3 - len, ' ');
		ft_printf("%*d", p->m_minor, ls->file[i]->size);
	}
}

static void			print_not_c_d(t_ls *ls, t_p *p, uint32_t i)
{
	uint8_t			len;

	len = ft_strlen(ls->file[i]->group);
	ft_printf("%s", ls->file[i]->group);
	ft_printf("%*d", p->m_g + 2 - len, ls->file[i]->size);
}

static void			print_date(t_ls *ls, uint32_t i)
{
	time_t			t;
	double			diff;

	time(&t);
	if (ls->op & OP_U)
	{
		diff = t - ls->file[i]->atime;
		diff = diff / (60 * 60 * 24 * 30);
		ft_printf(" %s %s ", ls->file[i]->amonth, ls->file[i]->aday);
		if (diff >= 6)
			ft_printf(" %s", ls->file[i]->ayear);
		else
			ft_printf("%s", ls->file[i]->aatime);
	}
	else
	{
		diff = t - ls->file[i]->mtime;
		diff = diff / (60 * 60 * 24 * 30);
		ft_printf(" %s %s ", ls->file[i]->mmonth, ls->file[i]->mday);
		if (diff >= 6)
			ft_printf(" %s", ls->file[i]->myear);
		else
			ft_printf("%s", ls->file[i]->mmtime);
	}
}

/*
** Printing is used in 2 way
** 1. printing out ls at the main where ls->prefix is NULL
** 2. priting out normally while processing the file.
** So splited y using ls->prefix == NULL & ls->prefix != NULL
*/

static void			print_filename(t_ls *ls, uint32_t i)
{
	char			*link_buff;
	char			*temp;
	char			*path;

	if (ls->file[i]->mode == 'l')
	{
		if (!(link_buff = (char *)malloc(sizeof(char) * 2048)))
			p_error("Memory allocation failed in link buf");
		ft_bzero(link_buff, 2048);
		ft_printf(" %s -> ", ls->file[i]->name);
		ls->prefix != NULL ? temp = ft_strjoin(ls->prefix, "/") : 0;
		ls->prefix != NULL ? path = ft_strjoin(temp, ls->file[i]->name) : 0;
		ls->prefix == NULL ? path = ls->file[i]->name : 0;
		readlink(path, link_buff, 2048);
		ft_printf("%s\n", link_buff);
		free(link_buff);
		ls->prefix != NULL ? free(temp) : 0;
		ls->prefix != NULL ? free(path) : 0;
	}
	else
		ft_printf(" %s\n", ls->file[i]->name);
}

void				print_ls(t_ls *ls)
{
	uint32_t		i;
	t_p				*p;

	i = -1;
	p = init_print(ls);
	calculate_max(ls->file, p, ls->f_num);
	if (ls->op & OP_L && ls->f_num != 0 && !(ls->op & OP_MAIN_LS))
		ft_printf("total %lld\n", calculate_total(ls->file, ls->f_num));
	while (++i < ls->f_num)
	{
		if (ls->op & OP_L && ls->file[i]->mode != 'x')
		{
			ft_printf("%c%s", ls->file[i]->mode, ls->file[i]->permission);
			ft_printf("%*d ", p->m_l + 2, ls->file[i]->link);
			ft_printf("%-*s", p->m_u + 2, ls->file[i]->user);
			p->is_c_d ? print_c_d(ls, p, i) : print_not_c_d(ls, p, i);
			print_date(ls, i);
			print_filename(ls, i);
		}
		else if (ls->file[i]->mode != 'x')
			ft_printf("%s\n", ls->file[i]->name);
	}
	free(p);
}
