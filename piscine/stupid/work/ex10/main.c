
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					char		*ft_strcapitalize(char *str);
				
int main()
{
char str[] = "asdf qWeRtY ZXCV 100TIS\n";
printf("%s", ft_strcapitalize(str));
char str2[] = "asdf-qWeRtY ZXCV 100TIS";
printf("%s", ft_strcapitalize(str2));



return 0;
}
