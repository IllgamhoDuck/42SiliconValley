/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:36:25 by hypark            #+#    #+#             */
/*   Updated: 2019/08/01 19:49:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 64

typedef struct			s_reader
{
	char				*buff;
	char				*sharp;
	unsigned short		sharp_num;
	unsigned short		dot_num;
	unsigned short		i;
	unsigned short		len;
	int					fd;
	int					total;
}						t_reader;

typedef	struct			s_input
{
	char				piece;
	struct s_input		*next;
	struct s_reader		*reader;
}						t_input;

typedef	struct			s_tetris
{
	char				*pieces;
	unsigned short		m_size;
	char				**piece_info;
	char				*x_info;
	char				*y_info;
	char				*alphabet;
	int					total;
}						t_tetris;

/*
** solution.c
*/

int						find_map_size(int total);
char					**init_piece(char *piece, int x_len, int y_len);
int						search(char **a, char **m, t_tetris *t, int iter_n);
int						find_solution(t_tetris *t, char **solution);

/*
** io.c
*/

t_reader				*init_reader(int fd);
char					get_next_char(t_reader *r);
t_tetris				*compress_input(t_reader *r, t_input *input);
t_tetris				*process_file(int fd);

/*
** fill_info.c
*/

int						fill_alphabet(t_tetris *t);
void					fill_x_len(t_tetris *t);
void					fill_y_len(t_tetris *t);
void					fill_piece_info(t_tetris *t);
int						fill_info(t_tetris *t);

/*
** valid_checker.c
*/

int						valid_char(char c);
int						valid_piece(t_reader *r, t_input *input);
unsigned short			*compare_list(void);
unsigned short			bit_transfer(t_reader *r);

/*
** print.c
*/

void					print_error(void);

/*
** make_piece.c
*/

t_input					*init_input(void);
void					translate_coord(t_reader *r);
int						count_char(t_reader *r, char c, int i);
int						fill_input(t_reader *r, t_input *input);
int						fill_repeat(t_reader *r, t_input *input);

/*
** free.c
*/

void					free_list(t_tetris *t, t_input *input, int iter_num);

#endif
