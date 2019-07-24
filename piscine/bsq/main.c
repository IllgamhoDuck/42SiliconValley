/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:51:44 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 13:40:59 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				print_error(void)
{
	write(2, STR("map error\n"));
	return (-1);
}

int				main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
	{
		if (process_file(0))
			print_error();
	}
	else
	{
		while (--argc > 0)
		{
			if ((fd = open(*++argv, O_RDONLY)) == -1)
				print_error();
			else
			{
				if (process_file(fd))
					print_error();
				close(fd);
			}
			if (argc > 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
