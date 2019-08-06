/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 00:04:18 by hypark            #+#    #+#             */
/*   Updated: 2019/08/06 03:22:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** int				deal_mouse(int button, int x, int y, void *param)
** {
** 	param = 0;
** 	printf("button clicked is : %d\n", button);
** 	printf("coord x : %d\n", x);
** 	printf("coord y : %d\n", y);
** 	return (0);
** }
*/

int				main(int ac, char **av)
{
/*
** 	void		*mlx_ptr;
** 	void		*win_ptr;
*/
	t_map		*map;
	t_reader	*reader;
	int			i;

	if (ac != 2)
		print_error("usage : ./fdf [one file with fdf format]");
	map = init_map();
	reader = process_file(open(av[1], O_RDONLY), map);
	reader_data_to_map(map, reader);
	i = -1;
	while (++i < map->width * map->height)
		printf("the z : %d color : %d\n", map->position[i], map->color[i]);


/*
** 	mlx_ptr = mlx_init();
** 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
** 	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
** 	mlx_mouse_hook(win_ptr, deal_mouse, (void *)0);
** 	mlx_loop(mlx_ptr);
*/
}
