/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:44:32 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 00:47:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_strtrim_help(char const **s, int *i, int *j)
{
	while ((*s)[*i] == ' ' || (*s)[*i] == '\n' || (*s)[*i] == '\t')
		(*i)++;
	while ((*s)[*j] == ' ' || (*s)[*j] == '\n' || (*s)[*j] == '\t')
		(*j)--;
}
