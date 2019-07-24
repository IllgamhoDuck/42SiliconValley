/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:43:11 by hypark            #+#    #+#             */
/*   Updated: 2018/05/19 00:03:18 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_iterative_factorial(int nb)
{
	int		i;
	int		total;

	i = 1;
	total = 1;
	if (nb < 0)
	{
		return (0);
	}
	else if (nb >= 13)
	{
		return (0);
	}
	else if (nb == 0 || nb == 1)
	{
		return (1);
	}
	while (i <= nb)
	{
		total *= i;
		i++;
	}
	return (total);
}
