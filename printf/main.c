/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:19:15 by hypark            #+#    #+#             */
/*   Updated: 2019/08/13 00:31:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					main(void)
{
	int				ret;
//	// when flag is 000 no width
//	printf("hello this is for testing %0.06d\n", 123);
//	ft_printf("hello this is for testing %0.06d\n", 123);
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

	ret = printf("%15.25d number %#015.10X %%%d\n", 10, 10, 10);
	printf("Total length is : %d\n", ret);
	ret = ft_printf("%15.25d number %#015.10X %%%d\n", 10, 10, 10);
	printf("Total length is : %d\n", ret);
	return (1);
}
