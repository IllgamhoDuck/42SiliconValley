/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:04:43 by hypark            #+#    #+#             */
/*   Updated: 2018/05/25 22:48:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char				*ft_copy_str(char *str, int num_ar)
{
	char			*cp_str;
	int				i;

	i = 0;
	cp_str = (char *)malloc(sizeof(char) * (num_ar + 1));
	while (i < num_ar)
	{
		cp_str[i] = str[i];
		i++;
	}
	cp_str[i] = '\0';
	return (cp_str);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*s_array;
	int				i;
	int				j;

	i = 0;
	s_array = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	if (!s_array)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			j++;
		}
		s_array[i].size_param = j;
		s_array[i].str = av[i];
		s_array[i].copy = ft_copy_str(av[i], j);
		s_array[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	s_array[i].str = 0;
	return (s_array);
}
