/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:24:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/12 13:35:57 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

# define FLS 1
# define FLP (1 << 1)
# define FLM (1 << 2)
# define FLZ (1 << 3)
# define FLH (1 << 4)

/*
** w_a - width asterisk p_a - precision asterisk
** flag[0] = ' '
** flag[1] = '+'
** flag[2] = '-'
** flag[3] = '0'
** flag[4] = '#'
*/

typedef struct		s_print
{
	va_list			ap;
	int				f;
	int				w;
	int				w_a;
	int				p;
	int				p_a;
	char			*length;
	char			format;
	int				total_len;
	char			output[BUFF_SIZE];
	int				print_len;
	int				len;
	int				p_pad;
	int				pad;
	int				neg;
}					t_print;

int					ft_printf(const char *str, ...);
void				ft_printf_d(t_print *p);

int					count_d(uintmax_t n);

void				init_info(t_print *p);
const char			*read_information(const char *s, t_print *p);

void				print_error(char *str);
void				print_sign(t_print *p);
void				print_p(t_print *p);
void				print_pad(t_print *p);
void				print_info(t_print *p);

#endif
