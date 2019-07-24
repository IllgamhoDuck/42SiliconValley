/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 23:42:18 by hypark            #+#    #+#             */
/*   Updated: 2018/06/03 20:10:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "eval_expr.h"

char		*ft_remove_spaces(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*modify;

	i = 0;
	j = 0;
	len = ft_len(str);
	modify = (char*)malloc(sizeof(char) * (len + 1));
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			modify[j] = str[i];
			j++;
		}
		i++;
	}
	modify[j] = '\0';
	return (modify);
}

char		*ft_bra(char **str)
{
	char	*first;
	char	*copy;
	int		len;
	int		num;

	(*str)++;
	num = 0;
	len = 0;
	first = *str;
	while (**str != ')' || num != 0)
	{
		if (**str == '(')
			num++;
		else if (**str == ')' && num > 0)
			num--;
		(*str)++;
		len++;
	}
	copy = (char *)malloc(sizeof(char) * (len + 1));
	ft_copy(copy, first, len);
	return (copy);
}

void		ft_str_list(char *str, t_list *node)
{
	int				class;

	class = 0;
	while (*str)
	{
		class = ft_check_char(str);
		if (class == 1)
			node->next = ft_create_elem(0, ft_atoi(&str));
		else if (class == 2)
			node->next = ft_create_elem(*str, 0);
		else if (class == 3)
			node->next = ft_create_elem(0, eval_expr(ft_bra(&str)));
		else if (class == 4)
		{
			str++;
			if (*(str - 1) == '+')
				node->next = ft_create_elem(0, eval_expr(ft_bra(&str)));
			else if (*(str - 1) == '-')
				node->next = ft_create_elem(0, -1 * eval_expr(ft_bra(&str)));
		}
		node = node->next;
		str++;
	}
}

int			eval_expr(char *str)
{
	int		sum;
	t_list	*node;

	sum = 0;
	node = ft_create_elem('*', 0);
	str = ft_remove_spaces(str);
	ft_str_list(str, node);
	sum = (int)ft_cal_eval(node->next);
	ft_free_memory(node);
	return (sum);
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
