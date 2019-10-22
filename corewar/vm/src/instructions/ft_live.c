#include "vm.h"

void				ft_live(t_cw *cw, t_process *cp)
{
    uint32_t		prog_num;

	// Increase the total amount of live
    cw->n_live_call += 1;

	// copy the live parameter
	// If there was no matching player cut the total live call
	ft_memcpy(prog_num, &cw->memory[cp->pc + 1], 4);
    swap_32(&prog_num);
	if (prog_num == -1)
		cw->winner = 1;
	else if (prog_num == -2)
		cw->winner = 2;
	else if (prog_num == -3)
		cw->winner = 3;
	else if (prog_num == -4)
		cw->winner = 4;
	else
		cw->n_live_call -= 1;

	// may the processor be alive
    cp->live_call = cw->cycle.cycle;
    printf("live called\n");
}
