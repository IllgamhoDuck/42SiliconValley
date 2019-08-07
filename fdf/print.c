/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:47:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/07 03:02:07 by hypark           ###   ########.fr       */
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

void				print_sidebar(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 25, 25, BLACK, "TESTING");
	mlx_string_put(fdf->mlx, fdf->win, 25, 50, BLACK, "X : ");
	mlx_string_put(fdf->mlx, fdf->win, 75, 50, BLACK,
					ft_itoa(fdf->mouse->x));
	mlx_string_put(fdf->mlx, fdf->win, 125, 50, BLACK, "Y : ");
	mlx_string_put(fdf->mlx, fdf->win, 175, 50, BLACK,
					ft_itoa(fdf->mouse->y));
}
