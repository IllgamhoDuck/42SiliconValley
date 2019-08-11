/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:24:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/11 02:37:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

# define BUFF_SIZE 64

/*
** w_a - width asterisk p_a - precision asterisk
*/

typedef struct		s_print
{
	char			flag[BUFF_SIZE];
	int				flag_total;
	int				width;
	int				w_a;
	int				precision;
	int				p_a;
	char			*length;
	char			format;
	int				color;
	va_list			ap;
}					t_print;

int					ft_printf(const char *str, ...);
void				ft_printf_d(t_print *p_info);

void				init_info(t_print *p_info);
const char			*read_information(const char *s, t_print *p_info);

void				print_error(char *str);
void				print_info(t_print *p_info);

#endif
