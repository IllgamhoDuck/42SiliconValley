/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 02:40:36 by hypark            #+#    #+#             */
/*   Updated: 2018/05/17 12:31:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_purchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void ft_print_combn(int n);
{
	int a;
	int total;
	int number;
	a = 0;
	total = 1;
	while ( ++a <= n )
	{
		total *= 10;
	}
	total -= 1;
	a = 0;

	while ( a++ < total )
	{
}

int main()
{
	int input_num;
	scanf("%d", &input_num);
	ft_print_combn(input_num);
	return (0);
}
