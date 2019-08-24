/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:33:48 by hypark            #+#    #+#             */
/*   Updated: 2019/08/24 00:37:39 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** ======================== OPTIONS ==========================
** -p - echo STDIN to STDOUT and append the checksum to STDOUT
** -q - quiet mode
** -r - reverse the format of the output
** -s - print the sum of the given string
*/

# define OP_P 1
# define OP_Q (1 << 1)
# define OF_R (1 << 2)
# define OF_S (1 << 3)

# define BUFF_SIZE_SSL 64

typedef struct		s_reader
{
	char			*buff;
	unsigned short	i;
	short			len;
	int				fd;
}					t_reader;

typedef struct		s_c_list
{
	char			c;
	struct s_c_list	*next;
}					t_c_list;

typedef struct		s_ssl
{
	char			**files;
	char			*str;
	int32_t			total;
	uint64_t		op;
	int16_t			mdc;
	uint8_t			p_stdin;
	char			*s_stdin;
}					t_ssl;

typedef void (*hash_algorithm)(t_ssl *ssl);

extern char *g_md_command[3];
extern hash_algorithm g_hash_f[3];

void				read_input(int ac, char **av, t_ssl *ssl);
char				*read_file(uint16_t fd);

t_reader			*init_reader(uint16_t fd);
t_c_list			*init_c_list(char c);
t_ssl				*init_ssl(void);

void				free_reader(t_reader *r);
void				free_c_list(t_c_list *c_list);
void				free_ssl(t_ssl *ssl);

void				invalid_command(char *command);
void				unknown_option(char *op);
void				no_file_dic(char *file);
void				malloc_error(char *str);
void				p_error(char *str);

#endif
