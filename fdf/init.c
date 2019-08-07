/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:37:25 by hypark            #+#    #+#             */
/*   Updated: 2019/08/07 12:56:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_reader			*init_reader(int z, int color)
{
	t_reader		*reader;

	if (!(reader = (t_reader *)ft_memalloc(sizeof(t_reader))))
		print_error("Memory allocating fail at t_reader"); 
	reader->z = z;
	reader->color = color;
	reader->next = NULL;
	return (reader);
}

t_map				*init_map(void)
{
	t_map			*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		print_error("Memory allocating fail at t_map"); 
	map->width = 0;
	map->height = 0;
	map->position = NULL;
	map->color = NULL;
	map->z_ratio = 1;
	map->width_c = 0;
	map->height_c = 0;
	map->altitude_c = 0;
	return (map);
}

static t_camera		*init_camera(t_map *map)
{
	t_camera		*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		print_error("Memory allocating fail at t_camera"); 
	camera->x_1 = map->width_c;
	camera->y_1 = -map->height_c;
	camera->z_1 = map->altitude_c;
	camera->zoom = 1;
	camera->pan = 0;
	camera->tilt = 0;
	camera->focus_d = 3;
	camera->offset_x = 0;
	camera->offset_y = 0;
	return (camera);
}

static t_mouse		*init_mouse(void)
{
	t_mouse			*mouse;

	if (!(mouse = ft_memalloc(sizeof(t_mouse))))
		print_error("Memory allocating fail at t_mouse"); 
	mouse->press = 0;
	mouse->just_start = 1;
	mouse->pre_x = 0;
	mouse->pre_y = 0;
	mouse->x = 0;
	mouse->y = 0;
	return (mouse);
}

t_fdf				*init_fdf(t_map *map)
{
	t_fdf			*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		print_error("Memory allocating fail at t_fdf"); 
	if (!(fdf->mlx = mlx_init()))
		print_error("Initializing mlx have failed"); 
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, WIN_TITLE)))
		print_error("Making a new window failed"); 
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H)))
		print_error("Making a new image failed"); 
	if (!(fdf->img_address = mlx_get_data_addr(fdf->img,
					&(fdf->bits_per_pixel),	&(fdf->size_line), &(fdf->endian))))
		print_error("Finding the address of image have failed"); 
	fdf->map = map;
	fdf->camera = init_camera(map);
	fdf->mouse = init_mouse();
	return (fdf);
}
