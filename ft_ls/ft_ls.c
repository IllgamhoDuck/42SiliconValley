/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:40:12 by hypark            #+#    #+#             */
/*   Updated: 2019/08/17 02:26:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <dirent.h>

/*
** if there is no option it is treated as a file or directory.
** if it is not a directory it should turn the error message
*/

int					main(int ac, char **av)
{
	t_ls			ls;
	int				i;
	
	ls.file = NULL;
	ls.op = 0;
	ls.op |= OP_1;
	if (ac == 1)
		ft_printf("file is %d\n", ac);
	if (ac > 1)
		read_parameter(ac, av, &ls);
	i = 0;
	while (i < ls.f_num)
		ft_printf("%s\n", ls.file[i++]);
	ft_printf("the option is 1 is %d\n", ls.op & OP_1);
	ft_printf("the option is l is %d\n", ls.op & OP_L);
	ft_printf("the option is R is %d\n", ls.op & OP_R);
	ft_printf("the option is a is %d\n", ls.op & OP_A);
	ft_printf("the option is r is %d\n", ls.op & OP_SR);
	ft_printf("the option is t is %d\n", ls.op & OP_T);
	return (0);
}
