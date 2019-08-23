/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:11:54 by hypark            #+#    #+#             */
/*   Updated: 2019/08/22 21:25:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					decide_color(t_fdf *fdf, int z)
{
	double			z_range;
	double			z_current;
	double			percentage;

	z_range = fdf->map->z_max - fdf->map->z_min;
	z_current = z - fdf->map->z_min;
	if (z_range != 0)
		percentage = z_current / z_range;
	else
		return (LIGHT_GOLD);
	return (calculate_color(LIGHT_GOLD, DEEPPINK, percentage));
}

/*
** Color 2 is the destination color and the color 1 is the starting point
** So percentage 80% means its far from color 1 and closer to color 2
*/

int					calculate_color(int color_1, int color_2, double per)
{
	unsigned char	c1;
	unsigned char	c2;
	int				r;
	int				g;
	int				b;

	c1 = (color_1 >> 16) & 0xFF;
	c2 = (color_2 >> 16) & 0xFF;
	r = (c2 - c1) * per + c1;
	c1 = (color_1 >> 8) & 0xFF;
	c2 = (color_2 >> 8) & 0xFF;
	g = (c2 - c1) * per + c1;
	c1 = color_1 & 0xFF;
	c2 = color_2 & 0xFF;
	b = (c2 - c1) * per + c1;
	return ((r << 16) | (g << 8) | b);
}

int					pos_color(t_pos *s, t_pos *e, t_pos *c, t_bres *b)
{
	double			percentage;
	double			dx_1;
	double			dx_2;
	double			dy_1;
	double			dy_2;

	if (b->w > b->h)
	{
		dx_1 = c->x - s->x;
		dx_2 = e->x - s->x;
		percentage = dx_1 / dx_2;
	}
	else
	{
		dy_1 = c->y - s->y;
		dy_2 = e->y - s->y;
		percentage = dy_1 / dy_2;
	}
	return (calculate_color(c->color, e->color, percentage));
}
