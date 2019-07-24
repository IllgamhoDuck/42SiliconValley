
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					char		*ft_concat_params(int argc, char **argv);
				
int main()
{
char* arr[5] = {"NO", "YES", "ARG2", "ARG3", NULL};
printf("%s", ft_concat_params(4, arr));



return 0;
}
