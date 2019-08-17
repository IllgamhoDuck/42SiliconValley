/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:37:59 by hypark            #+#    #+#             */
/*   Updated: 2019/08/17 02:20:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdint.h>

/*
** Options
*/

# define OP_1 1
# define OP_L (1 << 1)
# define OP_R (1 << 2)
# define OP_A (1 << 3)
# define OP_SR (1 << 4)
# define OP_T (1 << 5)

typedef struct		s_ls
{
	uint32_t		op;
	char			**file;
	uint8_t			f_num;
}					t_ls;

void				read_parameter(int ac, char **av, t_ls *ls);

void				illegal_option(t_ls *ls);
void				no_file_dic(char *file);
void				p_error(char *str, t_ls *ls);

#endif
