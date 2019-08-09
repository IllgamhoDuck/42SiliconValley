/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 00:24:15 by hypark            #+#    #+#             */
/*   Updated: 2019/08/09 13:33:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	int				index;
	unsigned char	*img;

	img = (unsigned char *)fdf->img_address;
	index = (fdf->bits_per_pixel / 8) * x + (fdf->size_line * y);
	if (x > SIDE_W && x < WIN_W && y < WIN_H && y > 0)
	{
		img[index++] = color & 0xFF;
		img[index++] = (color >> 8) & 0xFF;
		img[index] = (color >> 16) & 0xFF;
	}
}

static void			draw_line(t_fdf *fdf, t_pos *s, t_pos *e)
{
	t_bres			b;
	t_pos			*c;

	c = make_pos(s->x, s->y, s->z, s->color);
	b.w = ft_abs(e->x - s->x);
	b.h = ft_abs(e->y - s->y);
	b.sign[0] = s->x < e->x ? 1 : -1;
	b.sign[1] = s->y < e->y ? 1 : -1;
	b.f[0] = 2 * b.w - 2 * b.h;
	while (c->x != e->x || c->y != e->y)
	{
		draw_pixel(fdf, c->x, c->y, pos_color(s, e, c, &b));
		b.f[1] = b.f[0];
		if (b.f[1] + b.h > 0)
		{
			b.f[0] -= 2 * b.h;
			c->x += b.sign[0];
		}
		if (b.f[1] - b.w < 0)
		{
			b.f[0] += 2 * b.w;
			c->y += b.sign[1];
		}
	}
	free_pos(s, e, c);
}

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
			img[i++] = GRAY & 0xFF;
			img[i++] = (GRAY >> 8) & 0xFF;
			img[i++] = (GRAY >> 16) & 0xFF;
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

void				draw(t_fdf *fdf)
{
	int				x;
	int				y;

	draw_background(fdf);
	ft_bzero(fdf->img_address, WIN_W * WIN_H * (fdf->bits_per_pixel / 8));
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(fdf, projection(fdf, position(fdf, x, y)),
						projection(fdf, position(fdf, x + 1, y)));
			if (y != fdf->map->height - 1)
				draw_line(fdf, projection(fdf, position(fdf, x, y)),
						projection(fdf, position(fdf, x, y + 1)));
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_sidebar(fdf);
}

void				draw_2(t_fdf *fdf)
{
	int				x;
	int				y;

	ft_bzero(fdf->img_address, WIN_W * WIN_H * (fdf->bits_per_pixel / 8));
	draw_background(fdf);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(fdf, projection_2(fdf, position(fdf, x, y)),
						projection_2(fdf, position(fdf, x + 1, y)));
			if (y != fdf->map->height - 1)
				draw_line(fdf, projection_2(fdf, position(fdf, x, y)),
						projection_2(fdf, position(fdf, x, y + 1)));
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_sidebar(fdf);
}

/*
**static void			draw_or_not(t_fdf *fdf, int x, int y, int x_or_y)
**{
**	t_pos			*pos_s;
**	t_pos			*pos_e;
**	t_pos			*proj_s;
**	t_pos			*proj_e;
**	t_pos			*proj[2];
**
**	pos_s = position(fdf, x, y);
**	pos_e = position(fdf, x + (x_or_y ? 1 : 0), y + (x_or_y ? 0 : 1));
**	proj_s = projection(fdf, pos_s);
**	proj_e = projection(fdf, pos_e);
**	if (proj_s->z > 0 && proj_e->z > 0)
**	{
**		draw_line(fdf, window_c(fdf, proj_s), window_c(fdf, proj_e));
**		return ;
**	}
**	else if (proj_s->z <= 0 && proj_e->z <= 0)
**		return ;
**	proj[0] = proj_s->z > 0 ? proj_e : proj_s;
**	proj[1] = proj_s->z > 0 ? proj_s : proj_e;
**	linear_equation(proj[0], proj[1]);
**	draw_line(fdf, window_c(fdf, proj[0]), window_c(fdf, proj[1]));
**}
**
**void				draw(t_fdf *fdf)
**{
**	int				x;
**	int				y;
**
**	ft_bzero(fdf->img_address, WIN_W * WIN_H * (fdf->bits_per_pixel / 8));
**	draw_background(fdf);
**	y = -1;
**	while (++y < fdf->map->height)
**	{
**		x = -1;
**		while (++x < fdf->map->width)
**		{
**			if (x != fdf->map->width - 1)
**				draw_or_not(fdf, x, y, 1);
**			if (y != fdf->map->height - 1)
**				draw_or_not(fdf, x, y, 0);
**		}
**	}
**	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
**	print_sidebar(fdf);
**}
*/
