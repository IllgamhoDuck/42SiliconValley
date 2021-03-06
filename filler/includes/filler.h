/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:04:26 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 12:33:42 by hypark           ###   ########.fr       */
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

# define NOT_12(x) (x != -1 && x != -2)
# define NOT_123(x) (x != -1 && x != -2 && x != -3)

# define P_X filler->piece_x
# define P_Y filler->piece_y
# define P_I(x,y) (x + P_X * y)
# define P(x,y) filler->piece[P_I(x, y)]

# define MY(i,x,y) filler->map_mine[I(X(i) + x, (Y(i) + y))]
# define ENEMY(i,x,y) filler->map_enemy[I(X(i) + x, (Y(i) + y))]

# define SOLUTION filler->solution

typedef struct		s_filler
{
	uint8_t			player;
	uint16_t		map_x;
	uint16_t		map_y;
	uint8_t			piece_x;
	uint8_t			piece_y;
	int32_t			*map;
	int32_t			*map_original;
	int32_t			*map_mine;
	int32_t			*map_enemy;
	char			*piece;
	int32_t			my_score;
	int32_t			enemy_score;
	int32_t			solution;
}					t_filler;

int					process_file(t_filler *filler);
void				process_map(t_filler *filler);
void				process_solution(t_filler *filler);

int					*copy_map(t_filler *filler, int *copy_map);

void				print_map(t_filler *filler);
void				print_my_map(t_filler *filler);
void				print_enemy_map(t_filler *filler);

void				delete_12_map(t_filler *filler);
void				recover_12_map(t_filler *filler, int *map);

t_filler			*init_filler(void);

void				reset_filler(t_filler *filler);
void				free_str(char **str);
void				free_filler(t_filler *filler);

#endif
