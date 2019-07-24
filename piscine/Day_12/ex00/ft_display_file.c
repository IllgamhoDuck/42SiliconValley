/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:08:31 by hypark            #+#    #+#             */
/*   Updated: 2018/05/30 20:56:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

int			main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[1024];

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc >= 3)
		ft_putstr("Too many arguments.\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("Open() Failed.\n");
		while ((ret = read(fd, buf, 1024)) != 0 && ret != -1)
			write(1, buf, ret);
		close(fd);
	}
	return (0);
}
