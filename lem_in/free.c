/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:13:56 by hypark            #+#    #+#             */
/*   Updated: 2019/09/14 01:17:38 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void				free_ant(t_ant *ant)
{
	if (ant)
	{
		if (ant->room)
			free_b_tree(room);
		free(ant);
	}
}

void				free_b_tree(t_b_tree *b_tree)
{
	//NOT IMPLEMENTED YET
	b_tree = 0;
}

void				free_strsplit(char **str)
{
	int				i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}
