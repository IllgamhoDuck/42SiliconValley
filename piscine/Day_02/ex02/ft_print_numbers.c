/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:04:37 by hypark            #+#    #+#             */
/*   Updated: 2018/05/17 21:31:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_print_numbers(void)
{
	char	digit_char;

	digit_char = '0';
	while (digit_char <= '9')
	{
		ft_putchar(digit_char);
		digit_char++;
	}
}
