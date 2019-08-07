/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 23:50:58 by hypark            #+#    #+#             */
/*   Updated: 2019/08/07 00:20:14 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				move_camera_angle(int key, t_fdf *fdf)
{
	fdf = 0;
	if (key == UP)
		printf("moving the camera angle up tilt!!\n");
	else if (key == DOWN)
		printf("moving the camera angle down tilt!!\n");
	else if (key == LEFT)
		printf("moving the camera angle left pan!!\n");
	else if (key == RIGHT)
		printf("moving the camera angle right pan!!\n");
}

void				move_camera_position(int key, t_fdf *fdf)
{
	fdf = 0;
	if (key == KEY_W)
		printf("moving the camera position y minus!\n");
	else if (key == KEY_S)
		printf("moving the camera position y plus!\n");
	else if (key == KEY_A)
		printf("moving the camera position x minus!\n");
	else if (key == KEY_D)
		printf("moving the camera position x plus!\n");
	else if (key == KEY_Q)
		printf("moving the camera position z plus!\n");
	else if (key == KEY_E)
		printf("moving the camera position z minus!\n");
}

void				move_camera_pan(int angle, t_fdf *fdf)
{
	fdf = 0;
	angle = 0;
	printf("moving the camera pan! the left right!\n");
}

void				move_camera_tilt(int angle, t_fdf *fdf)
{
	fdf = 0;
	angle = 0;
	printf("moving the camera tilt! the up down!\n");
}

void				camera_zoom(int button, t_fdf *fdf)
{
	fdf = 0;
	if (button == M_S_UP)
		printf("Zooming in!\n");
	else if (button == M_S_DOWN)
		printf("Zooming out!\n");
}
