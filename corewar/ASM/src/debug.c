/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:20:18 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/16 22:52:56 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void			debug_print_instructions(t_vector *v)
{
	int				i;
	t_instruction	*item;

	i = 0;
	while (i < v->size)
	{
		item = (t_instruction *)vector_get(v, i);
		i++;
	}
}

void			debug_print_labels(t_vector *v)
{
	int			i;
	t_label		*item;

	i = 0;
	while (i < v->size)
	{
		item = (t_label *)vector_get(v, i);
		i++;
	}
}

void			debug_print_darray(char **a)
{
	while (a && *a)
	{
		ft_printf("-> %s\n", *a);
		a++;
	}
}

int				count_arg(char **elem)
{
	int count;

	count = 0;
	while (elem[count])
	{
		if (elem[count][0] == '#')
			return (count);
		++count;
	}
	return (count);
}

t_error			error_arg_check(int type, char *elem)
{
	if (type == REG_CODE && !(ft_isdigit(elem[1])))
		return (ft_strjoin(elem, "\x1b[91m is invalid.\x1b[0m"));
	if (type == DIR_CODE && (!(ft_isdigit(elem[1])) &&
	elem[1] != ':' && elem[1] != '-'))
		return (ft_strjoin(elem, "\x1b[91m is invalid.\x1b[0m"));
	return (NULL);
}
