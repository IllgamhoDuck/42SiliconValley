
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					char		*ft_strcat(char *dest, char *src);
				
int main()
{
char test[256] = "";
printf("%s\n", ft_strcat(test, "asdf"));
printf("%s\n", ft_strcat(test, ""));
printf("%s\n", ft_strcat(test, "zxcv"));



return 0;
}
