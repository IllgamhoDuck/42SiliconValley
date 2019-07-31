/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:59:16 by hypark            #+#    #+#             */
/*   Updated: 2019/07/30 16:02:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
** 소수는 소수로만 나눌 수 있다는 가정이 깔려야 단순해진다.
*/

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

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
