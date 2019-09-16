/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:17:23 by hypark            #+#    #+#             */
/*   Updated: 2019/09/15 22:41:28 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void				malloc_error(char *str)
{
	ft_printf("%2@Memory Allocation Failed at %s\n", str);
	exit(1);
}

void				lem_error(char *str)
{
	ft_printf("%2@%s\n", str);
	exit(1);
}

void				ant_error(void)
{
	ft_printf("%2@ERROR\n");
	exit(1);
}

void				line_error(char *line)
{
	ft_printf("%2@%s\n", line);
	lem_error("Invalid line has been inputed");
}
