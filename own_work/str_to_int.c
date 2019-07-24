/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:58:03 by hule              #+#    #+#             */
/*   Updated: 2018/05/20 02:14:41 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

// Caculating the power 10
// Input : number of power
// Output : result after caculating the power
// Ex : power_ten(1) -> 10 power_ten(2) -> 100
int			power_ten(int iter_num)
{
	int		i;
	int		total;

	i = 0;
	total = 1;
	while (i < iter_num)
	{
		total *= 10;
		i++;
	}
	return (total);
}

// Turn the string to int type
// Input : the address of string & digit
// Output : integer
// Ex : str_to_int(Address of "4242", 3) -> 4242
int			str_to_int(char *c, int digit)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	while (i <= digit)
	{
		total += ((int)(c[i] - '0') * power_ten(digit - i));
		i++;
	}
	return (total);
}

// Calculating the digit given the string
// Input : the address of string
// Output : the digit of given string
// Ex : cal_digit(Address of "4242") -> 3
int			cal_digit(char *c)
{
	int 	digit;

	digit = 0;
	while (c[digit] != '\0')
	{
		digit++;
	}
	digit--;
	return (digit);
}

// After compiling and made a BINARY file
// You can use this file like 
// ./str_to_int '40' -> 40
int			main(int argc, char *argv[])
{
	int		digit;
	int		number;

	digit = cal_digit(argv[1]);
	number = str_to_int(argv[1], digit);

	printf("Turned the string to integer : %d\n", number);
	return (0);
}
