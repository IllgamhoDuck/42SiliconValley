/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 00:04:18 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 22:49:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** endian is 1 - small endian BGR0
** key_press 2
** mouse_press 4
** mouse_release 5
** mouse_move 6
** x_button 17 - the close button (X)
*/

static void		mouse_key(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->win, 17, 0, x_button, fdf);
}

int				main(int ac, char **av)
{
	t_map		*map;
	t_reader	*reader;
	t_fdf		*fdf;

	if (ac != 2)
		print_error("usage : ./fdf [one file with fdf format]");
	map = init_map();
	reader = process_file(open(av[1], O_RDONLY), map);
	reader_data_to_map(map, reader);
	fdf = init_fdf(map);
	mouse_key(fdf);
	draw_mode(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
