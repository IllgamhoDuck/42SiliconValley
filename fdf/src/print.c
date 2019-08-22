/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:47:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 22:59:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <errno.h>

void				print_error(char *str)
{
	if (errno == 0)
	{
		ft_putendl_fd(str, 2);
		return ;
	}
	perror(str);
	exit(1);
}

static void			print_sidebar_4(t_fdf *fdf)
{
	char			*str;

	mlx_string_put(fdf->mlx, fdf->win, 150, 200, DEEPPINK, "PAN : ");
	str = ft_itoa(fdf->camera->pan * (180.0 / M_PI));
	mlx_string_put(fdf->mlx, fdf->win, 225, 200, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 150, 225, DEEPPINK, "TILT : ");
	str = ft_itoa(fdf->camera->tilt * (180.0 / M_PI));
	mlx_string_put(fdf->mlx, fdf->win, 225, 225, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 25, 775, LIGHT_GOLD,
					"USE ARROW KEY AND MOUSE TO ROTATE");
	mlx_string_put(fdf->mlx, fdf->win, 25, 850, LIGHT_GOLD,
					"ILLGAMHO DUCK LAND QUARK!!!");
}

static void			print_sidebar_3(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 25, 300, GOLD, "INSTRUCTIONS");
	mlx_string_put(fdf->mlx, fdf->win, 25, 325, GOLD, "KEY I - ISO");
	mlx_string_put(fdf->mlx, fdf->win, 25, 350, GOLD, "KEY P - PARALLEL");
	mlx_string_put(fdf->mlx, fdf->win, 25, 400, GOLD, "KEY A - UP");
	mlx_string_put(fdf->mlx, fdf->win, 25, 425, GOLD, "KEY S - DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 25, 450, GOLD, "KEY D - RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 25, 475, GOLD, "KEY W - UP");
	mlx_string_put(fdf->mlx, fdf->win, 25, 500, GOLD, "KEY H - HIGH");
	mlx_string_put(fdf->mlx, fdf->win, 25, 525, GOLD, "KEY L - LOW");
	mlx_string_put(fdf->mlx, fdf->win, 25, 575, GOLD, "KEY Q - UNFLATTEN");
	mlx_string_put(fdf->mlx, fdf->win, 25, 600, GOLD, "KEY E - FLATTEN");
	mlx_string_put(fdf->mlx, fdf->win, 25, 650, LIGHT_GOLD, "CHANGE MODE");
	mlx_string_put(fdf->mlx, fdf->win, 25, 675, LIGHT_GOLD, \
					"1 - FIXED CAMERA, AXIS AT THE CENTER OF OBJECT");
	mlx_string_put(fdf->mlx, fdf->win, 25, 700, LIGHT_GOLD, \
					"ALPHA / BETA / GAMMA");
	mlx_string_put(fdf->mlx, fdf->win, 25, 725, LIGHT_GOLD,
					"2 - MOVING CAMERA, NO MODIFY ON AXIS");
	mlx_string_put(fdf->mlx, fdf->win, 25, 750, LIGHT_GOLD,
					"PAN(X - LEFT & RIGHT) / TILT(Y - UP & DOWN)");
	print_sidebar_4(fdf);
}

static void			print_sidebar_2(t_fdf *fdf)
{
	char			*str;

	mlx_string_put(fdf->mlx, fdf->win, 25, 200, DEEPPINK, "ALPHA : ");
	str = ft_itoa(fdf->camera->alpha * (180.0 / M_PI));
	mlx_string_put(fdf->mlx, fdf->win, 100, 200, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 25, 225, DEEPPINK, "BETA : ");
	str = ft_itoa(fdf->camera->beta * (180.0 / M_PI));
	mlx_string_put(fdf->mlx, fdf->win, 100, 225, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 25, 250, DEEPPINK, "GAMMA : ");
	str = ft_itoa(fdf->camera->gamma * (180.0 / M_PI));
	mlx_string_put(fdf->mlx, fdf->win, 100, 250, DEEPPINK, str);
	free(str);
	print_sidebar_3(fdf);
}

void				print_sidebar(t_fdf *fdf)
{
	char			*str;

	mlx_string_put(fdf->mlx, fdf->win, 25, 25, DEEPPINK, "MOUSE");
	mlx_string_put(fdf->mlx, fdf->win, 25, 50, DEEPPINK, "X : ");
	str = ft_itoa(fdf->mouse->x);
	mlx_string_put(fdf->mlx, fdf->win, 75, 50, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 125, 50, DEEPPINK, "Y : ");
	str = ft_itoa(fdf->mouse->y);
	mlx_string_put(fdf->mlx, fdf->win, 175, 50, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 25, 75, DEEPPINK, "CAMERA");
	mlx_string_put(fdf->mlx, fdf->win, 25, 100, DEEPPINK, "X : ");
	str = ft_itoa(fdf->camera->x_1);
	mlx_string_put(fdf->mlx, fdf->win, 75, 100, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 25, 125, DEEPPINK, "Y : ");
	str = ft_itoa(fdf->camera->y_1);
	mlx_string_put(fdf->mlx, fdf->win, 75, 125, DEEPPINK, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 25, 150, DEEPPINK, "Z : ");
	str = ft_itoa(fdf->camera->z_1);
	mlx_string_put(fdf->mlx, fdf->win, 75, 150, DEEPPINK, str);
	free(str);
	print_sidebar_2(fdf);
}
