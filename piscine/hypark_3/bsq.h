/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:53:27 by hypark            #+#    #+#             */
/*   Updated: 2018/06/06 12:57:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_max
{
	int				max_r;
	int				max_i;
	int				max_j;
}					t_max;

typedef struct		s_map
{
	int				line;
	char			empty;
	char			obstacle;
	char			full;
}					t_map;

/*
** bsq.c
*/

void				ft_square_finder(int **i_arr, int row, int col, t_map *map);
void				ft_bsq(char *str);

/*
** bsq_solution.c
*/

int					ft_pre_value(int **i_arr, int *r_arr, int i, int j);
void				ft_pre_max(t_max *max, int r, int i, int j);
void				ft_preprocess(int **i_arr, t_max *max, int row, int col);
void				ft_square_max(int **i_arr, t_max *max, int row, int col);
int					**ft_square_sol(int **i_arr, t_max *max);

/*
** bsq_print.c
*/

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_print_char_2d(char **arr, int row, int col);
void				ft_print_int_2d(int **arr, int row, int col);

/*
** bsq_valid.c
*/

int					ft_check_col(int *col_arr, int size);
void				ft_col_arr(char *str, int **col_arr, int row);
void				ft_row_newline(char *str, int *row, int *newline);
int					ft_char_check(char *str, t_map *map);
int					ft_valid_check(char *str, int **col_arr, t_map *map);

/*
** bsq_trans.c
*/

char				**ft_1d_2d(char *str, int row, int col);
int					**ft_char_int(char **c_arr, int row, int col, t_map *map);
char				**ft_int_char(int **i_arr, int row, int col, t_map *map);
int					**ft_int_2d(int row, int col);

/*
** bsq_str.c
*/

int					ft_atoi(char **str);
int					ft_check_map_info(char *str, t_map *map);
char				*ft_delete_map_info(char *str);

/*
** bsq_int.c
*/

int					ft_min(int i, int j, int k);

#endif
