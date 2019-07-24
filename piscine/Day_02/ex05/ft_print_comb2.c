/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:04:37 by hypark            #+#    #+#             */
/*   Updated: 2018/05/17 21:28:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_print_comb(void)
{
	int		a;
	int		b;

	a = -1;
	while (++a <= 98)
	{
		b = a;
		while (++b <= 99)
		{
			ft_putchar((char)(a / 10 + '0'));
			ft_putchar((char)(a % 10 + '0'));
			ft_putchar(' ');
			ft_putchar((char)(b / 10 + '0'));
			ft_putchar((char)(b % 10 + '0'));
			if (a != 98 || b != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
