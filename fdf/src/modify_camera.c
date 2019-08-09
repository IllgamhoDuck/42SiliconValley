/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:24:41 by hypark            #+#    #+#             */
/*   Updated: 2019/08/09 02:26:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				move_camera_angle(int key, t_fdf *fdf)
{
	if (key == UP)
	{
		fdf->camera->alpha += 0.07;
		fdf->camera->tilt += 0.07;
	}
	else if (key == DOWN)
	{
		fdf->camera->alpha -= 0.07;
		fdf->camera->tilt -= 0.07;
	}
	else if (key == LEFT)
	{
		fdf->camera->beta -= 0.07;
		fdf->camera->pan -= 0.07;
	}
	else if (key == RIGHT)
	{
		fdf->camera->beta += 0.07;
		fdf->camera->pan += 0.07;
	}
	draw_mode(fdf);
}

void				move_camera_position(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->camera->y_1 += 1;
	else if (key == KEY_S)
		fdf->camera->y_1 -= 1;
	else if (key == KEY_A)
		fdf->camera->x_1 -= 1;
	else if (key == KEY_D)
		fdf->camera->x_1 += 1;
	else if (key == KEY_H)
		fdf->camera->z_1 += 1;
	else if (key == KEY_L)
		fdf->camera->z_1 -= 1;
	else if (key == KEY_Q)
		fdf->camera->z_div *= 0.9;
	else if (key == KEY_E)
		fdf->camera->z_div /= 0.9;
	draw_mode(fdf);
}

void				move_camera_pan(double angle, t_fdf *fdf, int i)
{
	if (i == 1)
	{
		fdf->camera->beta += angle / 100;
		fdf->camera->pan += angle / 100;
	}
	else
		fdf->camera->gamma += angle / 100;
	draw_mode(fdf);
}

void				move_camera_tilt(double angle, t_fdf *fdf)
{
	fdf->camera->alpha += angle / 100;
	fdf->camera->tilt -= angle / 100;
	draw_mode(fdf);
}

void				camera_zoom(int button, t_fdf *fdf)
{
	if (button == M_S_UP)
		fdf->camera->zoom *= 1.1;
	else if (button == M_S_DOWN)
		fdf->camera->zoom /= 1.1;
	draw_mode(fdf);
}
