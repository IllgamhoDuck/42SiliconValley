/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:18:46 by hypark            #+#    #+#             */
/*   Updated: 2018/05/19 00:40:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_find_next_prime(int nb)
{
	int		prime;
	int		div_num;

	if (nb <= 2)
	{
		return (2);
	}
	while (0 == 0)
	{
		prime = 1;
		div_num = 1;
		while (++div_num <= nb / 2)
		{
			if (nb % div_num == 0)
			{
				prime = 0;
			}
		}
		if (prime == 1)
		{
			return (nb);
		}
		nb++;
	}
}
