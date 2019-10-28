#include "vm.h"

void			h_rev_bytes(void *ptr, size_t n)
{
	size_t		i;
	size_t		half;
	uint8_t		*tmp;
	uint8_t		swap;

	i = 0;
	half = n / 2;
	tmp = (uint8_t *)ptr;
	while (i < half)
	{
		swap = tmp[i];
		tmp[i] = tmp[n - i - 1];
		tmp[n - i - 1] = swap;
		++i;
	}
}

void			swap_int32(int32_t *x)
{
	uint32_t	temp;

	temp = (uint32_t)*x;
	*x = (int32_t)((temp & 0x0000FFFF) << 16 | (temp & 0xFFFF0000) >> 16);
	*x = (int32_t)((temp & 0x00FF00FF) << 8 | (temp & 0xFF00FF00) >> 8);
}

void			swap_32(uint32_t *x)
{
	*x = (*x & 0x0000FFFF) << 16 | (*x & 0xFFFF0000) >> 16;
	*x = (*x & 0x00FF00FF) << 8 | (*x & 0xFF00FF00) >> 8;
}

void			swap_8(uint8_t *x)
{
	*x = (*x & 0x0000FFFF) << 4 | (*x & 0xFFFF0000) >> 4;
	*x = (*x & 0x00FF00FF) << 2 | (*x & 0xFF00FF00) >> 2;
}

void			dump_memory(t_cw *cw)
{
	if (GUI)
		endwin();
	print_memory(cw);
	exit(1);
}
