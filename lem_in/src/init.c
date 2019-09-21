/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:13:02 by hypark            #+#    #+#             */
/*   Updated: 2019/09/20 11:30:11 by hypark           ###   ########.fr       */
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

t_deploy			*init_deploy(int32_t path_number)
{
	t_deploy		*deploy;

	if (!(deploy = (t_deploy *)ft_memalloc(sizeof(t_deploy))))
		malloc_error("deploy");
	deploy->room_left = INIT_INT64(path_number);
	deploy->spare_room = INIT_INT64(path_number);
	deploy->ant_deploy = INIT_INT64(path_number);
	deploy->start_num = INIT_INT32(path_number);
	return (deploy);
}

void				init_path_check(t_ant *ant)
{
	if (!(ant->path_check = INIT_INT32(ant->room_number)))
		malloc_error("path_check");
	if (!(ant->complete_list = INIT_INT32(ant->room_number)))
		malloc_error("complete_list");
}

t_c_list			*init_c_list(char c)
{
	t_c_list		*list;

	if (!(list = (t_c_list *)ft_memalloc(sizeof(t_c_list))))
		malloc_error("t_c_list");
	list->c = c;
	list->next = NULL;
	return (list);
}
