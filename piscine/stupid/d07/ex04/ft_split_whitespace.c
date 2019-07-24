/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:44:43 by hypark            #+#    #+#             */
/*   Updated: 2018/05/23 19:00:05 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int count_char;

	count_char = 0;
	while (*str)
	{
		count_char += 1;
		str++;
	}
	return (count_char);
}

char		**ft_split_whitespace(char *str)
{
	char	*sep;
	char	**result;
	int		n_word;
	int		i;

	sep = str;
	i = 0;
	n_word = 1;
	while (*sep++ != '\0')
	{
		if (*sep == ' ' || *sep == '\t' || *sep == '\n')
			n_word += 1;
	}
	result = (char **)malloc(sizeof(char *) * (n_word + 1));
	while (*str != '\0' && i < n_word)
	{
		if (i == 0)
			result[i++] = str;
		else if (*str == ' ' || *str == '\t' || *str == '\n')
			result[i++] = str + 1;
		str++;
	}
	result[i] = 0;
	return (result);
}
