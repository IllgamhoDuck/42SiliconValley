/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:12:17 by hypark            #+#    #+#             */
/*   Updated: 2019/08/09 00:35:57 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				draw_mode(t_fdf *fdf)
{
	if (fdf->mode == 0)
		draw(fdf);
	else if (fdf->mode == 1)
		draw_2(fdf);
}

void				change_mode(int key, t_fdf *fdf)
{
	if (key == KEY_1)
		fdf->mode = 0;
	else if (key == KEY_2)
		fdf->mode = 1;
	draw_mode(fdf);
}

void				change_proj(int key, t_fdf *fdf)
{
	fdf->camera->x_1 = fdf->map->width / 2;
	fdf->camera->y_1 = fdf->map->height / 2;
	fdf->camera->z_1 = (fdf->map->z_max - fdf->map->z_min) / 2;
	fdf->camera->pan = 0;
	fdf->camera->tilt = 0;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == KEY_P)
		fdf->iso = 0;
	else if (key == KEY_I)
		fdf->iso = 1;
	draw_mode(fdf);
}

void				iso(int *x, int *y, int z)
{
	int				pre_x;
	int				pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.523599);
	*y = -z + (pre_x + pre_y) * sin(0.523599);
}
