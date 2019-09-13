/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:44:49 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 12:34:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void				free_str(char **str)
{
	int				i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}

void				free_filler(t_filler *filler)
{
	if (filler)
	{
		if (filler->map)
			free(filler->map);
		if (filler->map_original)
			free(filler->map_original);
		if (filler->map_mine)
			free(filler->map_mine);
		if (filler->map_enemy)
			free(filler->map_enemy);
		if (filler->piece)
			free(filler->piece);
		free(filler);
	}
}

void				reset_filler(t_filler *filler)
{
	if (filler)
	{
		filler->enemy_score = INT_MAX;
		if (filler->map)
			free(filler->map);
		if (filler->map_original)
			free(filler->map_original);
		if (filler->map_mine)
			free(filler->map_mine);
		if (filler->map_enemy)
			free(filler->map_enemy);
		if (filler->piece)
			free(filler->piece);
		filler->map = NULL;
		filler->map_original = NULL;
		filler->map_mine = NULL;
		filler->map_enemy = NULL;
		filler->piece = NULL;
	}
}
