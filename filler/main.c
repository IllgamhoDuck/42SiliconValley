/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:30:09 by hypark            #+#    #+#             */
/*   Updated: 2019/09/11 04:19:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void			fill_filler(t_filler *filler)
{
	filler->enemy_score = INT_MAX;
	if (filler->map)
			free(filler->map);
	if (filler->map_mine)
		free(filler->map_mine);
	if (filler->map_enemy)
		free(filler->map_enemy);
	if (filler->piece)
		free(filler->piece);
}

int					main(void)
{
	t_filler		*filler;
	int				solution;

	while (1)
	{
		filler = init_filler();
		if (process_file(filler) == 0)
		{
			free_filler(filler);
			return (1);
		}
		process_map(filler);
		process_solution(filler);
		solution = filler->solution;
		fill_filler(filler);
		if (solution != INT_MAX)
			ft_printf("%d %d\n", X(solution), Y(solution));
	}
	return (0);
}
