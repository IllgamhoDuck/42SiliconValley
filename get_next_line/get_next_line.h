/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:18:31 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 07:20:47 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 64

int				get_next_line(const int fd, char **line);

typedef	struct		s_finfo
{
	char			buf[BUFF_SIZE];
	unsigned short	index;
	unsigned short	length;
	int				fd;
	struct s_finfo	*next;
}					t_finfo;

#endif
