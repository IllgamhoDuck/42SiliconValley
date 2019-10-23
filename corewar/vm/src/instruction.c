#include "vm.h"
#include "op.h"

static t_instr_hdlr instruction[] = {
	ft_live,
	ft_ld,
	ft_st,
	ft_add,
	ft_sub,
	ft_and,
	ft_or,
	ft_xor,
	ft_zjump,
	ft_ldi,
	ft_sti,
	ft_fork,
	ft_lld,
	ft_lldi,
	ft_lfork,
	ft_aff
};

int16_t			pc_idx_mod(t_process *cp, int16_t offset)
{
	if (offset < 0)
	{
		offset = ((-1) * offset) % IDX_MOD;
		offset *= -1;
	}
	else
		offset %= IDX_MOD;
	offset = cp->pc + offset;
	if (offset < 0)
		return (MEM_SIZE - offset);
	return (offset % MEM_SIZE);
}

/*
** -----------------------------------------------------------
** Store the information based on the op.c
** When storing the information based on ocp
** check this is right or wrong and if not wrong return 0
** -----------------------------------------------------------
*/

static int8_t	instruction_get_info(t_cw *cw, t_process *cp)
{
	int8_t		i;
	int8_t		trunc;
	int8_t		*param_byte;

	trunc = g_op_tab[cp->op].trunc;
	if (OCP)
	{
		if (process_ocp(cw, cp, trunc))
			return (1);
	}
	else
	{
		cp->param_type[0] = T_DIR;
		param_byte = (int8_t *)cp->param_value;
		param_byte += 4 - (trunc ? 2 : 4);
		i = -1;
		while (++i < (trunc ? 2 : 4))
		{
			*param_byte = (int8_t)cw->memory[(cp->pc + 1 + i) % MEM_SIZE];
			param_byte++;
		}
		swap_32((uint32_t *)cp->param_value);
		cp->next_pc_distance += 1 + (trunc ? 2 : 4);
	}
	return (0);
}

void			instruction_proceed(t_cw *cw, t_process *cp)
{
	ft_printf("%s : ", cp->id->name);

	// store the information before doing instruction
	if (instruction_get_info(cw, cp) == 0)
		instruction[cp->op](cw, cp); // do the instruction if valid

	// move the pc if it not a jump
	if (cp->op != 8)
		cp->pc = (cp->pc + cp->next_pc_distance) % MEM_SIZE;

	// initialize the information
	cp->next_pc_distance = 0;
	bzero(cp->param_type, 3);
	bzero(cp->param_size, 3);
	bzero(cp->param_value, 12);

	// initialize to next instruction
	cp->op = cw->memory[cp->pc] - 1;
	cp->init_cycle = CYCLE;
}
