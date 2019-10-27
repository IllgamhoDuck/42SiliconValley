/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:26:46 by anjansse          #+#    #+#             */
/*   Updated: 2019/10/26 23:10:33 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdint.h>
# include <curses.h>
# include "libft.h"
# include "op.h"

# define FLAG		cw->parsing.flag

# define CYCLE		cw->cycle.cycle
# define DUMP_CYCLE	cw->cycle.dump_cycle
# define KILL_CYCLE cw->cycle.kill_cycle
# define KC_CHECK	cw->cycle.kc_check

# define P_I		 cp->process_number

# define CHAMP(i)	cw->champions[i]

# define WINNER		cw->winner

# define AC			cw->parsing.ac
# define AV			cw->parsing.av

# define OCP		(g_op_tab[cp->op].n_param > 1 &&\
					g_op_tab[cp->op].cbyte == 1)
# define TRUNC		(g_op_tab[cp->op].trunc == 0 &&\
					g_op_tab[cp->op].param[0] == T_DIR)

# define MAX_X		192
# define MAX_Y		64

# define ESC		27
# define SPACE		32

/*
** ----------------------------------------------------------------------------
** Macros used for paser (flags).
**
** @macro {FL_DUMP} - Macro for defining dump flag.
** @macro {FL_GUI} - Graphic User Interface
** @macro {FL_VER0} - Show only essential
** @macro {FL_VER1} - Show lives
** @macro {FL_VER2} - Show cycles
** @macro {FL_VER4} - Show operations (Params are NOT literal ...)
** @macro {FL_VER8} - Show deaths
** @macro {FL_VER16} - Show PC movements (Except for jumps)
** ----------------------------------------------------------------------------
*/

# define FL_DUMP (1 << 0) 
# define FL_GUI (1 << 1)
# define FL_VER0 (1 << 2)
# define FL_VER1 (1 << 3)
# define FL_VER2 (1 << 4)
# define FL_VER4 (1 << 5)
# define FL_VER8 (1 << 6)
# define FL_VER16 (1 << 7)

# define GUI		((cw->parsing.flag) & FL_GUI)
# define DUMP		((cw->parsing.flag) & FL_DUMP)

typedef struct      s_parser
{
	int             flag;
	int				ac;
	char			**av;
}                   t_parser;

typedef struct		s_cycle
{
	int				cycle;
	int				dump_cycle;
	int				kill_cycle;
	int				kc_check;
}					t_cycle;

typedef struct		s_champ
{
	int				fd;
	char			manual_assign;
	uint32_t		prog_number;
	char			*name;
	char			*comment;
	unsigned int	prog_size;
}					t_champ;

typedef struct		s_process
{
	int				process_number;
	int				init_cycle;
	int				carry;
	int				live_call;
	uint8_t			op;
	uint8_t			ocp;
	uint8_t			param_num;
	int32_t			param_value[3];
	uint8_t			param_type[3];
	uint8_t			param_size[3];
	uint16_t		pc;
	uint8_t			next_pc_distance;
	uint32_t		registers[REG_NUMBER + 1];
	t_champ			*id;
	struct s_process *next;
}					t_process;

typedef struct		s_hdr
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_hdr;

typedef struct		s_gui
{
	WINDOW      	*win;
	WINDOW			*win_info;
	uint32_t		speed;
}					t_gui;

typedef struct      s_cw
{
	t_hdr			header;
	t_parser        parsing;
	t_champ			champions[MAX_PLAYERS];
	t_champ			tmp_champ[MAX_PLAYERS];
	t_champ			*winner;
	t_gui			gui;
	int				n_players;
	uint32_t		n_live_call;
	uint32_t		process_index;
	t_process		*process_list;
	uint8_t			memory[MEM_SIZE];
	int8_t			owner[MEM_SIZE];
	t_cycle			cycle;
}                   t_cw;

typedef void		(*t_instr_hdlr)(t_cw *, t_process *);

int8_t				modify_carry(int value);
int16_t				pc_idx_mod(t_process *cp, int16_t offset);

void				process_add(t_cw *cw, t_process *cp);
int8_t				process_ocp(t_cw *cw, t_process *cp, int8_t trunc);

void				instruction_proceed(t_cw *cw, t_process *cp);

void				champ_load(t_cw *cw, char *filename, int champ_num);
void				champ_assign(t_cw *cw);

void				print_memory(t_cw *cw);

t_process			*process_init(t_cw *cw, t_champ *id, uint16_t pc);
void				process_update(t_cw *cw);
void				process_check_live(t_cw *cw);

void				corewar_env(t_cw *cw, int ac, char **av);
void				corewar_parser(t_cw *cw);
void				corewar_run(t_cw *cw);
void				corewar_end(t_cw *cw);

void				gui_init(t_cw *cw);
void				gui_update(t_cw *cw);

void				dump_memory(t_cw *cw);
void    			h_rev_bytes(void *ptr, size_t n);
void				swap_int32(int32_t *x);
void				swap_32(uint32_t *x);
void				swap_8(uint8_t *x);

void				ft_live(t_cw *cw, t_process *cp);
void				ft_ld(t_cw *cw, t_process *cp);
void				ft_st(t_cw *cw, t_process *cp);
void				ft_add(t_cw *cw, t_process *cp);
void				ft_sub(t_cw *cw, t_process *cp);
void				ft_and(t_cw *cw, t_process *cp);
void				ft_or(t_cw *cw, t_process *cp);
void				ft_xor(t_cw *cw, t_process *cp);
void				ft_zjump(t_cw *cw, t_process *cp);
void				ft_ldi(t_cw *cw, t_process *cp);
void				ft_sti(t_cw *cw, t_process *cp);
void				ft_fork(t_cw *cw, t_process *cp);
void				ft_lld(t_cw *cw, t_process *cp);
void				ft_lldi(t_cw *cw, t_process *cp);
void				ft_lfork(t_cw *cw, t_process *cp);
void				ft_aff(t_cw *cw, t_process *cp);

#endif
