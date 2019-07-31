/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:36:25 by hypark            #+#    #+#             */
/*   Updated: 2019/07/31 01:04:31 by hypark           ###   ########.fr       */
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
	unsigned short		i;
	unsigned short		len;
	int					fd;
	int					total;
}						t_reader;

typedef	struct			s_input
{
	char				*piece;
	struct s_input		*next;
	struct s_reader		*reader;
}						t_input;

/*
** io.c
*/

t_reader				*init_reader(int fd);
char					get_next_char(t_reader *r);
t_input					*process_file(int fd);

/*
** valid_checker.c
*/

int						valid_char(char c);

/*
** print.c
*/

void					print_error(void);

/*
** make_piece.c
*/

t_input					*init_input(void);
int						fill_input(t_reader *r, t_input *input);
int						fill_repeat(t_reader *r, t_input *input);

/*
** free.c
*/

/*
** str.c
*/
#endif
