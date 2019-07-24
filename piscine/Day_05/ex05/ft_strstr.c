/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:00:57 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 13:20:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	return (i);
}

char		*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		match;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (i <= ft_strlen(str))
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			match = 1;
			while (j <= ft_strlen(to_find))
			{
				if (str[i + j] != to_find[j])
					match = 0;
				j++;
			}
			if (match == 1)
				return (str + i);
		}
		i++;
	}
	return ((char *)0);
}
