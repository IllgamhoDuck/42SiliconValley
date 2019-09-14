/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:13:02 by hypark            #+#    #+#             */
/*   Updated: 2019/09/14 01:04:34 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_ant				*init_ant(void)
{
	t_ant			*ant;

	ant = (t_ant *)ft_memalloc(sizeof(t_ant)) ? 0 : malloc_error("ant");
	return (ant);
}

t_node				*init_node(void)
{
	t_node			*node;

	node = (t_node *)ft_memalloc(sizeof(t_node)) ? 0 : malloc_error("node");
	return (node);
}

t_b_tree			*init_b_tree(char *name)
{
	t_b_tree		*b_tree;

	if (!(b_tree = (t_b_tree *)ft_memalloc(sizeof(t_b_tree))))
		malloc_error("b_tree");
	b_tree->room_name = name;
	b_tree->right = NULL;
	b_tree->left = NULL;
	return (b_tree);
}
