/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:26:22 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 17:45:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void				illegal_option(char op)
{
	ft_printf("%2@ls: illegal option -- %c\n", op);
	ft_printf("%2@usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] ");
	ft_printf("%2@[file ...]\n");
	exit(1);
}

void				no_file_dic(char *file)
{
	ft_printf("%2@ls: %s: No such file or directory\n", file);
}

void				p_error(char *str)
{
	ft_printf("%2@%s\n", str);
	exit(1);
}
