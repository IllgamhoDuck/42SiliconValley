/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:44:43 by hypark            #+#    #+#             */
/*   Updated: 2018/05/24 16:15:46 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_check_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int			ft_count_word(char *str)
{
	int		n_word;

	n_word = 0;
	while (*str != '\0')
	{
		if (ft_check_sep(*str))
			str++;
		else
		{
			n_word += 1;
			str++;
			while (*str != '\0' && !ft_check_sep(*str))
				str++;
		}
	}
	return (n_word);
}

void		ft_fill_word(char *str, char **result, int *i)
{
	int		n_char;
	char	*cp_str;

	n_char = 0;
	cp_str = str;
	while (*str != '\0' && !ft_check_sep(*str))
	{
		n_char++;
		str++;
	}
	result[*i] = (char *)malloc(sizeof(char) * (n_char + 1));
}

void		ft_fill_add(char *str, char **result, int *i, int n_word)
{
	int		j;

	while (*str != '\0' && *i < n_word)
	{
		if (ft_check_sep(*str))
			str++;
		else
		{
			ft_fill_word(str, result, i);
			j = 0;
			while (*str != '\0' && !ft_check_sep(*str))
			{
				result[*i][j] = *str;
				str++;
				j++;
			}
			result[*i][j] = '\0';
			*i += 1;
		}
	}
}

char		**ft_split_whitespaces(char *str)
{
	char	**result;
	char	*cp_str;
	int		n_word;
	int		i;

	i = 0;
	n_word = 0;
	cp_str = str;
	while (*cp_str)
	{
		n_word += 1;
		cp_str++;
	}
	result = (char **)malloc(sizeof(char *) * (n_word + 1));
	n_word = ft_count_word(str);
	ft_fill_add(str, result, &i, n_word);
	result[i] = 0;
	return (result);
}
