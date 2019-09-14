/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:25:46 by hypark            #+#    #+#             */
/*   Updated: 2019/09/14 01:27:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdint.h>

/*
** Adjacency list
*/

typedef struct			s_adj
{
	uint32_t			n;
	char				*s;
	struct s_node		*data;
	struct s_node		*next;
}						t_adj;

typedef	struct			s_b_tree
{
	char				*room_name;
	uint32_t			x;
	uint32_t			y;
	struct s_b_tree		*right;
	struct s_b_tree		*left;
}						t_b_tree;

typedef struct			s_ant
{
	uint32_t			ant_number;
	uint32_t			room_number;
	uint32_t			link_number;
	t_b_tree			*room;
}						t_ant;

void					read_file(t_ant *ant);

t_b_tree				*find_room(t_b_tree *b_tree, char *room_name);
void					fill_room_info(t_b_tree *b_tree, int16_t x, int16_t y);

t_ant					*init_ant(void);
t_adj					*init_adj(void);
t_b_tree				*init_b_tree(char *name);

void					free_ant(t_ant *ant);
void					free_b_tree(t_b_tree *b_tree);
void					free_strsplit(char **str);

void					ant_error(void);
void					lem_error(char *str);
void					malloc_error(char *str);

#endif
