/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:59:16 by hypark            #+#    #+#             */
/*   Updated: 2018/06/07 22:12:05 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void		fprime(unsigned int nb)
{
	unsigned int i;

	if (nb == 1)
		printf("1");
	else
	{
		i = 2;
		while (nb > 1)
		{
			if (nb % i == 0)
			{
				printf("%d", i);
				nb /= i;
				if (nb > 1)
					printf("*");
				i--;
			}
			i++;
		}
	}
}

/*
void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void		ft_putnbr(long nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int			is_prime(int nb)
{
	int		div;
	int		i;

	i = 2;
	div = nb / 2;
	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	printf("div : %d\n", div);
	while (i <= div)
	{
		if (nb % i == 0)
			return (0);
		//printf("%d\n", i);
		i++;
	}
	return (1);
}

void		fprime(int nb)
{
	int		prime;
	int		ok;

	prime = 0;
	if (nb == 1)
	{
		ft_putnbr(1);
		return ;
	}
	while (nb != 1)
	{
		ok = 0;
		prime = 0;
		while (ok == 0)
		{
			if (is_prime(prime))
			{
				printf("prime : %d\n", prime);
				if ((nb % prime) == 0)
				{
					ft_putnbr(prime);
					ok = 1;
				}
				else
					prime++;
			}
			else
				prime++;
		}
		nb /= prime;
		if (nb != 1)
			ft_putchar('*');
	}
}
*/

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
