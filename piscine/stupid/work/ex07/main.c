
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_strncmp(char *s1, char *s2, unsigned int n);
				
int main()
{
int res, exp;res = ft_strncmp("", "", 0), exp = 0;
printf("ft_strncmp('', '', 0) (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strncmp("asde", "asdf", 3), exp = 0;
printf("ft_strncmp('asde', 'asdf', 3) (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strncmp("asde", "asdf", 4), exp = -1;
printf("ft_strncmp('asde', 'asdf', 4) (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strncmp("asdf", "asdf", 3), exp = 0;
printf("ft_strncmp('asdf', 'asdf', 3) (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strncmp("asdf", "asdf", 4), exp = 0;
printf("ft_strncmp('asdf', 'asdf', 4) (%d vs %d) -> %d\n", exp, res, res == exp);
res = ft_strncmp("asdg", "asdf", 4), exp = 1;
printf("ft_strncmp('asdg', 'asdf', 4) (%d vs %d) -> %d\n", exp, res, res == exp);



return 0;
}
