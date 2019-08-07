/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 00:24:15 by hypark            #+#    #+#             */
/*   Updated: 2019/08/07 03:06:24 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void			draw_pixel(t_fdf *fdf, int x, int y, int color)
//{
//	int				index;
//	unsigned char	*img;
//
//	img = (unsigned_char *)fdf->img_address;
//	index = (fdf->bits_per_pixel / 8) * x + (fdf->size_line * y);
//	if (x > SIDE_W && x < WIN_W && y < WIN_H && y > 0)
//	{
//		img[index++] = color & 0xFF;
//		img[index++] = (color >> 8) & 0xFF;
//		img[index] = (color >> 16) & 0xFF;
//	}
//}

static void			draw_background(t_fdf *fdf)
{
	unsigned char	*img;
	int				i;
	int				p_bytes;

	i = 0;
	img = (unsigned char *)fdf->img_address;
	p_bytes = fdf->bits_per_pixel / 8;
	while (i < WIN_W * WIN_H * p_bytes)
	{
		if ((i % (WIN_W * p_bytes)) < (SIDE_W * p_bytes))
		{
			img[i++] = SOFT_YELLOW & 0xFF;
			img[i++] = (SOFT_YELLOW >> 8) & 0xFF;
			img[i++] = (SOFT_YELLOW >> 16) & 0xFF;
			img[i] = 0;
		}
		else
		{
			img[i++] = BLACK & 0xFF;
			img[i++] = (BLACK >> 8) & 0xFF;
			img[i++] = (BLACK >> 16) & 0xFF;
			img[i] = 0;
		}
		i++;
	}
}

void				draw_line(fdf, t_pos *s, t_pos *e)
{
}

void				draw(t_fdf *fdf)
{
	int				x;
	int				y;

	mlx_clear_window(fdf->mlx, fdf->win);
	ft_bzero(fdf->img_address, WIN_W * WIN_H * (fdf->bits_per_pixel / 8));
	draw_background(fdf);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x != map->width - 1)
				draw_line(fdf, projection(fdf, position(fdf, x, y)),
						projection(fdf, position(fdf, x + 1, y)));
			if (y != map->height - 1)
				draw_line(fdf, projection(fdf, position(fdf, x, y)),
						projection(fdf, position(fdf, x, y + 1)));
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_sidebar(fdf);
}
