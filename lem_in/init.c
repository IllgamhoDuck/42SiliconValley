/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:13:02 by hypark            #+#    #+#             */
/*   Updated: 2019/09/18 13:15:32 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_ant				*init_ant(void)
{
	t_ant			*ant;

	if (!(ant = (t_ant *)ft_memalloc(sizeof(t_ant))))
		malloc_error("ant");
	return (ant);
}

void				init_link(t_ant *ant, t_b_tree *link)
{
	t_adj			*adj;

	adj = init_adj(ft_strdup(link->room_name), link->i);
	ft_memcpy(&(ant->adj_list[link->i]), adj, sizeof(t_adj));
	ant->adj_list[link->i].room_name = ft_strdup(adj->room_name);
	free_adj(adj);
}

void				init_path_check(t_ant *ant)
{
	if (!(ant->adj_matrix = init_adj_matrix(ant->room_number)))
		malloc_error("adjacency matrix");
	if (!(ant->complete_list = INIT_INT))
		malloc_error("complete_list");
}
