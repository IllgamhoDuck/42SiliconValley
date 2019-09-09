/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:19:15 by hypark            #+#    #+#             */
/*   Updated: 2019/08/27 00:21:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					main(void)
{
	int				ret;
	char			*test_p;
	uint8_t			r_test[30];

	ret = 0;
	r_test[0] = 31;
	r_test[1] = 'd';
	r_test[2] = 'u';
	r_test[3] = 'c';
	r_test[4] = 'k';
	r_test[5] = 'h';
	r_test[6] = 24;
	r_test[7] = 3;
	r_test[8] = 6;
	r_test[9] = 9;
	r_test[10] = 12;
	r_test[11] = ' ';
	r_test[12] = 'i';
	r_test[13] = 's';
	r_test[14] = ' ';
	r_test[15] = 'b';
	r_test[16] = 'e';
	r_test[17] = 's';
	r_test[18] = 't';
	r_test[19] = '.';
	r_test[20] = '\0';
//	// when flag is 000 no width
//	printf("hello this is for testing %0.06d\n", 123);
//	ft_printf("hello this is for testing %0.06d\n", 123);
//	printf("%15.4d number\n", -42);
//	ft_printf("%15.4d number\n", -42);
//
//	// when flag is 000006 flag has 5 0 and width is 6
//	printf("hello this is for testing %0+00006d\n", 123);
//	ft_printf("hello this is for testing %0+00006d\n", 123);
//	printf("hello this is for testing %0+10d\n", 123);
//	ft_printf("hello this is for testing %0+10d\n", 123);
//
//	printf("hello this is for testing %0+007.5d\n", 123);
//	ft_printf("hello this is for testing %0+007.5d\n", 123);
//	printf("hello this is for testing %0+00.5d\n", 123);
//	ft_printf("hello this is for testing %0+00.5d\n", 123);
//	printf("hello this is for testing %0+007.5d\n", -11223);
//	ft_printf("hello this is for testing %0+007.5d\n", -11223);

//	// 0 - cannot be together
//	printf("hello this is for testing %0-6d\n", 123);
//	ft_printf("hello this is for testing %0-6d\n", 123);
//
//	// format d testing
//	printf("hello this is for testing %d\n", 123);
//	ft_printf("hello this is for testing %d\n", 123);
//
//	// precision = 12
//	printf("hello this is for testing %.12d\n", 123);
//	ft_printf("hello this is for testing %.12d\n", 123);
//
//	// when precision input is 00012
//	printf("hello this is for testing %.00012d\n", 123);
//	ft_printf("hello this is for testing %.00012d\n", 123);
//
//	// flag = ' ' width = 3 precision = 12
//	printf("hello this is for testing % 3.00012d\n", 123);
//	ft_printf("hello this is for testing % 3.00012d\n", 123);
//
//	// width = 5 precision = 12
//	printf("hello this is for testing %5.00012d\n", 123);
//	ft_printf("hello this is for testing %5.00012d\n", 123);
//
//	// width = 15 precision = 12
//	printf("hello this is for testing %15.00012d\n", 123);
//	ft_printf("hello this is for testing %15.00012d\n", 123);
//
//	//=============is 0 flag work with precision?==========
//	// flag = 0 width = 15 precision = 12
//	printf("hello this is for testing %015.00012d\n", 123);
//	ft_printf("hello this is for testing %015.00012d\n", 123);
//	
//	// flag = 0 width = 15 precision 0
//	printf("hello this is for testing %015.d\n", 123);
//	ft_printf("hello this is for testing %015.d\n", 123);
//
//	// flag = 0 width = 15 
//	printf("hello this is for testing %015d\n", 123);
//	ft_printf("hello this is for testing %015d\n", 123);
//	//==============NOPE===================================
//
//	// flag = - width = 15 precision 12
//	printf("hello this is for testing %-15.12d\n", 123);
//	ft_printf("hello this is for testing %-15.12d\n", 123);
//	
//	// flag = - width = 15 precision 12
//	printf("hello this is for testing %-15.12d\n", 0123);
//	ft_printf("hello this is for testing %-15.12d\n", 0123);
//
//	// flag = - width = 15 precision 12
//	printf("hello this is for testing %-15.12d\n", 0x123);
//	ft_printf("hello this is for testing %-15.12d\n", 0x123);
//
//	// flag = - width = 3 length = 'l'
//	printf("hello this is for testing %-3ld\n", (long)123);
//	ft_printf("hello this is for testing %-3ld\n", (long)123);
//
	// flag = - width = 3 length = 'll'
//	printf("hello this is for testing %-3lld\n", (long long)112412412412412423);
//	ft_printf("hello this is for testing %-3lld\n", (long long)112412412412412423);
//	printf("hello this is for testing %-3lld\n", (long long)112412412412423);
//	ft_printf("hello this is for testing %-3lld\n", (long long)112412412412423);
//
//	// flag = - width = 3 length = 'll'
//	printf("hello this is for testing %-3lld\n", (unsigned long long)9223372036854775807);
//	ft_printf("hello this is for testing %-3lld\n", (unsigned long long)9223372036854775807);
//
//	// flag = 0 width = 3 length = 'h'
//	printf("hello this is for testing %03hd\n", (short)123124124);
//	ft_printf("hello this is for testing %03hd\n", (short)123124124);
//
//	// flag =  - width = 3 length = 'hh'
//	printf("hello this is for testing % -3hhd\n", (char)123);
//	ft_printf("hello this is for testing % -3hhd\n", (char)123);
//
//	// asterisk test
//	// width asterisk
//	printf("Asterisk testing %*d\n", 5, 123);
//	ft_printf("Asterisk testing %*d\n", 5, 123);
//
//	// precision asterisk width = 5 
//	printf("Asterisk testing %.*d\n", 5, 123);
//	ft_printf("Asterisk testing %.*d\n", 5, 123);
//
//	// width and precision asterisk width 7 precision 5
//	printf("Asterisk testing %*.*d\n", 7, 5, 123);
//	ft_printf("Asterisk testing %*.*d\n", 7, 5, 123);
//
//	// h and precision asterisk width 7 precision 5
//	printf("Asterisk testing %*.*ld\n", 7, 5, (long)123);
//	ft_printf("Asterisk testing %*.*ld\n", 7, 5, (long)123);
//
//	// h and precision asterisk width 7 precision 5
//	printf("Asterisk testing %*.3hhd\n", 7, (char)123);
//	ft_printf("Asterisk testing %*.3hhd\n", 7, (char)123);

//	// test %%
//	// only %%
//	printf("\%\% testing %%%%%%\n");
//	ft_printf("\%\% testing %%%%%%\n");
//	printf("%5%\n");
//	ft_printf("%5%\n");
//	printf("%0 .5%\n");
//	ft_printf("%0 .5%\n");
//	printf("%-5%\n");
//	ft_printf("%-5%\n");
//	printf("%-.5%\n");
//	ft_printf("%-.5%\n");
//	printf("%-7.10%\n");
//	ft_printf("%-7.10%\n");
//	printf("%-7.5%\n");
//	ft_printf("%-7.5%\n");
//	printf("%+.5%\n");
//	ft_printf("%+.5%\n");
//
//	// with %d
//	printf("\%\%\%d%%%d testing %%%%%%\n", 1, 2);
//	ft_printf("\%\%\%d%%%d testing %%%%%%\n", 1, 2);

//	//+ and ' ' and - together
//	printf("test number % -5.3d\n", 100);
//	ft_printf("test number % -5.3d\n", 100);
//	printf("test number % -5.7d\n", 100);
//	ft_printf("test number % -5.7d\n", 100);
//	printf("test number % -10.7d\n", 100);
//	ft_printf("test number % -10.7d\n", 100);
//
//	// sign test positive negative number
//	printf("negative number %.3d\n", -10);
//	ft_printf("negative number %.3d\n", -10);
//	printf("negative number %.3d\n", -10000);
//	ft_printf("negative number %.3d\n", -10000);
//	printf("negative number %15.10d\n", -10);
//	ft_printf("negative number %15.10d\n", -10);
//	printf("positive number %+15.10d\n", 10);
//	ft_printf("positive number %+15.10d\n", 10);
//	printf("positive number %15.10d\n", 10);
//	ft_printf("positive number %15.10d\n", 10);

//	// sign test octal and hexa
//	printf("positive number %15.10ho\n", (short)-1);
//	ft_printf("positive number %15.10ho\n", (short)-1);
//	printf("positive number %15.10o\n", -1);
//	ft_printf("positive number %15.10o\n", -1);
//	printf("positive number %15.10u\n", -1);
//	ft_printf("positive number %15.10u\n", -1);
//	printf("positive number %15.10o\n", (unsigned int)-1);
//	ft_printf("positive number %15.10o\n", (unsigned int)-1);
//	printf("positive number %15.10lo\n", (unsigned long int)-1);
//	ft_printf("positive number %15.10lo\n", (unsigned long int)-1);
//	printf("positive number %15.10llo\n", (unsigned long long int)-1);
//	ft_printf("positive number %15.10llo\n", (unsigned long long int)-1);
//	printf("positive number %15.10o\n", 10);
//	ft_printf("positive number %15.10o\n", 10);
//	printf("positive number %15.10o\n", 010);
//	ft_printf("positive number %15.10o\n", 010);
//	printf("positive number %#15.10o\n", 10);
//	ft_printf("positive number %#15.10o\n", 10);
//	printf("positive number %15.10x\n", 10);
//	ft_printf("positive number %15.10x\n", 10);
//	printf("positive number %15.10X\n", 10);
//	ft_printf("positive number %15.10X\n", 10);
//	printf("positive number %#15.10o\n", 10);
//	ft_printf("positive number %#15.10o\n", 10);
//	printf("positive number %#15.10x\n", 10);
//	ft_printf("positive number %#15.10x\n", 10);
//	printf("positive number %#15.10X\n", 10);
//	ft_printf("positive number %#15.10X\n", 10);
//	printf("positive number %15.10x\n", 10);
//	ft_printf("positive number %15.10x\n", 10);
//	printf("positive number %15.10X\n", 10);
//	ft_printf("positive number %15.10X\n", 10);
//	printf("positive number %-1.10o\n", 10);
//	ft_printf("positive number %-1.10o\n", 10);
//	printf("positive number %-1.10x\n", 10);
//	ft_printf("positive number %-1.10x\n", 10);
//	printf("positive number %015.10X\n", 10);
//	ft_printf("positive number %015.10X\n", 10);
//	printf("%o number\n", 0);
//	ft_printf("%o number\n", 0);

//	ret = printf("%15.25d number %#015.10X %%%d\n", 10, 10, 10);
//	printf("Total length is : %d\n", ret);
//	ret = ft_printf("%15.25d number %#015.10X %%%d\n", 10, 10, 10);
//	printf("Total length is : %d\n", ret);

//	// char ======================================
//	printf("testing char %c\n", 'p');
//	ft_printf("testing char %c\n", 'p');
//	printf("testing char %5c\n", 'p');
//	ft_printf("testing char %5c\n", 'p');
//	printf("testing char %-5c\n", 'p');
//	ft_printf("testing char %-5c\n", 'p');

	// string ======================================
//	printf("testing char %-5s\n", "p");
//	ft_printf("testing char %-5s\n", "p");
//	printf("testing char %-51s\n", "hello");
//	ft_printf("testing char %-51s\n", "hello");
//	printf("testing char %51s\n", "hello");
//	ft_printf("testing char %51s\n", "hello");
//	printf("testing char %.1s\n", "hello");
//	ft_printf("testing char %.1s\n", "hello");
//	printf("testing char %.2s\n", "hello");
//	ft_printf("testing char %.2s\n", "hello");
//	printf("testing char %3.2s\n", "hello");
//	ft_printf("testing char %3.2s\n", "hello");
//	printf("testing char %3.10s\n", "hello");
//	ft_printf("testing char %3.10s\n", "hello");
//	printf("testing char %5.s\n", "hello");
//	ft_printf("testing char %5.s\n", "hello");
//	printf("testing char %5.s\n", NULL);
//	ft_printf("testing char %5.s\n", NULL);
//	printf("testing char %10s\n", NULL);
//	ft_printf("testing char %10s\n", NULL);

//	// pointer ==============================
	test_p = "hello";
//	printf("testing pointer %51p\n", NULL);
//	ft_printf("testing pointer %51p\n", NULL);
//	printf("testing pointer %-5p\n", test_p);
//	ft_printf("testing pointer %-5p\n", test_p);
//	printf("testing pointer %p\n", test_p);
//	ft_printf("testing pointer %p\n", test_p);
//	printf("testing pointer %5p\n", test_p);
//	ft_printf("testing pointer %5p\n", test_p);

	// Fail cases at basic test
//	printf("%#5x\n", 0);
//	ft_printf("%#5x\n", 0);
//	printf("%#08x\n", 42);
//	ft_printf("%#08x\n", 42);

//	printf("%#-08x", 42);
//	ft_printf("%#-08x", 42);
//
//	printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	printf("@moulitest: %.x %.0x\n", 0, 0);	
//	ft_printf("@moulitest: %.x %.0x\n", 0, 0);	
//	printf("@moulitest: %5.x %5.0x\n", 0, 0);
//	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
//	printf("@moulitest: %5.1x %5.10x\n", 0, 0);
//	ft_printf("@moulitest: %5.1x %5.10x\n", 0, 0);
//	printf("thisis duck: %5.1x %5.0x\n", 125, 125);
//	ft_printf("thisis duck: %5.1x %5.0x\n", 125, 125);
//	printf("%#6o\n", 2500);
//	ft_printf("%#6o\n", 2500);
//	printf("%-#6o\n", 2500);
//	ft_printf("%-#6o\n", 2500);
//	printf("%-05o\n", 2500);
//	ft_printf("%-05o\n", 2500);
//	printf("@moulitest: %.o %.0o\n", 0, 0);
//	ft_printf("@moulitest: %.o %.0o\n", 0, 0);
//	printf("@moulitest: %5.o %5.0o\n", 0, 0);
//	ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
//	printf("@moulitest: %5.o %5.0o\n", 1, 0);
//	ft_printf("@moulitest: %5.o %5.0o\n", 1, 0);
//	printf("@moulitest: %5o %5o\n", 0, 0);
//	ft_printf("@moulitest: %5o %5o\n", 0, 0);
//	printf("%-05d\n", 42);
//	ft_printf("%-05d\n", 42);
//	printf("%-05d\n", -42);
//	ft_printf("%-05d\n", -42);
//	printf("@moulitest: %.d %.0d\n", 0, 0);
//	ft_printf("@moulitest: %.d %.0d\n", 0, 0);
//	printf("@moulitest: %5.d %5.0d\n", 0, 0);
//	ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
//	printf("@moulitest: %5d %5.0d\n", 0, 0);
//	ft_printf("@moulitest: %5d %5.0d\n", 0, 0);
//	printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	printf("@moulitest: %#.o %#.0o\n", 0, 0);
//	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
//	printf("%#o\n", 0);
//	ft_printf("%#o\n", 0);
//	printf("%#3.5o\n", 0);
//	ft_printf("%#3.5o\n", 0);
//	printf("%o\n", 0);
//	ft_printf("%o\n", 0);
//	printf("%#x\n", 0);
//	ft_printf("%#x\n", 0);
//	printf("{%*d}\n", -5, 42);
//	ft_printf("{%*d}\n", -5, 42);
//	printf("%\n");
//	ft_printf("%\n");
//	printf("%5.0p, %.p\n", 0, 0);
//	ft_printf("%5.0p, %.p\n", 0, 0);
//	printf("printing%05.0p, %.p\n", 0, 0);
//	ft_printf("printing%05.0p, %.p\n", 0, 0);
//	printf("%05p, %.p\n", 0, 0);
//	ft_printf("%05p, %.p\n", 0, 0);
//	printf("%5.0p, %.p\n", 5, 0);
//	ft_printf("%5.0p, %.p\n", 5, 0);
//	printf("sharp%#5.0p, %.p\n", 5, 0);
//	ft_printf("sharp%#5.0p, %.p\n", 5, 0);
//	printf("%5.3p, %.p\n", 0, 0);
//	ft_printf("%5.3p, %.p\n", 0, 0);
//	printf("%5.3p, %.p\n", 5, 0);
//	ft_printf("%5.3p, %.p\n", 5, 0);
//	printf("%-7.3p, %.p\n", 5, 0);
//	ft_printf("%-7.3p, %.p\n", 5, 0);
//	printf("%0-7.3p, %.p\n", 5, 0);
//	ft_printf("%0-7.3p, %.p\n", 5, 0);
//	printf("sharp with num%#5.1o, %.o\n", 5, 0);
//	ft_printf("sharp with num%#5.1o, %.o\n", 5, 0);
//	printf("sharp with num%#5.1o, %.o\n", 2, 0);
//	ft_printf("sharp with num%#5.1o, %.o\n", 2, 0);
//	printf("sharp with num%#5.3o, %.o\n", 2, 0);
//	ft_printf("sharp with num%#5.3o, %.o\n", 2, 0);
//	printf("sharp with num%#5.2o, %.o\n", 2, 0);
//	ft_printf("sharp with num%#5.2o, %.o\n", 2, 0);
//	printf("%#5.3o\n", 1);
//	ft_printf("%#5.3o\n", 1);
//	printf("%#.3o\n", 1);
//	ft_printf("%#.3o\n", 1);
//	printf("%#.3o\n", 0);
//	ft_printf("%#.3o\n", 0);
//	printf("%#3o\n", 1);
//	ft_printf("%#3o\n", 1);

	// moulinette asterisks and module
//	printf("{%*3d}\n", 5, 0);
//	ft_printf("{%*3d}\n", 5, 0);
//	printf("{%*d}\n", -5, 42);
//	ft_printf("{%*d}\n", -5, 42);
//	printf("%\n");
//	ft_printf("%\n");
//	printf("{%.*s}\n", -5, "42");
//	ft_printf("{%.*s}\n", -5, "42");
//	printf("{%05.*d}\n", -15, 42);
//	ft_printf("{%05.*d}\n", -15, 42);
//	printf("{%05.d}\n", 42);
//	ft_printf("{%05.d}\n", 42);
//
//	// float
//	printf("%0+5f\n", (double)12); 
//	ft_printf("%0+5f\n", (double)12); 
//	printf("%0+12f\n", (double)12); 
//	ft_printf("%0+12f\n", (double)12); 
//	printf("%+12f\n", (double)12); 
//	ft_printf("%+12f\n", (double)12); 
//	printf("Testing negative %+-12f\n", (double)12); 
//	ft_printf("Testing negative %+-12f\n", (double)12); 
//	printf("Testing negative %0+-12f\n", (double)12); 
//	ft_printf("Testing negative %0+-12f\n", (double)12); 
//	printf("%5.f\n", (double)12); 
//	ft_printf("%5.f\n", (double)12); 
//	printf("%5.f\n", (double)12.123124124124); 
//	ft_printf("%5.f\n", (double)12.123124124124); 
//	printf("%#-+015.130f\n", (double)12.123124124124); 
//	ft_printf("%#-+015.130f\n", (double)12.123124124124); 
//	printf("%05.f\n", (double)12); 
//	ft_printf("%05.f\n", (double)12); 
//	printf("Minus with width %-5.f\n", (double)12); 
//	ft_printf("Minus with width %-5.f\n", (double)12); 
//	printf("Minus with width %-5.0f\n", (double)12); 
//	ft_printf("Minus with width %-5.0f\n", (double)12); 
//	printf("Minus with width %-5.1f\n", (double)12); 
//	ft_printf("Minus with width %-5.1f\n", (double)12); 
//	printf("Minus with width %-5.7f\n", (double)12); 
//	ft_printf("Minus with width %-5.7f\n", (double)12); 
//	printf("%0+5.3f\n", (double)12);
//	ft_printf("%0+5.3f\n", (double)12);
//	printf("%0+5.7f\n", (double)12);
//	ft_printf("%0+5.7f\n", (double)12);
//	printf("%0+10.7f\n", (double)12);
//	ft_printf("%0+10.7f\n", (double)12);
//	printf("%0+15.7f\n", (double)12);
//	ft_printf("%0+15.7f\n", (double)12);
//	printf("%0+15.7f\n", (double)-12);
//	ft_printf("%0+15.7f\n", (double)-12);
//	printf("%015.7f\n", (double)-12);
//	ft_printf("%015.7f\n", (double)-12);
//	printf("%0 15.7f\n", (double)12);
//	ft_printf("%0 15.7f\n", (double)12);
//	printf("% 15.7f\n", (double)12);
//	ft_printf("% 15.7f\n", (double)12);
//	printf("%0+10.7f\n", (float)-12.123);
//	ft_printf("%0+10.7f\n", (float)-12.123);
//	printf("%0+10.7f\n", (double)-12.123);
//	ft_printf("%0+10.7f\n", (double)-12.123);
//	printf("%Lf\n", (long double)-1124124124142.12412412);
//	ft_printf("%Lf\n", (long double)-1124124124142.12412412);
//	printf("%0+10.f\n", (double)0);
//	ft_printf("%0+10.f\n", (double)0);
//	printf("%.10Lf\n", (long double)-1124124124142.12412412);
//	ft_printf("%.10Lf\n", (long double)-1124124124142.12412412);
//	printf("%.20Lf\n", (long double)-1124124124142.12412412125125125125125);
//	ft_printf("%.20Lf\n", (long double)-1124124124142.12412412125125125125125);
//	printf("%#-+015.f\n", (double)12.123124124124); 
//	ft_printf("%#-+015.f\n", (double)12.123124124124); 
//	printf("%#-+015.0f\n", (double)12.123124124124); 
//	ft_printf("%#-+015.0f\n", (double)12.123124124124); 
//	printf("%#0+-10.f\n", (double)12.123);
//	ft_printf("%#0+-10.f\n", (double)12.123);
//
//	printf("%#0+-10.f\n", (double)12);
//	ft_printf("%#0+-10.f\n", (double)12);
//	printf("hello%\n");
//	ft_printf("hello%\n");
//	printf("%");
//	ft_printf("%");
//	printf("%s\n\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
//	ft_printf("%s\n\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
//	printf("%Lf\n", 3.9999999l);
//	ft_printf("%Lf\n", 3.9999999l);
//	printf("this %.0f float\n", 1.6);
//	ft_printf("this %.0f float\n", 1.6);
//	printf("%.0f\n", -3.85);
//	ft_printf("%.0f\n", -3.85);
//	printf("%.0f\n", 573.924);
//	ft_printf("%.0f\n", 573.924);
//	printf("test %.10Lf\n", 0.87650894255l);
//	ft_printf("test %.10Lf\n", 0.87650894255l);
//	printf("test2 %.10f\n", 0.87650894255);
//	ft_printf("test2 %.10f\n", 0.87650894255);
//	printf("%f\n", -56.2012685);
//	ft_printf("%f\n", -56.2012685);
//	printf("%Lf\n", -56.2012685l);
//	ft_printf("%Lf\n", -56.2012685l);
//
//
	// BONUS PART
	// BINARY - b B
//	ft_printf("testing binary %b\n", 123);
	ft_printf("testing binary %15.7b\n", 21487389);
	ft_printf("testing binary %#15.b\n", 123);
//	ft_printf("testing binary %#015.b\n", 123);
//	ft_printf("testing binary %-#015.b\n", 123);
//	ft_printf("testing binary %B\n", 123);
//	ft_printf("testing binary %15.7B\n", 123);
//	ft_printf("testing binary %#15.B\n", 123);
//	ft_printf("testing binary %#015.B\n", 123);
//	ft_printf("testing binary %-#015.B\n", 123);

	// Non printable
//	ft_printf("testing non printable %.r\n");
//	ft_printf("testing non printable %.r\n");
//	ft_printf("%r\n", "testing this!");
//	ft_printf("%r\n", 0);
//	ft_printf("%r\n", r_test);

	// Color
	ft_printf("the color {red} is {blue} like {yellow} this {blue} bold {magenta} red {cyan} and red\n");
	ft_printf("I will put the color to normal {eos} like this\n");
	ft_printf("the color {red} is like this {bold red} bold red and red\n");

	// fd
//	ft_printf("the default fd is %@, and 1 is %1@, and also its %2@ the error message");
//	ft_printf("fd 3is %3@ and ...\n");

//	ft_printf("[%*.*d]\n", -20, 2, 500);
//	printf("[%*.*d]\n", -20, 2, 500);
	ft_printf("%x\n", -125125);
	printf("%x\n", -125125);
	return (0);
}
