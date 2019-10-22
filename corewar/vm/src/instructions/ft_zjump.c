#include "vm.h"

void				ft_zjump(t_cw *cw, t_process *cp)
{
    (void)cw;
    (void)cp;
    if (cp->carry == 1)
    {
        // jump
    }
    printf("zjump called\n");
}