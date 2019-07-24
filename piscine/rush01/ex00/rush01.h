/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:17:57 by hypark            #+#    #+#             */
/*   Updated: 2018/05/27 20:38:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_print_error(void);
void		ft_print_sudoku(char **sudoku);
void		ft_copy(char **dest, char **copy);
char		**ft_copy_malloc(char **copy);
void		ft_copy_main(char **dest, char **copy);
char		**ft_copy_malloc_main(char **main_arg);
int			ft_check_input(char **argv);
int			ft_check_len(char **argv);

#endif
