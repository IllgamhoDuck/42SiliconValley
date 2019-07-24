/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:35:08 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/06/03 23:35:38 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void			ft_rush0(char *str, int col, int row, int or)
{
	ft_rush1(str, col, row, or);
}

void			ft_rush1(char *str, int col, int row, int or)
{
	ft_rush2(str, col, row, or);
}

void			ft_rush2(char *str, int col, int row, int or)
{
	ft_rush3(str, col, row, or);
}

void			ft_rush3(char *str, int col, int row, int or)
{
	char		*rush;
	int			result;

	rush = rush3(col, row);
	result = ft_strcmp(str, rush);
	ft_print(col, row, result, 3);
	if (result == 0 && or == 1)
		ft_putstr(" || ");
	else if (result == 0 && or == 0)
		or = 1;
	ft_rush4(str, col, row, or);
}

void			ft_rush4(char *str, int col, int row, int or)
{
	//if or == 0 and the result is still 0 than print out error
	if (or == 0 && result != 0)
		ft_putstr("error!");
}
