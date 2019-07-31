/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:08:05 by hypark            #+#    #+#             */
/*   Updated: 2019/07/30 03:25:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define BUFF 1024

void			error()
{
	printf("There is a error here!");
}

int				main(int ac, char **av)
{
	int			fd[10];
	int			re;
	char		*test;
	int			finish;
	int			i;

	i = 0;
	ac = 1;
	av[0][0] = 0;
	finish = 3;
	if (!(fd[0] = open("1.txt", O_RDONLY)))
		error();
	if (!(fd[1] = open("2.txt", O_RDONLY)))
		error();
	if (!(fd[2] = open("3.txt", O_RDONLY)))
		error();
	while (finish)
	{
		re = get_next_line(fd[i], &test);
		if (re == 0)
			finish -= 1;
		else if (re < 0)
			error();
		printf("The number of fd is %d\n", fd[i]);
		printf("The number of result is %d\n", re);
		printf("%s\n\n", test);
		i++;
		i = i % 3;
	}
	re = get_next_line(1, &test);
	printf("The number of fd is %d\n", 1);
	printf("The number of result is %d\n", re);
	printf("%s\n\n", test);
	return (0);
}
