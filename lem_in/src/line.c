/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 02:00:14 by hypark            #+#    #+#             */
/*   Updated: 2019/09/19 03:06:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void			fill_list(t_ant *ant, char *line)
{
	t_c_list		*current;
	char			c;

	current = ant->c_list;
	current ? current = ant->current : 0;
	while (*line)
	{
		c = *line;
		if (current == NULL)
		{
			current = init_c_list(c);
			ant->c_list = current;
		}
		else
		{
			current->next = init_c_list(c);
			current = current->next;
		}
		ant->c_len++;
		line++;
	}
	current->next = init_c_list('\n');
	ant->c_len++;
	ant->current = current->next;
}

static char			*compress_data(t_c_list *c_list, int32_t len)
{
	char			*result;
	int32_t			i;

	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		malloc_error("compress_data - char *result");
	i = -1;
	while (++i < len)
	{
		result[i] = c_list->c;
		c_list = c_list->next;
	}
	result[i] = '\0';
	return (result);
}

void				store_line(t_ant *ant, char *line)
{
	fill_list(ant, line);
}

void				compress_line(t_ant *ant)
{
	ant->line = compress_data(ant->c_list, ant->c_len);
}

void				free_c_list(t_c_list *c_list)
{
	if (c_list)
	{
		if (c_list->next)
			free_c_list(c_list->next);
		free(c_list);
	}
}
