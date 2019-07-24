
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_strcmp(char *s1, char *s2);
				
int main()
{
int exp, res;res = ft_strcmp("A", ""), exp = 65;
printf("ft_strcmp('A', '') (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strcmp("", ""), exp = 0;
printf("ft_strcmp('', '') (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strcmp("", "A"), exp = -65;
printf("ft_strcmp('', 'A') (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strcmp("asde", "asdf"), exp = -1;
printf("ft_strcmp('asde', 'asdf') (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strcmp("asdf", "asdf"), exp = 0;
printf("ft_strcmp('asdf', 'asdf') (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strcmp("asdg", "asdf"), exp = 1;
printf("ft_strcmp('asdg', 'asdf') (%d vs %d) -> %d\n", exp, res, res == exp);



return 0;
}
