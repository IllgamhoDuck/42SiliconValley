/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:04:37 by hypark            #+#    #+#             */
/*   Updated: 2018/05/17 21:31:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_is_negative(int n)
{
	char	np_show;

	np_show = 'P';
	if (n >= 0)
	{
		np_show = 'P';
	}
	else if (n < 0)
	{
		np_show = 'N';
	}
	ft_putchar(np_show);
}
