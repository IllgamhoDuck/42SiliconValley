/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:26:50 by hypark            #+#    #+#             */
/*   Updated: 2019/07/26 21:27:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the char number from the index i at the string
** before the \0 or the designated delimiter
*/

int				ft_strcct(char const *s, char c, int i)
{
	size_t		num;

	num = 0;
	while (s[i] != c && s[i])
	{
		i++;
		num++;
	}
	return (num);
}
