/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:38:43 by hypark            #+#    #+#             */
/*   Updated: 2019/09/14 19:18:53 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

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

void				fill_room_info(t_b_tree *b_tree, int16_t x, int16_t y)
{
	b_tree->i = g_index;
	b_tree->x = x;
	b_tree->y = y;
}

t_b_tree			*find_room(t_b_tree *b_tree, char *room_name)
{
	while (1)
	{
		if (ft_strcmp(b_tree->room_name, room_name) == 0)
			return (b_tree);
		if (ft_strcmp(b_tree->room_name, room_name) < 0)
		{
			if (b_tree->right == NULL)
				return (NULL);
			b_tree = b_tree->right;
		}
		else
		{
			if (b_tree->left == NULL)
				return (NULL);
			b_tree = b_tree->left;
		}
	}
}

t_b_tree			*build_ant_room(t_b_tree *b_tree, char *room_name)
{
	while (1)
	{
		if (ft_strcmp(b_tree->room_name, room_name) == 0)
			return (b_tree);
		if (ft_strcmp(b_tree->room_name, room_name) < 0)
		{
			if (b_tree->right == NULL)
			{
				b_tree->right = init_b_tree(room_name);
				b_tree = b_tree->right;
				return (b_tree);
			}
			b_tree = b_tree->right;
		}
		else
		{
			if (b_tree->left == NULL)
			{
				b_tree->left = init_b_tree(room_name);
				b_tree = b_tree->left;
				return (b_tree);
			}
			b_tree = b_tree->left;
		}
	}
}
