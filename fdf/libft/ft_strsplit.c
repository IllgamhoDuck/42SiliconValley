/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:30:42 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 00:42:50 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	char			**l;

	if (!s)
		return (0);
	if (!(l = (char **)malloc(sizeof(char *) * (ft_strct(s, c) + 1))))
		return (NULL);
	l = ft_strsplit_help(&l, &s, c);
	return (l);
}
