/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 03:53:02 by hypark            #+#    #+#             */
/*   Updated: 2018/06/03 03:57:05 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_copy(char *copy, char *first, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		copy[i] = first[i];
		i++;
	}
	copy[i] = '\0';
}

int			ft_len(char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		if (*str != ' ')
			len++;
		str++;
	}
	return (len);
}
