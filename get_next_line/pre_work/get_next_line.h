/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:18:31 by hypark            #+#    #+#             */
/*   Updated: 2019/07/30 03:30:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# define BUFF_SIZE 64

typedef	struct		s_finfo
{
	char			*buf;
	unsigned short	index;
	unsigned short	length;
	int				fd;
	struct s_finfo	*right;
	struct s_finfo	*left;
}					t_finfo;

char				get_next_char(t_finfo *f);
t_finfo				*init(const int fd);
t_finfo				*find_f(t_finfo *b_list, const int fd);
int					fill_text(t_finfo *f, char **line);
int					get_next_line(const int fd, char **line);

#endif
