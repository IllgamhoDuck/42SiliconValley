
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_str_is_lowercase(char *str);
				
int main()
{
TEST(ft_str_is_lowercase(""), 1);
TEST(ft_str_is_lowercase("1234"), 0);
TEST(ft_str_is_lowercase("ASDF"), 0);
TEST(ft_str_is_lowercase("asdF"), 0);
TEST(ft_str_is_lowercase("asdf"), 1);



return 0;
}
