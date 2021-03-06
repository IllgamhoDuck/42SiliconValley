/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:53:59 by hypark            #+#    #+#             */
/*   Updated: 2019/09/16 20:54:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_adj				*init_adj(char *room_name, uint32_t i)
{
	t_adj			*adj;

	if (!(adj = (t_adj *)ft_memalloc(sizeof(t_adj))))
		malloc_error("adj");
	adj->room_name = room_name;
	adj->i = i;
	return (adj);
}

int32_t				**init_adj_matrix(int32_t len)
{
	int32_t			**adj_matrix;
	int32_t			i;

	if (!(adj_matrix = (int32_t **)ft_memalloc(sizeof(int32_t *) * len)))
		malloc_error("adj_matrix");
	i = -1;
	while (++i < len)
		if (!(adj_matrix[i] = (int32_t *)ft_memalloc(sizeof(int32_t) * len)))
			malloc_error("adj_matrix");
	return (adj_matrix);
}

void				push_adj(t_adj **start_adj, uint32_t i)
{
	t_adj			*current;

	current = *start_adj;
	if (current == NULL)
	{
		*start_adj = init_adj(NULL, i);
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = init_adj(NULL, i);
}

void				free_adj_list(t_ant *ant)
{
	int32_t			i;
	t_adj			*current;

	i = -1;
	while (++i < ant->room_number)
	{
		free(ant->adj_list[i].room_name);
		current = ant->adj_list[i].next;
		free_adj(current);
	}
	free(ant->adj_list);
}

int8_t				is_empty(t_adj *adj)
{
	uint8_t			*memory;
	int32_t			size;

	memory = (uint8_t *)adj;
	size = sizeof(t_adj);
	while (size--)
		if (memory[size] != 0)
			return (0);
	return (1);
}
