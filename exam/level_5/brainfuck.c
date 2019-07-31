/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:30:57 by hypark            #+#    #+#             */
/*   Updated: 2018/06/01 22:37:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		brainfuck(char *str)
{
	char	*print;
	int		num;

	num = 0;
	print = (char *)malloc(sizeof(char *) * 2048);
	while (*str)
	{
		if (*str == '>')
			print++;
		else if (*str == '<')
			print--;
		else if (*str == '+')
			(*print)++;
		else if (*str == '-')
			(*print)--;
		else if (*str == '.')
			ft_putchar(*print);
		else if (*str == '[' && !(*print))
		{
			str++;
			while(*str != ']' || num != 0)
			{
				if (*str == '[')
					num++;
				else if (*str == ']' && num > 0)
					num--;
				str++;
			}
		}
		else if (*str == ']' && *print)
		{
			str--;
			while (*str != '[' || num != 0)
			{
				if (*str == ']')
					num--;
				else if (*str == '[' && num < 0)
					num++;
				str--;
			}
		}	
		str++;
	}

}

int			main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		brainfuck(argv[1]);
	ft_putchar('\n');
	return (0);
}
