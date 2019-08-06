/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:08:15 by hypark            #+#    #+#             */
/*   Updated: 2019/08/06 03:16:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include "fdf_input.h"
# include <math.h>
# include <stdio.h>

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
}					t_map;

void				reader_data_to_map(t_map *map, t_reader *reader);
t_reader			*process_file(int fd, t_map *map);

int					atoi_h(char *str);

t_map				*init_map(void);
t_reader			*init_reader(int z, int color);

void				free_reader(t_reader *reader);

void				print_error(char *str);

#endif
