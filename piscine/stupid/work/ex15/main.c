
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_str_is_printable(char *str);
				
int main()
{
TEST(ft_str_is_printable(""), 1);
TEST(ft_str_is_printable("!@#$^&*()_+-=[]{}:;,./<>?"), 1);
TEST(ft_str_is_printable("1234"), 1);
TEST(ft_str_is_printable("ASDF"), 1);
TEST(ft_str_is_printable("\n"), 0);
TEST(ft_str_is_printable("\x7f"), 0);
TEST(ft_str_is_printable("\xf0"), 0);
TEST(ft_str_is_printable("asdf"), 1);



return 0;
}
