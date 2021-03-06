/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:13:56 by hypark            #+#    #+#             */
/*   Updated: 2019/09/20 21:36:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
**		if (ant->adj_matrix)
**		{
**			while (++i < ant->room_number)
**				free(ant->adj_matrix[i]);
**			free(ant->adj_matrix);
**		}
*/

void				free_ant(t_ant *ant)
{
	int32_t			i;

	i = -1;
	if (ant)
	{
		if (ant->line)
			free(ant->line);
		if (ant->c_list)
			free_c_list(ant->c_list);
		if (ant->room)
			free_b_tree(ant->room);
		if (ant->adj_list)
			free_adj_list(ant);
		if (ant->path_check)
			free(ant->path_check);
		if (ant->complete_list)
			free(ant->complete_list);
		if (ant->queue)
			free_queue(ant->queue);
		free(ant);
	}
}

void				free_deploy(t_deploy *deploy)
{
	if (deploy)
	{
		if (deploy->room_left)
			free(deploy->room_left);
		if (deploy->spare_room)
			free(deploy->spare_room);
		if (deploy->ant_deploy)
			free(deploy->ant_deploy);
		if (deploy->start_num)
			free(deploy->start_num);
		free(deploy);
	}
}

void				free_adj(t_adj *adj)
{
	if (adj)
	{
		if (adj->next)
			free_adj(adj->next);
		if (adj->room_name)
			free(adj->room_name);
		free(adj);
	}
}

void				free_b_tree(t_b_tree *b_tree)
{
	if (b_tree)
	{
		if (b_tree->left)
			free_b_tree(b_tree->left);
		if (b_tree->right)
			free_b_tree(b_tree->right);
		free(b_tree->room_name);
		free(b_tree);
	}
}

void				free_strsplit(char **str)
{
	int				i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}
