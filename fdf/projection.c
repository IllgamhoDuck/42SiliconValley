/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 03:03:45 by hypark            #+#    #+#             */
/*   Updated: 2019/08/07 12:57:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			rotation(t_fdf *fdf, int *x, int *y, int *z)
{
	int				p;
	int				t;
	int				x_w;
	int				y_w;
	int				z_w;

	p = fdf->camera->pan;
	t = fdf->camera->tilt;
	x_w = *x;
	y_w = *y;
	z_w = *z;
	*x = (cos(p) * x_w) + (sin(p) * y_w);
	*y = ((-1) * sin(p) * sin(t) * x_w) - (cos(p) * sin(t) * y_w) - \
				((-1) * cos(t) * z_w);
	*z = ((-1) * sin(p) * cos(t) * x_w) + (cos(p) * cos(t) * y_w) + \
			 (sin(t) * z_w);
}

t_pos				*projection(t_fdf *fdf, t_pos *pos)
{
	int				d;

	d = fdf->camera->focus_d;
	pos->z *= fdf->map->z_ratio;
	pos->x = (pos->x * fdf->camera->zoom) - fdf->camera->x_1;
	pos->y = (pos->y * fdf->camera->zoom) - fdf->camera->y_1;
	pos->z = (pos->z * fdf->camera->zoom) - fdf->camera->z_1;
	rotation(fdf, &(pos->x), &(pos->y), &(pos->z));
	pos->x = (d * pos->x) / (pos->z + d);
	pos->y = (d * pos->y) / (pos->z + d);
	pos->z = 1;
	pos->x += ((WIN_W - SIDE_W) / 2) + SIDE_W + fdf->camera->offset_x;
	pos->y += WIN_H / 2 + fdf->camera->offset_y;
	return (pos);
}
