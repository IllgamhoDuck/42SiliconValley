/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:19:15 by hypark            #+#    #+#             */
/*   Updated: 2019/08/11 02:43:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					main(void)
{
//	// when flag is 000 no width
//	printf("hello this is for testing %0.06d\n", 123);
//	ft_printf("hello this is for testing %0.06d\n", 123);
//
//	// when flag is 000006 flag has 5 0 and width is 6
//	printf("hello this is for testing %0+00006d\n", 123);
//	ft_printf("hello this is for testing %0+00006d\n", 123);
//
//	// 0 - cannot be together
//	//printf("hello this is for testing %0-6d\n", 123);
//	printf("hello this is for testing %+-6d\n", 123);
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
//	// flag = - width = 3 length = 'l'
//	printf("hello this is for testing %-3ld\n", (long)123);
//	ft_printf("hello this is for testing %-3ld\n", (long)123);
//
//	// flag = - width = 3 length = 'll'
//	printf("hello this is for testing %-3lld\n", (long long)123);
//	ft_printf("hello this is for testing %-3lld\n", (long long)123);
//
//	// flag = 0 width = 3 length = 'h'
//	printf("hello this is for testing %03hd\n", (short)123);
//	ft_printf("hello this is for testing %03hd\n", (short)123);
//
//	// flag =  - width = 3 length = 'hh'
//	//printf("hello this is for testing % -3hhd\n", 123);
//	ft_printf("hello this is for testing % -3hhd\n", 123);
//
//	// asterisk test
//	// width asterisk
	printf("Asterisk testing %*d\n", 5, 123);
	ft_printf("Asterisk testing %*d\n", 5, 123);

	// precision asterisk width = 5 
	printf("Asterisk testing %.*d\n", 5, 123);
	ft_printf("Asterisk testing %.*d\n", 5, 123);

	// width and precision asterisk width 7 precision 5
	printf("Asterisk testing %*.*d\n", 7, 5, 123);
	ft_printf("Asterisk testing %*.*d\n", 7, 5, 123);

	// h and precision asterisk width 7 precision 5
	printf("Asterisk testing %*.*d\n", 7, 5, 123);
	ft_printf("Asterisk testing %*.*d\n", 7, 5, 123);

//	// test %%
//	// only %%
//	printf("\%\% testing %%%%%%\n");
//	ft_printf("\%\% testing %%%%%%\n");
//
//	// with %d
//	printf("\%\%\%d%%%d testing %%%%%%\n", 1, 2);
//	ft_printf("\%\%\%d%%%d testing %%%%%%\n", 1, 2);
	return (1);
}
