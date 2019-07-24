
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					char		*ft_strncat(char *dest, char *src, int nb);
				
int main()
{
char test[256] = "\0zxcvzxcvzxcvxzcvzxcvzxcv";
printf("%s\n", ft_strncat(test, "asdf", 16));
printf("%s\n", ft_strncat(test, "", 16));
printf("%s\n", ft_strncat(test, "qwerty", 0));
printf("%s\n", ft_strncat(test, "asdf", 3));



return 0;
}
