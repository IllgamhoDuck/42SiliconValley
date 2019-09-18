/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:25:46 by hypark            #+#    #+#             */
/*   Updated: 2019/09/18 00:12:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdint.h>

# define INIT_ADJ_LIST (t_adj *)ft_memalloc(sizeof(t_adj) * ant->room_number)

/*
** Adjacency list
*/

typedef struct		s_adj
{
	char			*room_name;
	int32_t			i;
	struct s_adj	*next;
}					t_adj;

typedef	struct		s_b_tree
{
	char			*room_name;
	int32_t			i;
	int32_t			x;
	int32_t			y;
	struct s_b_tree	*right;
	struct s_b_tree	*left;
}					t_b_tree;

typedef struct		s_queue
{
	int32_t 		*path;
	int32_t			len;
	int32_t			current_i;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_ant
{
	int32_t			ant_number;
	int32_t			room_number;
	int32_t			link_number;
	int32_t			path_number;
	t_b_tree		*start_room;
	t_b_tree		*end_room;
	t_b_tree		*room;
	t_adj			*adj_list;
	int32_t			**adj_matrix;
	t_queue			*queue;
}					t_ant;

extern uint32_t g_index;
extern uint32_t g_start;
extern uint32_t g_end;

void				read_file(t_ant *ant);

void				search_path(t_ant *ant);

int32_t				*init_path(int32_t i);
t_queue				*init_queue(int32_t i);
t_queue				*copy_queue(t_queue *q, int32_t i);
void				push_queue(t_ant *ant, t_queue **q, t_queue *c, int32_t i);
void				free_queue(t_queue *queue);

t_b_tree			*find_room(t_b_tree *b_tree, char *room_name);
t_b_tree			*build_ant_room(t_b_tree *b_tree, char *room_name);
void				fill_room_info(t_b_tree *b_tree, int16_t x, int16_t y);

t_adj				*init_adj(char *room_name, uint32_t i);
int32_t				**init_adj_matrix(int32_t len);
void				push_adj(t_adj **start_adj, uint32_t i);
void				free_adj_list(t_ant *ant);
int8_t				is_empty(t_adj *adj);

void				valid_room(t_ant *ant, char **room_info, int16_t i);
void				valid_link(t_ant *ant, char **link_info, int16_t i);
void				valid_input(t_ant *ant);

t_ant				*init_ant(void);
void				init_link(t_ant *ant, t_b_tree *link);
t_b_tree			*init_b_tree(char *name);

void				free_ant(t_ant *ant);
void				free_adj(t_adj *adj);
void				free_b_tree(t_b_tree *b_tree);
void				free_strsplit(char **str);

void				print_ant(t_ant *ant);
void				print_path(t_ant *ant);
void				print_adj_matrix(t_ant *ant);

void				ant_error(void);
void				lem_error(char *str);
void				malloc_error(char *str);
void				line_error(char *line);

#endif
