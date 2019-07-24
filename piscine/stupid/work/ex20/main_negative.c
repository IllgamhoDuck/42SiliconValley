
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					void		ft_putnbr_base(int nbr, char *base);
				
int main()
{
ft_putnbr_base(-15, "0123456789");
ft_putnbr_base(-16, "01");



return 0;
}
