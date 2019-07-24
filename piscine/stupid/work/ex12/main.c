
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_str_is_numeric(char *str);
				
int main()
{
TEST(ft_str_is_numeric(""), 1);
TEST(ft_str_is_numeric("0"), 1);
TEST(ft_str_is_numeric("123456"), 1);
TEST(ft_str_is_numeric("12345asdf"), 0);
TEST(ft_str_is_numeric("asdf1234"), 0);



return 0;
}
