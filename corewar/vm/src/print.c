#include "vm.h"

void	h_puthex(unsigned char c)
{
    static char    *base = "0123456789abcdef";

	printf("%c", base[c / 16]);
	printf("%c", base[c % 16]);
}

void		print_memory(t_cw *cw)
{
	int                 i;
	unsigned            siz;

	i = 0;
	siz = (unsigned)sqrt(MEM_SIZE);
	while (i < MEM_SIZE)
	{
		if (i % siz == 0)
		{
			if (i)
				printf("\n");
			if (i == 0)
				printf("0x0000 : ");
			else
				printf("%#06x : ", i);
		}
		h_puthex(cw->memory[i]);
		printf(" ");
		i++;
	}
	printf("\n");
}
