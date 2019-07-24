/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:17:44 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/06/03 23:17:45 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_row_len(char *str);
int				*ft_col_arr(char *str, int row);
int				*ft_str_array(char *str, int *row);
int				ft_check_same(int *arr, int size);
char			get_rush0(int columns, int rows, int col, int row);
char			*rush0(int columns, int rows);
char			get_rush1(int columns, int rows, int col, int row);
char			*rush1(int columns, int rows);
char			get_rush2(int columns, int rows, int col, int row);
char			*rush2(int columns, int rows);
char			get_rush3(int columns, int rows, int col, int row);
char			*rush3(int columns, int rows);
char			get_rush4(int columns, int rows, int col, int row);
char			*rush4(int columns, int rows);
int				ft_strcmp(char *s1, char *s2);
void			ft_print(int col, int row, int r, int rush);
void			ft_rush0(char *str, int col, int row, int or);
void			ft_rush1(char *str, int col, int row, int or);
void			ft_rush2(char *str, int col, int row, int or);
void			ft_rush3(char *str, int col, int row, int or);
void			ft_rush4(char *str, int col, int row, int or);
void			ft_row_col(char *str);
char			*increase_n_transfer(char *str, int *size);
char			*input_acquire(void);

#endif