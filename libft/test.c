/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 00:51:06 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 01:05:32 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int					main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("the above one if ft and the below one is original\n");
		if (ft_strcmp(argv[1], "1") == 0)
		{
			char	str[30] = "This will be changed\n";
			char	str_c[30] = "This will be changed\n";

			printf("Testing memset\n");
			printf("%s", str);
			ft_memset(str+2, 'G', 10); 
			memset(str_c+2, 'G', 10); 
			printf("%s", str);
			printf("%s", str_c);
		}
		if (ft_strcmp(argv[1], "2") == 0)
		{
			char	str[30] = "This will be changed\n";
			char	str_c[30] = "This will be changed\n";

			printf("Testing bzero\n");
			printf("With length n 0\n");
			printf("%s", str);
			ft_bzero(str, 0);
			bzero(str_c, 0);
			printf("%s", str);
			printf("%s\n", str_c);
			printf("With length n 10\n");
			printf("%s", str);
			ft_bzero(str, 10);	
			bzero(str_c, 10);
			printf("%s", str);
			printf("%s", str_c);
		}
		if (ft_strcmp(argv[1], "3") == 0)
		{
			char	src[30] = "this is the source\n";
			char	dst[30] = "destination is here\n";
			char	src_c[30] = "this is the source\n";
			char	dst_c[30] = "destination is here\n";
			char	*result;
			char	*result_c;

			printf("Testing memcpy\n");
			printf("%s", src);
			printf("%s\n", dst);
			result = ft_memcpy(dst, src, 5);
			result_c = memcpy(dst_c, src_c, 5);
			printf("%s", result);
			printf("%s\n", result_c);
			result = ft_memcpy(dst, src, 10);
			result_c = memcpy(dst_c, src_c, 10);
			printf("%s", result);
			printf("%s\n", result_c);
			result = ft_memcpy(dst, src, 20);
			result_c = memcpy(dst_c, src_c, 20);
			printf("%s", result);
			printf("%s\n", result_c);
		}
		if (ft_strcmp(argv[1], "4") == 0)
		{
			char	src[30] = "this is the source\n";
			char	dst[30] = "destination is here\n";
			char	src_c[30] = "this is the source\n";
			char	dst_c[30] = "destination is here\n";
			char	*result;
			char	*result_c;

			printf("Testing memcpy\n");
			printf("%s", src);
			printf("%s\n", dst);
			result = ft_memccpy(dst, src, 'e', 5);
			result_c = memccpy(dst_c, src_c, 'e', 5);
			printf("%s", result);
			printf("%s\n", result_c);
			result = ft_memccpy(dst, src, 'e', 10);
			result_c = memccpy(dst_c, src_c, 'e', 10);
			printf("%s", result);
			printf("%s\n", result_c);
			result = ft_memccpy(dst, src, 'e', 20);
			result_c = memccpy(dst_c, src_c, 'e', 20);
			printf("%s", result);
			printf("%s\n", result_c);
		}
		if (ft_strcmp(argv[1], "5") == 0)
		{
			printf("Testing memmove\n");
			char	sample[30] = "this is a test of memmove.\n";
			char	*src;
			char	*dst;
			char	*result;
			char	*result_c;

			printf("%s", sample);
			src = sample;
			dst = sample;
			result = ft_memmove(dst, src, 5);
			result_c = memmove(dst, src, 5);
			printf("%s", result);
			printf("%s\n", result_c);
			src = sample + 7;
			dst = sample + 5;
			result = ft_memmove(dst, src, 5);
			result_c = memmove(dst, src, 5);
			printf("%s", result);
			printf("%s\n", result_c);
			src = sample;
			dst = sample + 3;
			result = ft_memmove(dst, src, 5);
			result_c = memmove(dst, src, 5);
			printf("%s", result);
			printf("%s\n", result_c);
		}
		if (ft_strcmp(argv[1], "6") == 0)
		{
			printf("Testing memchr\n");
			char	sample[30] = "this is a test of memchr.\n";
			char	test_c = 'e';
			char	*result;
			char	*result_c;

			result = ft_memchr(sample, test_c, 5);
			result_c = memchr(sample, test_c, 5);
			printf("%s", result);
			printf("%s\n", result_c);
			result = ft_memchr(sample, test_c, 15);
			result_c = memchr(sample, test_c, 15);
			printf("%s", result);
			printf("%s\n", result_c);
			test_c = 'z';
			result = ft_memchr(sample, test_c, 20);
			result_c = memchr(sample, test_c, 20);
			printf("%s", result);
			printf("%s\n", result_c);
		}
		if (argv[1][0] == '7')
		if (ft_strcmp(argv[1], "7") == 0)
		{
			printf("Testing memcmp\n");
			char	t_1[10] = "duckduck";
			char	t_2[10] = "duckduck";
			char	t_3[10] = "\200";
			char	t_4[10] = "\0";
			char	t_5[10] = "\124jkl1";
			char	t_6[10] = "\124jzl1";
			int		result;
			int		result_c;

			result = ft_memcmp(t_1, t_2, 8);
			result_c = memcmp(t_1, t_2, 8);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_memcmp(t_3, t_4, 8);
			result_c = memcmp(t_3, t_4, 8);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_memcmp(t_5, t_6, 1);
			result_c = memcmp(t_5, t_6, 1);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_memcmp(t_5, t_6, 8);
			result_c = memcmp(t_5, t_6, 8);
			printf("%d\n", result);
			printf("%d\n", result_c);
		}
		if (argv[1][0] == '8')
		if (ft_strcmp(argv[1], "8") == 0)
		{
			printf("Testing strlen\n");
			char	t_1[10] = "duckduck";
			char	t_2[10] = "ducck";
			char	t_3[10] = "\200";
			char	t_4[10] = "\0";
			char	t_5[20] = "\124jkl12124kj1";
			int		result;
			int		result_c;

			result = ft_strlen(t_1);
			result_c = strlen(t_1);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_strlen(t_2);
			result_c = strlen(t_2);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_strlen(t_3);
			result_c = strlen(t_3);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_strlen(t_4);
			result_c = strlen(t_4);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_strlen(t_5);
			result_c = strlen(t_5);
			printf("%d\n", result);
			printf("%d\n", result_c);
		}
		if (ft_strcmp(argv[1], "9") == 0)
		{
			printf("Testing strdup\n");
			char	t_s[50] = "hello this is a testing of strdup\n";
			char	t_s2[50] = "hello this is\0 a testing of strdup\n";
			char	*result;
			char	*result_c;

			result = ft_strdup(t_s);
			result_c = strdup(t_s);
			printf("%s", result);
			printf("%s", result_c);
			result = ft_strdup(t_s2);
			result_c = strdup(t_s2);
			printf("%s", result);
			printf("%s", result_c);
		}
		if (ft_strcmp(argv[1], "10") == 0)
		{
			printf("Testing strcpy\n");
			char	t_s[50] = "hello this is a testing of strcpy\n";
			char	t_s2[50] = "hello this is\0 a testing of strcpy\n";
			char	result[50] = "duckduckduckdukcdukcdukcdukcdukc";
			char	result_c[50] = "duckduckduckdukcdukcdukcdukcdukc";

			ft_strcpy(result, t_s);
			strcpy(result_c, t_s);
			printf("%s", result);
			printf("%s", result_c);
			ft_strcpy(result, t_s2);
			strcpy(result_c, t_s2);
			printf("%s", result);
			printf("%s", result_c);
		}
		if (ft_strcmp(argv[1], "11") == 0)
		{
			printf("Testing strncpy\n");
			char	t_s[50] = "hello this is a testing of strncpy\n";
			char	t_s2[50] = "hello this is\0 a testing of strncpy\n";
			char	result[50] = "duckduckduckdukcdukcdukcdukcdend";
			char	result_c[50] = "duckduckduckdukcdukcdukcdukcdend";

			ft_strncpy(result, t_s, 5);
			strncpy(result_c, t_s, 5);
			printf("%s\n", result);
			printf("%s\n", result_c);
			ft_strncpy(result, t_s2, 5);
			strncpy(result_c, t_s2, 5);
			printf("%s\n", result);
			printf("%s\n", result_c);
			ft_strncpy(result, t_s2, 20);
			strncpy(result_c, t_s2, 20);
			printf("%s\n", result);
			printf("%s", result_c);
		}
		if (ft_strcmp(argv[1], "12") == 0)
		{
			printf("Testing strcat\n");
		}
		if (ft_strcmp(argv[1], "13") == 0)
		{
			printf("Testing strncat\n");
		}
		if (ft_strcmp(argv[1], "14") == 0)
		{
			printf("Testing strlcat\n");
			int		result;
			char	test[50] = "aaa";

			result = ft_strlcat("aa", "abcd", 2);
			printf("%d\n", result);
			result = strlcat("aa", "abcd", 2);
			printf("%d\n", result);
			result = ft_strlcat("aaa", "abcd", 2);
			printf("%d\n", result);
			result = strlcat("aaa", "abcd", 2);
			printf("%d\n", result);
			result = ft_strlcat(test, "abc", 20);
			printf("%d\n", result);
			result = strlcat(test, "abc", 20);
			printf("%d\n", result);
		}
		if (ft_strcmp(argv[1], "15") == 0)
		{
			printf("Testing strchr\n");
		}
		if (ft_strcmp(argv[1], "16") == 0)
		{
			printf("Testing strrchr\n");
		}
		if (ft_strcmp(argv[1], "17") == 0)
		{
			printf("Testing strstr\n");
		}
		if (ft_strcmp(argv[1], "18") == 0)
		{
			printf("Testing strnstr\n");
			const char *largestring = "Foo Bar Baz";
           	const char *smallstring = "Bar";
           	char *ptr;

           	ptr = ft_strnstr(largestring, smallstring, 6);
			printf("%s\n", ptr);
           	ptr = strnstr(largestring, smallstring, 6);
			printf("%s\n", ptr);
           	ptr = ft_strnstr(largestring, smallstring, 7);
			printf("%s\n", ptr);
           	ptr = strnstr(largestring, smallstring, 7);
			printf("%s\n", ptr);
		}
		if (ft_strcmp(argv[1], "19") == 0)
		{
			printf("Testing strcmp\n");
		}
		if (ft_strcmp(argv[1], "20") == 0)
		{
			printf("Testing strncmp\n");
		}
		if (ft_strcmp(argv[1], "21") == 0)
		{
			printf("Testing atoi\n");
			char	*t_1 = "++876";
			char	*t_2 = "  \t\n  \r\r\v\f-899";
			char	*t_3 = "500";
			char	*t_4 = "-500";
			int		result;
			int		result_c;

			result = ft_atoi(t_1);
			result_c = atoi(t_1);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_atoi(t_2);
			result_c = atoi(t_2);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_atoi(t_3);
			result_c = atoi(t_3);
			printf("%d\n", result);
			printf("%d\n", result_c);
			result = ft_atoi(t_4);
			result_c = atoi(t_4);
			printf("%d\n", result);
			printf("%d\n", result_c);
		}
		if (ft_strcmp(argv[1], "22") == 0)
		{
			printf("Testing isalpha\n");
		}
		if (ft_strcmp(argv[1], "23") == 0)
		{
			printf("Testing isdigit\n");
		}
		if (ft_strcmp(argv[1], "24") == 0)
		{
			printf("Testing isalnum\n");
		}
		if (ft_strcmp(argv[1], "25") == 0)
		{
			printf("Testing isascii\n");
		}
		if (ft_strcmp(argv[1], "26") == 0)
		{
			printf("Testing isprint\n");
		}
		if (ft_strcmp(argv[1], "27") == 0)
		{
			printf("Testing toupper\n");
		}
		if (ft_strcmp(argv[1], "28") == 0)
		{
			printf("Testing tolower\n");
		}
		if (ft_strcmp(argv[1], "29") == 0)
		{
			char	*test;
			printf("Testing memalloc\n");
			test = ft_memalloc(8);
			printf("%s\n", test);
			test = ft_memalloc(15);
			printf("%s\n", test);
		}
		if (ft_strcmp(argv[1], "30") == 0)
		{
			printf("Testing memdel\n");
		}
		if (ft_strcmp(argv[1], "31") == 0)
		{
			printf("Testing strnew\n");
		}
		if (ft_strcmp(argv[1], "32") == 0)
		{
			printf("Testing strdel\n");
		}
		if (ft_strcmp(argv[1], "33") == 0)
		{
			printf("Testing strclr\n");
		}
		if (ft_strcmp(argv[1], "34") == 0)
		{
			printf("Testing striter\n");
		}
		if (ft_strcmp(argv[1], "35") == 0)
		{
			printf("Testing striteri\n");
		}
		if (ft_strcmp(argv[1], "36") == 0)
		{
			printf("Testing strmap\n");
		}
		if (ft_strcmp(argv[1], "37") == 0)
		{
			printf("Testing strmapi\n");
		}
		if (ft_strcmp(argv[1], "38") == 0)
		{
			printf("Testing strequ\n");
		}
		if (ft_strcmp(argv[1], "39") == 0)
		{
			printf("Testing strnequ\n");
		}
		if (ft_strcmp(argv[1], "40") == 0)
		{
			printf("Testing strsub\n");
		}
		if (ft_strcmp(argv[1], "41") == 0)
		{
			printf("Testing strjoin\n");
		}
		if (ft_strcmp(argv[1], "42") == 0)
		{
			printf("Testing strtrim\n");
			char	test[40] = "helloi\tthis\n\n is duck'/t' quark \t";
			char	*result;

			result = ft_strtrim(test);
			printf("%s/n", result);
			result = ft_strtrim("\t\t\n\t\t   ");
			printf("%s/n", result);
			result = ft_strtrim("");
			printf("%s/n", result);
			result = ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t");
			printf("%s/n", result);
		}
		if (ft_strcmp(argv[1], "43") == 0)
		{
			printf("Testing strsplit\n");
			char	test[40] = "***hello*duck*and*bye*for*tomorrow*";
			char	**result;

			result = ft_strsplit(test, '*');
			printf("%s\n", result[0]);
			printf("%s\n", result[1]);
			printf("%s\n", result[2]);
			printf("%s\n", result[3]);
			printf("%s\n", result[4]);
			printf("%s\n", result[5]);
		}
		if (ft_strcmp(argv[1], "44") == 0)
		{
			printf("Testing itoa\n");
			int		t_1 = -2147483648;
			int		t_2 = 2147483647;
			int		t_3 = 0;
			int		t_4 = -123;
			int		t_5 = 123;
			char	*result;

			result = ft_itoa(t_1);
			printf("%s\n", result);
			result = ft_itoa(t_2);
			printf("%s\n", result);
			result = ft_itoa(t_3);
			printf("%s\n", result);
			result = ft_itoa(t_4);
			printf("%s\n", result);
			result = ft_itoa(t_5);
			printf("%s\n", result);
		}
		if (ft_strcmp(argv[1], "45") == 0)
		{
			printf("Testing putchar\n");
		}
		if (ft_strcmp(argv[1], "46") == 0)
		{
			printf("Testing putstr\n");
		}
		if (ft_strcmp(argv[1], "47") == 0)
		{
			printf("Testing putendl\n");
			char		t_1[10] = "hello";
			char		t_2[4];

			ft_putendl(t_1);
			ft_putendl(t_2);
		}
		if (ft_strcmp(argv[1], "48") == 0)
		{
			printf("Testing putnbr\n");
			int		t_1 = -2147483648;
			int		t_2 = 2147483647;
			int		t_3 = 0;
			int		t_4 = 500;
			int		t_5 = -500;

			ft_putnbr(t_1);
			ft_putnbr(t_2);
			ft_putnbr(t_3);
			ft_putnbr(t_4);
			ft_putnbr(t_5);
		}
		if (ft_strcmp(argv[1], "49") == 0)
		{
			printf("Testing putchar_fd\n");
		}
		if (ft_strcmp(argv[1], "50") == 0)
		{
			printf("Testing putstr_fd\n");
		}
		if (ft_strcmp(argv[1], "51") == 0)
		{
			printf("Testing putendl_fd\n");
		}
		if (ft_strcmp(argv[1], "52") == 0)
		{
			printf("Testing putnbr_fd\n");
		}
		if (ft_strcmp(argv[1], "53") == 0)
		{
			printf("Testing putendl_fd\n");
		}
	}	
	else
		printf("Write the test number");
	return (0);
}
