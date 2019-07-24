/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:25:21 by hypark            #+#    #+#             */
/*   Updated: 2018/05/23 16:37:05 by hypark           ###   ########.fr       */
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

char		*ft_strcpy(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*src != '\0')
	{
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\n';
	return (temp + 1);
}

char		*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		concat_len;
	char	*concat;
	char	*op;

	i = -1;
	concat_len = 0;
	concat = 0;
	if (argc > 0)
	{
		while (++i < (argc - 1))
			concat_len += ft_strlen(argv[i + 1]) + 1;
		concat = (char *)malloc(sizeof(char) * concat_len);
		op = concat;
		i = -1;
		while (++i < (argc - 1))
			op = ft_strcpy(op, argv[i + 1]);
		concat[concat_len - 1] = '\0';
	}
	return (concat);
}
