/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:18:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/03 17:11:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 64

typedef	struct		s_finfo
{
	char			*storage;
	int				fd;
	struct s_finfo	*right;
	struct s_finfo	*left;
}					t_finfo;

int					get_next_line(const int fd, char **line);

#endif
