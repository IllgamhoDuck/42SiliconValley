/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:33:48 by hypark            #+#    #+#             */
/*   Updated: 2019/08/27 00:53:10 by hypark           ###   ########.fr       */
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
# define OP_R (1 << 2)
# define OP_S (1 << 3)
# define OP_P_NOPRINT (1 << 16)

# define CC_A (1 << 4)
# define CC_D (1 << 5)
# define CC_E (1 << 6)
# define CC_I (1 << 7)
# define CC_O (1 << 8)
# define CC_K (1 << 9)
# define CC_P (1 << 10)
# define CC_S (1 << 11)
# define CC_V (1 << 12)

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

typedef struct		s_cc
{
	char			*cc_input;
	char			*cc_write;
	char			*cc_key;
	char			*cc_salt;
	char			*cc_vector;
}					t_cc;

typedef struct		s_ssl
{
	int32_t			total;
	int16_t			i;
	char			**files;
	char			*ssl_input;
	uint64_t		op;
	int16_t			mdc;
	uint32_t		hash_output32[16];
	uint64_t		hash_output64[16];
	int32_t			hash_size;
	int16_t			cc;
	t_cc			*cc_info;
	uint8_t			p_stdin;
}					t_ssl;

typedef void		(*t_mdc_hash_algorithm)(t_ssl *ssl);
typedef void		(*t_cc_cipher_algorithm)(t_ssl *ssl);

extern char *g_mdc_prefix[8];
extern char *g_md_command[8];
extern t_mdc_hash_algorithm g_hash_f[8];
extern int32_t g_mdc_hash_size[7];

extern char *g_cc_prefix[8];
extern char *g_c_command[8];
extern t_cc_cipher_algorithm g_cipher_f[8];
extern int32_t g_cc_cipher_size[7];

void				mdc_process(t_ssl *ssl);
void				mdc_stdin_process(t_ssl *ssl);
void				mdc_string_process(t_ssl *ssl, char *str);

void				mdc_read_input(int ac, char **av, t_ssl *ssl);
void				mdc_print_result(t_ssl *ssl, uint8_t p_op);
void				mdc_hash_size(t_ssl *ssl);

void				cc_process(t_ssl *ssl);
void				cc_stdin_process(t_ssl *ssl);

void				cc_read_input(int ac, char **av, t_ssl *ssl);
void				cc_print_result(t_ssl *ssl, uint8_t p_op);

char				*read_file(int16_t fd);

uint32_t			swap_endian32(uint32_t w);
uint64_t			swap_endian64(uint64_t w);

t_reader			*init_reader(uint16_t fd);
t_c_list			*init_c_list(char c);
t_ssl				*init_ssl(void);

void				free_reader(t_reader *r);
void				free_c_list(t_c_list *c_list);
void				free_ssl(t_ssl *ssl);

void				invalid_command(char *command);
void				no_file_dic(t_ssl *ssl);
void				malloc_error(char *str);
void				p_error(char *str);

void				mdc_unknown_option(char *op);
void				mdc_s_usage_error(t_ssl *ssl);

void				cc_missing_arg_error(char *op);
void				cc_unknown_option(char *op);
void				cc_usage_error(void);

void				print_bits(uint8_t *str, uint32_t len, char *where);
void				write_file(char *file, char *content);

#endif
