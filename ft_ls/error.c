/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:26:22 by hypark            #+#    #+#             */
/*   Updated: 2019/08/17 02:19:28 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void				illegal_option(t_ls *ls)
{
	ft_printf("ls: illegal option -- -\n");
	ft_printf("usage: ls [-Ralrt1] [file ...]\n");
	if (ls->file)
		free(ls->file);
	exit(1);
}

void				no_file_dic(char *file)
{
	ft_printf("ls: %s: No such file or directory\n", file);
}

void				p_error(char *str, t_ls *ls)
{
	ft_printf("%s\n", str);
	if (ls->file)
		free(ls->file);
	exit(1);
}
