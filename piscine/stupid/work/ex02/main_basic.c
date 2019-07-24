
					#include <stdio.h>
					#include <stdlib.h>
					#include <string.h>

					#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
					#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

					int			ft_atoi(char *str);
				
int main()
{
int res; int exp;res = ft_atoi("0"), exp = 0;
printf("ft_atoi('0') (0 vs %d) -> %d\n", res, res == exp);
res = ft_atoi("15"), exp = 15;
printf("ft_atoi('15') (15 vs %d) -> %d\n", res, res == exp);
res = ft_atoi("-25"), exp = -25;
printf("ft_atoi('-25') (-25 vs %d) -> %d\n", res, res == exp);
res = ft_atoi("12345"), exp = 12345;
printf("ft_atoi('12345') (12345 vs %d) -> %d\n", res, res == exp);
res = ft_atoi("987654321"), exp = 987654321;
printf("ft_atoi('987654321') (987654321 vs %d) -> %d\n", res, res == exp);
res = ft_atoi("-34567"), exp = -34567;
printf("ft_atoi('-34567') (-34567 vs %d) -> %d\n", res, res == exp);
res = ft_atoi("2147483647"), exp = 2147483647;
printf("ft_atoi('2147483647') (2147483647 vs %d) -> %d\n", res, res == exp);
res = ft_atoi("-2147483648"), exp = -2147483648;
printf("ft_atoi('-2147483648') (-2147483648 vs %d) -> %d\n", res, res == exp);



return 0;
}
