/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:33:48 by hypark            #+#    #+#             */
/*   Updated: 2019/09/08 17:06:49 by hypark           ###   ########.fr       */
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
# define OP_P_NOPRINT (START << 60)

/*
** CIPHER OPTION
*/

# define CC_A (START << 4)
# define CC_D (START << 5)
# define CC_E (START << 6)
# define CC_I (START << 7)
# define CC_O (START << 8)
# define CC_K (START << 9)
# define CC_P (START << 10)
# define CC_S (START << 11)
# define CC_V (START << 12)
# define CC_BP (START << 13)
# define CC_NOSALT (START << 14)
# define CC_NOPAD (START << 15)
# define CC_SALT_HEADER (START << 16)

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
	char			*cc_password;
	char			*cc_salt;
	char			*cc_iv;
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
	char			*cc_output;
	uint32_t		cc_len;
	uint8_t			p_stdin;
	uint8_t			p_mutual;
	uint32_t		mut_len;
	uint32_t		read_len;
}					t_ssl;

typedef void		(*t_mdc_hash_algorithm)(t_ssl *ssl);
typedef void		(*t_cc_cipher_algorithm)(t_ssl *ssl);

extern char *g_mdc_prefix[8];
extern char *g_md_command[8];
extern t_mdc_hash_algorithm g_hash_f[8];
extern int32_t g_mdc_hash_size[7];

extern char *g_cc_prefix[11];
extern char *g_c_command[11];
extern t_cc_cipher_algorithm g_cipher_f[11];

void				mdc_process(t_ssl *ssl);
void				mdc_stdin_process(t_ssl *ssl);
void				mdc_string_process(t_ssl *ssl, char *str);

void				mdc_read_input(int ac, char **av, t_ssl *ssl);
void				mdc_print_result(t_ssl *ssl, uint8_t p_op);
void				mdc_hash_size(t_ssl *ssl);

void				cc_process(t_ssl *ssl);
void				cc_stdin_process(t_ssl *ssl);

uint64_t			cc_atoi_base(char *str, uint8_t base);
int8_t				cc_is_hex_str(char *str);
char				*cc_pad_zero(char *str, int64_t len);
int64_t				cc_count_valid_char(t_ssl *ssl, uint8_t *str, uint64_t len);
char				*cc_insert_newline(uint8_t *str, int64_t len, int64_t n);

void				cc_read_input(int ac, char **av, t_ssl *ssl);
void				cc_print_result(t_ssl *ssl, uint8_t p_op);

char				*read_file(int16_t fd, t_ssl *ssl);

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
void				write_file(char *f, char *content, uint32_t len);

#endif
