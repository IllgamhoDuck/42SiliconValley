/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 00:46:28 by hypark            #+#    #+#             */
/*   Updated: 2019/09/11 03:28:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static int			valid_place(t_filler *filler, int i)
{
	int				p_x;
	int				p_y;
	int				num_0;

	num_0 = 0;
	p_y = -1;
	while (++p_y < P_Y)
	{
		p_x = -1;
		while (++p_x < P_X)
		{
			if (P(p_x, p_y) == '*')
			{
				if (NOT_123(MY(i, p_x, p_y)) == 0)
					return (0);
				if (MY(i, p_x, p_y) == 0)
					num_0++;
			}
		}
	}
	if (num_0 == 1)
	{
		return (1);
	}
	else
		return (0);
}

/*
**static int			cal_my_score(t_filler *filler, int i)
**{
**	int				p_x;
**	int				p_y;
**	int				total;
**
**	total = 0;
**	p_y = -1;
**	while (++p_y < P_Y)
**	{
**		p_x = -1;
**		while (++p_x < P_X)
**		{
**			if (P(p_x, p_y) == '*')
**				total += MY(i, p_x, p_y);
**		}
**	}
**	return (total);
**}
**
**	int				my_score;
**	my_score = cal_my_score(filler, I(x, y));
**	if (my_score < filler->my_score)
**	{
**		filler->my_score = my_score;
**		filler->enemy_score = cal_enemy_score(filler, I(x, y));
**		filler->solution = I(x, y);
**	}
**	else if (my_score == filler->my_score)
**	{
**	}
*/

static int			cal_enemy_score(t_filler *filler, int i)
{
	int				p_x;
	int				p_y;
	int				total;

	total = 0;
	p_y = -1;
	while (++p_y < P_Y)
	{
		p_x = -1;
		while (++p_x < P_X)
		{
			if (P(p_x, p_y) == '*')
				total += ENEMY(i, p_x, p_y);
		}
	}
	return (total);
}



static void			compare_solution(t_filler *filler, int x, int y)
{
	int				enemy_score;

		enemy_score = cal_enemy_score(filler, I(x, y));
		if (enemy_score < filler->enemy_score)
		{
			filler->enemy_score = enemy_score;
			filler->solution = I(x, y);
		}
}

void				process_solution(t_filler *filler)
{
	int				x;
	int				y;

	y = -1;
	while (++y < (MAP_Y - P_Y + 1))
	{
		x = -1;
		while (++x < (MAP_X - P_X + 1))
		{
			if (valid_place(filler, I(x, y)))
				compare_solution(filler, x, y);
		}
	}
}
