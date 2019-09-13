/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:04:26 by hypark            #+#    #+#             */
/*   Updated: 2019/09/12 13:40:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdint.h>

# define BUFF_SIZE_FILLER 100000

# define MAP_X filler->map_x
# define MAP_Y filler->map_y

# define X(i) (i % MAP_X)
# define Y(i) (i / MAP_X)

# define I(x,y) (x + MAP_X * y)
# define VALID(x,y) (x >= 0 && x < MAP_X && y >= 0 && y < MAP_Y)

# define VALID_OFFSET(i,x,y) VALID(X(i) + x, Y(i) + y)
# define OFFSET(i,x,y) filler->map[I(X(i) + x, (Y(i) + y))]

# define NOT_123(x) (x != -1 && x != -2 && x != -3)

# define P_X filler->piece_x
# define P_Y filler->piece_y
# define P_I(x,y) (x + P_X * y)
# define P(x,y) filler->piece[P_I(x, y)]

# define MY(i,x,y) filler->map_mine[I(X(i) + x, (Y(i) + y))]
# define ENEMY(i,x,y) filler->map_enemy[I(X(i) + x, (Y(i) + y))]

# define SOLUTION filler->solution

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

typedef struct		s_filler
{
	uint8_t			player;
	uint16_t		map_x;
	uint16_t		map_y;
	uint8_t			piece_x;
	uint8_t			piece_y;
	int32_t			*map;
	int32_t			*map_mine;
	int32_t			*map_enemy;
	char			*piece;
	int32_t			my_score;
	int32_t			enemy_score;
	int32_t			solution;
}					t_filler;

int					stdin_filler(char ***line);

int					process_file(t_filler *filler);
void				process_map(t_filler *filler);
void				process_solution(t_filler *filler);

int					*copy_map(t_filler *filler);

void				print_map(t_filler *filler);
void				print_my_map(t_filler *filler);
void				print_enemy_map(t_filler *filler);

t_reader			*init_reader(uint16_t fd);
t_c_list			*init_c_list(char c);
t_filler			*init_filler(void);

void				filler_error(char *str);

void				reset_filler(t_filler *filler);
void				free_str(char **str);
void				free_filler(t_filler *filler);
void				free_reader(t_reader *r);
void				free_c_list(t_c_list *c_list);

#endif
