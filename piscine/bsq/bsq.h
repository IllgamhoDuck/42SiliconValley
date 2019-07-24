/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:35:02 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 23:08:37 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define STR(x)			(x), (sizeof(x) - 1)
# define MIN(a,b)		((a) < (b) ? (a) : (b))

# define BUF_SIZE		(4096)
# define START_SIZE		(1024)

# define UINT_SIZE		(8 * sizeof(unsigned int))

/*
**# define BUF_SIZE		(10)
**# define START_SIZE		(2)
*/

typedef	unsigned char	t_u8;

typedef struct			s_reader
{
	char			buf[BUF_SIZE];
	unsigned short	length;
	unsigned short	index;
	int				fd;
}						t_reader;

typedef struct			s_map_info
{
	unsigned int	width;
	unsigned int	height;
	t_u8			empty;
	t_u8			obs;
	t_u8			full;
}						t_map_info;

typedef struct			s_bsq
{
	unsigned int	**map_bits;
	t_u8			*squares_initial;
	unsigned int	*squares;
	unsigned int	trailing_square;
	unsigned int	capacity;
	unsigned int	x;
	unsigned int	y;
	unsigned int	sol_x;
	unsigned int	sol_y;
	unsigned int	sol_size;
}						t_bsq;

t_u8					next_input(t_reader *r);
int						append_to_map(t_bsq *bsq, t_map_info *map_info,
							t_u8 c);
int						append_to_map_initial(t_bsq *bsq, t_map_info *map_info,
							t_u8 c);
int						is_header_valid(t_map_info *map_info);
int						read_header(t_reader *reader, t_map_info *map_info);
void					print_solution(t_bsq *bsq, t_map_info *map_info);
void					grow_squares_array(t_bsq *bsq);
void					init(t_reader *reader, t_bsq *bsq, int fd);
void					cleanup(t_bsq *bsq, t_map_info *map_info);
int						process_file(int fd);

void					set_bit(unsigned int *bit_array, unsigned int index);
t_u8					get_bit(unsigned int *bit_array, unsigned int index);

#endif
