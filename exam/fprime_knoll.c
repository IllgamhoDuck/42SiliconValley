/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime_knoll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 22:27:47 by hypark            #+#    #+#             */
/*   Updated: 2018/06/07 22:27:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int        isprime(int x)
{
    int i;
    int count;

    if (x == 1)
        return (1);
    i = 1;
    count = 0;
    while (i <= x)
    {
        if (x % i == 0)
            count++;
        i++;
    }
    if (count == 2)
        return (1);
    return (0);
}

void    fprime(int num)
{
    int div;
    int build;

    build = num;
    div = 2;
    while (div <= num)
    {
        if (num % div == 0)
        {
            while (num % div == 0 && isprime(div))
            {
                printf("%d", div);
                num /= div;
                if (num != 1)
                    printf("*");
            }
        }
        div++;
    }
}

int        main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (isprime(atoi(argv[1])))
        {
            printf("%d\n", atoi(argv[1]));
            return (0);
        }
        else if (atoi(argv[1]) > 0)
            fprime(atoi(argv[1]));
    }
    printf("\n");
    return (0);
}
