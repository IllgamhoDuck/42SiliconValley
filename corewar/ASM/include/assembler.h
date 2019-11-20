/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:09:37 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/16 22:53:07 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "../../libft/includes/libft.h"
# include "op.h"
# include "vector.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define BOLD			"\x1b[1m"
# define ITALIC			"\x1b[3m"
# define UNDERL			"\x1b[4m"
# define CYAN			"\x1b[36m"
# define RED			"\x1b[91m"
# define GREEN			"\x1b[92m"
# define YELLOW			"\x1b[93m"
# define PURPLE			"\x1b[94m"
# define RESET			"\x1b[0m"

# define WHITE_SPACE	32
# define TAB			9
# define NEWLINE		10

typedef char*			t_error;

typedef struct			s_champ
{
	char				*fname;
	char				*name;
	char				*comment;
	char				*content;
}						t_champ;

/*
** Stores arguments from instructions:
** 	-> label = if not NULL, argument is a reference and should be filled\
**					later on;
** 	-> type = (0, 1, 2) (register, direct, indirect);
** 	-> size = (1, 2, 4) (register, indirect OR direct with thefuck == 1,\
**						direct with thefuck == 0);
**	-> value = compiled value;
*/

typedef struct			s_argument
{
	char				label[LABEL_NAME_LENGTH + 1];
	int					type;
	size_t				size;
	uint32_t			value;

}						t_argument;

typedef struct			s_instruction
{
	int					opcode;
	uint32_t			encoding_byte;
	int					n_args;
	t_argument			args[3];
	size_t				size;
	size_t				offset;
}						t_instruction;

typedef struct			s_label
{
	char				name[LABEL_NAME_LENGTH + 1];
	size_t				offset;
}						t_label;

size_t					g_offset;

t_error					assembler(char *filename);
t_error					feed_references(t_vector *instr, t_vector *labels);
t_error					lexer(t_vector *instructions, t_champ *champ);
t_error					verify_filename(char *filename);
t_error					fill_champ(t_champ *champ, int fd);
t_error					parser(t_champ *champ, char *filename);
t_error					write_file(t_champ *champ, t_vector *instructions);
t_error					get_name(char **dst, int fd);
t_error					get_comment(char **dst, int fd);
t_error					get_content(char **dst, int fd);

t_error					get_label(t_label **new_label, char **elem);
t_error					get_opcode(t_instruction *instruction, char **elem);

void					set_encoding_byte(t_instruction *instruction);
void					set_size(t_instruction *instruction);
t_error					get_args(t_instruction *instruction, char **elem);
t_error					get_instruction(t_instruction **dst, char **elem);

uint32_t				swap_endian(uint32_t num);

void					debug_print_instructions(t_vector *v);
void					debug_print_labels(t_vector *v);
void					debug_print_darray(char **a);
int						count_arg(char **elem);
t_error					error_arg_check(int type, char *elem);

void					free_double(char **dptr);

#endif
