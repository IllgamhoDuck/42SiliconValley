
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					void		ft_putnbr_base(int nbr, char *base);
				
int main()
{
ft_putnbr_base(2147483647, "0123456789abcdef");
ft_putnbr_base(-2147483648, "0123456789abcdef");



return 0;
}
