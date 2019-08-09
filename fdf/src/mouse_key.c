/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:31:10 by hypark            #+#    #+#             */
/*   Updated: 2019/08/09 02:27:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				key_press(int key, void *param)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_camera_angle(key, fdf);
	else if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W || \
			key == KEY_Q || key == KEY_E || key == KEY_H || key == KEY_L)
		move_camera_position(key, fdf);
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_1 || key == KEY_2)
		change_mode(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_proj(key, fdf);
	return (0);
}

int				mouse_press(int button, int x, int y, void *param)
{
	t_fdf		*fdf;

	x = 0;
	y = 0;
	fdf = (t_fdf *)param;
	if (button == M_LEFT)
		fdf->mouse->press = 1;
	else if (button == M_RIGHT)
		fdf->mouse->press = 2;
	else if (button == M_S_UP || button == M_S_DOWN)
		camera_zoom(button, fdf);
	return (0);
}

int				mouse_release(int button, int x, int y, void *param)
{
	t_fdf		*fdf;

	x = 0;
	y = 0;
	button = 0;
	fdf = (t_fdf *)param;
	fdf->mouse->press = 0;
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	if (fdf->mouse->just_start)
	{
		fdf->mouse->pre_x = x;
		fdf->mouse->pre_y = y;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
		fdf->mouse->just_start = 0;
	}
	fdf->mouse->pre_x = fdf->mouse->x;
	fdf->mouse->pre_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->press == 1)
	{
		move_camera_pan(fdf->mouse->x - fdf->mouse->pre_x, fdf, 1);
		move_camera_tilt(fdf->mouse->y - fdf->mouse->pre_y, fdf);
	}
	if (fdf->mouse->press == 2)
		move_camera_pan(fdf->mouse->x - fdf->mouse->pre_x, fdf, 2);
	draw_mode(fdf);
	return (0);
}

int				x_button(void *param)
{
	param = 0;
	exit(0);
}
