/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 00:37:59 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 15:36:59 by hypark           ###   ########.fr       */
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
# define OP_U (1 << 6)
# define OP_S (1 << 7)
# define OP_MAIN_LS (1 << 31)

typedef struct			s_flist
{
	char				*name;
	struct s_flist		*next;
}						t_flist;

typedef struct			s_file
{
	char				*name;
	uint32_t			uid;
	char				*user;
	uint32_t			gid;
	char				*group;
	char				mode;
	char				*permission;
	uint32_t			link;
	uint32_t			size;
	uint32_t			major;
	uint32_t			minor;
	uint32_t			block;
	time_t				atime;
	time_t				atimensec;
	time_t				mtime;
	time_t				mtimensec;
	time_t				ctime;
	time_t				ctimensec;
	char				month[4];
	char				day[3];
	char				year[5];
	char				time[6];
}						t_file;

typedef struct			s_ls
{
	char				*name;
	uint32_t			op;
	char				*prefix;
	char				*current;
	t_file				**file;
	t_flist				*f_list;
	DIR					*dir;
	uint32_t			f_num;
	uint32_t			depth;
}						t_ls;

typedef struct			s_p
{
	uint8_t				is_c_d;
	uint32_t			m_l;
	uint32_t			m_u;
	uint32_t			m_g;
	uint32_t			m_major;
	uint32_t			m_minor;
}						t_p;

void					process_ls(t_ls *ls, uint8_t print);
void					fill_info_ls(t_ls *ls);
void					read_dir(t_ls *ls);
void					sort_ls(t_ls *ls);

void					print_file_symbol(t_ls *ls);

char					fill_file_mode(int mode);
char					*fill_permission(int mode);
void					fill_user_group(t_file *file, struct stat *stat);
void					fill_date(t_file *file, struct stat *stat);

void					print_ls(t_ls *ls);
uint8_t					n_len(uint32_t n);
void					calculate_max(t_file **f, t_p *p, uint32_t len);
uint64_t				calculate_total(t_file **f, uint32_t len);

char					**read_parameter(int ac, char **av, t_ls *ls);

t_p						*init_print(t_ls *ls);
t_ls					*init_ls(void);
t_ls					*copy_ls(t_ls *ls, uint32_t i);
t_flist					*init_list(char *name);

void					free_ls(t_ls *ls);
void					free_list(t_flist *list);

void					illegal_option(char op);
void					no_file_dic(char *file);
void					p_error(char *str);

#endif
