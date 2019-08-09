/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 03:03:45 by hypark            #+#    #+#             */
/*   Updated: 2019/08/09 02:35:13 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos				*position(t_fdf *fdf, int x, int y)
{
	t_pos			*pos;
	int				index;
	int				color;

	index = x + (y * fdf->map->width);
	if (!(pos = (t_pos *)ft_memalloc(sizeof(t_pos))))
		print_error("Memory allocating fail at t_pos");
	pos->x = x;
	pos->y = y;
	pos->z = fdf->map->position[index];
	color = fdf->map->color[index];
	if (color == -1)
		pos->color = decide_color(fdf, pos->z);
	else if (color >= 0)
		pos->color = color;
	return (pos);
}

static void			rotation(t_fdf *fdf, int *x, int *y, int *z)
{
	int				pre_x;
	int				pre_y;
	double			angle;

	pre_y = *y;
	angle = fdf->camera->alpha;
	*y = pre_y * cos(angle) + *z * sin(angle);
	*z = -pre_y * sin(angle) + *z * cos(angle);
	pre_x = *x;
	angle = fdf->camera->beta;
	*x = pre_x * cos(angle) + *z * sin(angle);
	*z = -pre_x * sin(angle) + *z * cos(angle);
	pre_x = *x;
	pre_y = *y;
	angle = fdf->camera->gamma;
	*x = pre_x * cos(angle) - pre_y * sin(angle);
	*y = pre_x * sin(angle) + pre_y * cos(angle);
}

t_pos				*projection(t_fdf *fdf, t_pos *pos)
{
	pos->x *= 5 * fdf->camera->zoom;
	pos->y *= 5 * fdf->camera->zoom;
	pos->z *= 5 * fdf->camera->zoom / fdf->camera->z_div;
	pos->x -= (5 * fdf->map->width * fdf->camera->zoom) / 2;
	pos->y -= (5 * fdf->map->height * fdf->camera->zoom) / 2;
	rotation(fdf, &pos->x, &pos->y, &pos->z);
	if (fdf->iso == 1)
		iso(&pos->x, &pos->y, pos->z);
	pos->x += (WIN_W - SIDE_W) / 2 + fdf->camera->offset_x + SIDE_W;
	pos->y += WIN_H / 2 + fdf->camera->offset_y;
	return (pos);
}

static void			rotation_2(t_fdf *fdf, int *x, int *y, int *z)
{
	double			p;
	double			t;
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

t_pos				*projection_2(t_fdf *fdf, t_pos *pos)
{
	pos->x -= fdf->camera->x_1;
	pos->y -= fdf->camera->y_1;
	pos->z -= fdf->camera->z_1;
	pos->x *= 5 * fdf->camera->zoom;
	pos->y *= 5 * fdf->camera->zoom;
	pos->z *= 5 * fdf->camera->zoom / fdf->camera->z_div;
	rotation_2(fdf, &(pos->x), &(pos->y), &(pos->z));
	pos->x += (WIN_W - SIDE_W) / 2 + fdf->camera->offset_x + SIDE_W;
	pos->y += WIN_H / 2 + fdf->camera->offset_y;
	return (pos);
}
/*
**t_pos				*window_c(t_fdf *fdf, t_pos *pos)
**{
**	pos->x += (WIN_W - SIDE_W) / 2 + fdf->camera->offset_x + SIDE_W;
**	pos->y += WIN_H / 2 + fdf->camera->offset_y;
**	return (pos);
**}
**
**t_pos				*projection(t_fdf *fdf, t_pos *pos)
**{
**	pos->x -= fdf->camera->x_1;
**	pos->y -= fdf->camera->y_1;
**	pos->z -= fdf->camera->z_1;
**	pos->x *= 10 * fdf->camera->zoom;
**	pos->y *= 10 * fdf->camera->zoom;
**	pos->z *= 10 * fdf->camera->zoom / fdf->camera->z_div;
**	rotation(fdf, &(pos->x), &(pos->y), &(pos->z));
**	return (pos);
**}
**
**void				linear_equation(t_pos *pos_s, t_pos *pos_e)
**{
**	int				a;
**	int				b;
**	int				c;
**	int				x;
**	int				y;
**
**	a = pos_e->x - pos_s->x;
**	b = pos_e->y - pos_s->y;
**	c = pos_e->z - pos_s->z;
**	x = pos_s->x;
**	y = pos_s->y;
**	pos_s->x = x + a * ((3 - pos_s->z) / c);
**	pos_s->y = y + b * ((3 - pos_s->z) / c);
**	pos_s->z = 1;
**}
**
**static void			perspective(t_fdf *fdf, t_pos *pos)
**{
**	int				d;
**	int				u;
**	int				v;
**	int				div;
**
**	div = pos->y - fdf->camera->y_0 == 0 ? 1 : pos->y - fdf->camera->y_1;
**	d = fdf->camera->focus_d;
**	u = pos->x - ((pos->x - fdf->camera->x_0) * (pos->y - d) / div);
**	v = pos->z - ((pos->z - fdf->camera->z_0) * (pos->y - d) / div);
**	pos->x = u;
**	pos->y = v;
**}
*/
