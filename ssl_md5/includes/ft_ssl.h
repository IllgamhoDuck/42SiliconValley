/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:33:48 by hypark            #+#    #+#             */
/*   Updated: 2019/09/06 20:51:24 by hypark           ###   ########.fr       */
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

# define START 0x0000000000000001llu

# define OP_P START
# define OP_Q (START << 1)
# define OP_R (START << 2)
# define OP_S (START << 3)
# define OP_P_NOPRINT (START << 16)
# define OP_ERROR (START << 62)
# define OP_STDIN_CM (START << 63)

# define BUFF_SIZE_SSL 64

# define ROTL32(w,n) ((w << n) | (w >> (32 - n)))
# define ROTR32(w,n) ((w >> n) | (w << (32 - n)))
# define ROTL64(w,n) ((w << n) | (w >> (64 - n)))
# define ROTR64(w,n) ((w >> n) | (w << (64 - n)))

# define SHIFTL(w,n) (w << n)
# define SHIFTR(w,n) (w >> n)

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
	int16_t			i;
	char			*ssl_input;
	uint32_t		hash_output32[16];
	uint64_t		hash_output64[16];
	int32_t			hash_size;
	int32_t			total;
	uint64_t		op;
	int16_t			mdc;
	uint8_t			p_stdin;
}					t_ssl;

typedef void		(*t_mdc_hash_algorithm)(t_ssl *ssl);

extern char *g_mdc_prefix[8];
extern char *g_md_command[8];
extern t_mdc_hash_algorithm g_hash_f[8];
extern int32_t g_mdc_hash_size[7];

void				stdin_ac_av(t_ssl *ssl, int *ac, char ***av);

void				mdc_process(t_ssl *ssl);
void				mdc_stdin_process(t_ssl *ssl);
void				mdc_string_process(t_ssl *ssl, char *str);

void				mdc_read_input(int ac, char **av, t_ssl *ssl);
void				mdc_print_result(t_ssl *ssl, uint8_t p_op);
void				mdc_hash_size(t_ssl *ssl);

char				*read_file_stdin(t_ssl *ssl, int16_t fd);
char				*read_file(int16_t fd);

uint32_t			swap_endian32(uint32_t w);
uint64_t			swap_endian64(uint64_t w);

t_reader			*init_reader(uint16_t fd);
t_c_list			*init_c_list(char c);
t_ssl				*init_ssl(void);

void				free_reader(t_reader *r);
void				free_c_list(t_c_list *c_list);
void				free_ssl(t_ssl *ssl);
int					free_av_ac(t_ssl *ssl, int ac, char **av);

void				invalid_command(t_ssl *ssl, char *command);
void				unknown_option(t_ssl *ssl, char *op);
void				no_file_dic(t_ssl *ssl);
void				malloc_error(char *str);
void				p_error(char *str);
void				p_error_ssl(t_ssl *ssl, char *str);
void				s_usage_error(t_ssl *ssl);

void				print_bits(uint8_t *str, uint32_t len, char *where);
void				write_file(char *file, char *content);

#endif
