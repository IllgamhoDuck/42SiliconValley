
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_str_is_uppercase(char *str);
				
int main()
{
TEST(ft_str_is_uppercase(""), 1);
TEST(ft_str_is_uppercase("1234"), 0);
TEST(ft_str_is_uppercase("ASDF"), 1);
TEST(ft_str_is_uppercase("ASDf"), 0);
TEST(ft_str_is_uppercase("asdf"), 0);



return 0;
}
