/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 21:54:36 by hypark            #+#    #+#             */
/*   Updated: 2018/05/31 20:51:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SIZE(x) x, sizeof(x) - 1

void		ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int			ft_cat(int fd)
{
	char	buf[4096];
	int		ret;

	if (fd == -1)
		return (fd);
	while ((ret = read(fd, buf, 4096)) != 0 && ret != -1)
		if (write(1, buf, ret) == -1)
			return (1);
	if (ret == -1)
		return (1);
	close(fd);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc <= 1)
		write(1, SIZE("File name missing.\n"));
	else
	{
		while (++i < argc)
		{
			if (ft_cat(open(argv[i], O_RDONLY)))
			{
				ft_putstr(errno);
				ft_putstr("\n");
			}
		}
	}
	return (0);
}
