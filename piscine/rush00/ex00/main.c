/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:58:03 by hule              #+#    #+#             */
/*   Updated: 2018/05/20 21:41:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);
void	rush(int x, int y);

void	tests1(void)
{
	ft_putchar('-');
	ft_putchar('\n');
	rush(5, 3);
	ft_putchar('-');
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('-');
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('-');
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('-');
	ft_putchar('\n');
	rush(4, 4);
}

void	tests2(void)
{
	ft_putchar('-');
	ft_putchar('\n');
	rush(-4, 4);
	ft_putchar('-');
	ft_putchar('\n');
	rush(4, -4);
	ft_putchar('-');
	ft_putchar('\n');
	rush(0, 0);
}

int		main(void)
{
	rush(5, 5);
	tests1();
	tests2();
	return (0);
}
