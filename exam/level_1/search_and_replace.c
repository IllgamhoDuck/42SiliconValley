/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:37:21 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 09:51:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			search(char *s1, char *s2, char *s3)
{
	while (*s1)
	{
		if (*s1 == *s2)
			*s1 = *s3;
		write (1, s1, 1);
		s1++;
	}
}

int				ft_strlen(char *s1)
{
	int			len;

	len = 0;
	while (*s1)
	{
		len++;
		s1++;
	}
	return (len);
}

int				main(int ac, char **av)
{
	if (ac == 4 && ft_strlen(av[2]) == 1 && ft_strlen(av[3]) == 1)
		search(av[1], av[2], av[3]);
	write(1, "\n", 1);
	return (0);
}
