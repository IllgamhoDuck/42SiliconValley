/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:17:36 by hypark            #+#    #+#             */
/*   Updated: 2018/06/03 15:57:39 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			bottom_len(int size)
{
	int		interb_num;
	int		b_num;
	int		total;

	b_num = 0;
	interb_num = 3;
	total = 1;
	while (++b_num <= size)
	{
		total += (b_num + 1) * 2;
		if (b_num != size)
			total += interb_num * 2;
		if (b_num % 2 == 0)
			interb_num += 1;
	}
	return (total + 2);
}

void		print(int number, char c)
{
	int		i;

	i = 0;
	while (++i <= number)
	{
		ft_putchar(c);
	}
}

void		print_line(int b_num, int b_line, int bot_len)
{
	int		line_len;
	int		space_len;

	line_len = bottom_len(b_num) - (b_num + 2 - b_line) * 2;
	space_len = (bot_len - line_len) / 2;
	print(space_len, ' ');
	ft_putchar('/');
	print(line_len - 2, '*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void		print_d_line(int b_num, int b_line, int bot_len, int d_num)
{
	int		line_len;
	int		space_len;

	line_len = bottom_len(b_num) - (b_num + 2 - b_line) * 2;
	space_len = (bot_len - line_len) / 2;
	print(space_len, ' ');
	ft_putchar('/');
	print((line_len - 2 - d_num) / 2, '*');
	if (b_line == ((b_num + 2 - d_num) + (d_num / 2 + 1)) && d_num >= 5)
	{
		print(d_num - 2, '|');
		ft_putchar('$');
		ft_putchar('|');
	}
	else
		print(d_num, '|');
	print((line_len - 2 - d_num) / 2, '*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void		sastantua(int size)
{
	int		b_num;
	int		b_line;
	int		bot_len;
	int		d_num;

	if (size % 2 == 0)
		d_num = size - 1;
	else
		d_num = size;
	b_num = 0;
	bot_len = bottom_len(size);
	while (++b_num <= size)
	{
		b_line = 0;
		while (++b_line <= b_num + 2)
		{
			if (b_num != size)
				print_line(b_num, b_line, bot_len);
			else if (b_num == size && b_line <= (b_num + 2 - d_num))
				print_line(b_num, b_line, bot_len);
			else
				print_d_line(b_num, b_line, bot_len, d_num);
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc > 1)
	{
		sastantua(argv[1][0] - '0');
	}
	return (0);
}
