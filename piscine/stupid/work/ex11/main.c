
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_str_is_alpha(char *str);
				
int main()
{
TEST(ft_str_is_alpha(""), 1);
TEST(ft_str_is_alpha("999"), 0);
TEST(ft_str_is_alpha("QWERTY"), 1);
TEST(ft_str_is_alpha("asdf"), 1);
TEST(ft_str_is_alpha("asdf1234"), 0);



return 0;
}
