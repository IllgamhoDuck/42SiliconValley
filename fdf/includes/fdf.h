/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:08:15 by hypark            #+#    #+#             */
/*   Updated: 2019/08/09 02:47:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fdf_input.h"
# include "fdf_color.h"
# include <math.h>
# include <stdio.h>

# define WIN_TITLE "ILLGAMHO DUCK 3D WORLD"
# define WIN_W 1700
# define WIN_H 1000
# define SIDE_W 500
# define SIDE_H 1000

typedef struct		s_reader
{
	int				z;
	int				color;
	struct s_reader	*next;
}					t_reader;

typedef struct		s_map
{
	int				width;
	int				height;
	int				*position;
	int				*color;
	int				z_ratio;
	int				z_max;
	int				z_min;
}					t_map;

typedef struct		s_camera
{
	int				x_1;
	int				y_1;
	int				z_1;
	double			pan;
	double			tilt;
	double			alpha;
	double			beta;
	double			gamma;
	double			zoom;
	double			z_div;
	int				focus_d;
	int				offset_x;
	int				offset_y;
}					t_camera;

typedef struct		s_mouse
{
	int				press;
	int				just_start;
	int				pre_x;
	int				pre_y;
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				mode;
	int				iso;
	struct s_map	*map;
	struct s_camera	*camera;
	struct s_mouse	*mouse;
}					t_fdf;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pos;

typedef struct		s_bres
{
	int				w;
	int				h;
	int				f[2];
	int				sign[2];
}					t_bres;

void				draw(t_fdf *fdf);
void				draw_2(t_fdf *fdf);
t_pos				*projection(t_fdf *fdf, t_pos *pos);
t_pos				*projection_2(t_fdf *fdf, t_pos *pos);
t_pos				*position(t_fdf *fdf, int x, int y);
void				linear_equation(t_pos *pos, t_pos *pos_e);
t_pos				*window_c(t_fdf *fdf, t_pos *pos);

void				draw_mode(t_fdf *fdf);
void				change_mode(int key, t_fdf *fdf);
void				change_proj(int key, t_fdf *fdf);
void				iso(int *x, int *y, int z);

int					key_press(int key, void *param);
int					mouse_press(int button, int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);
int					x_button(void *param);

void				move_camera_angle(int key, t_fdf *fdf);
void				move_camera_position(int key, t_fdf *fdf);
void				move_camera_pan(double angle, t_fdf *fdf, int i);
void				move_camera_tilt(double angle, t_fdf *fdf);
void				camera_zoom(int button, t_fdf *fdf);

int					decide_color(t_fdf *fdf, int z);
int					calculate_color(int color_1, int color_2, double per);
int					pos_color(t_pos *s, t_pos *e, t_pos *c, t_bres *b);

void				reader_data_to_map(t_map *map, t_reader *reader);
t_reader			*process_file(int fd, t_map *map);

int					atoi_h(char *str);
int					ft_abs(int number);
t_pos				*make_pos(int x, int y, int z, int color);

t_reader			*init_reader(int z, int color);
t_map				*init_map(void);
t_fdf				*init_fdf(t_map *map);

void				free_reader(t_reader *reader);

void				print_error(char *str);
void				print_sidebar(t_fdf *str);

#endif
