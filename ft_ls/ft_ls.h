/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:37:59 by hypark            #+#    #+#             */
/*   Updated: 2019/08/18 05:01:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdint.h>
#include <dirent.h>
#include <sys/stat.h>

/*
** Options
*/

# define OP_1 1
# define OP_L (1 << 1)
# define OP_R (1 << 2)
# define OP_A (1 << 3)
# define OP_SR (1 << 4)
# define OP_T (1 << 5)

typedef struct			s_file
{
	char				*name;
}						t_file;

typedef struct			s_flist
{
	char				*name;
	struct s_flist		*next;
}						t_flist;

typedef struct			s_ls
{
	uint8_t				op;
	char				*prefix;
	char				*current;
	t_file				**file;
	t_flist				*f_list;
	uint32_t			f_num;
	DIR					*dir;
	uint32_t			depth;
}						t_ls;

void					process_ls(t_ls *ls, uint8_t print);
void					read_dir(t_ls *ls);
void					sort_ls(t_ls *ls);

char					**read_parameter(int ac, char **av, t_ls *ls);

t_ls					*init_ls(void);
t_ls					*copy_ls(t_ls *ls, uint32_t i);
t_flist					*init_list(char *name);

void					free_ls(t_ls *ls);
void					free_list(t_flist *list);

void					illegal_option();
void					no_file_dic(char *file);
void					p_error(char *str);

#endif
