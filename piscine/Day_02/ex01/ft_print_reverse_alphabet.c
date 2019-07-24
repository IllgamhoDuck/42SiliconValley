/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:04:37 by hypark            #+#    #+#             */
/*   Updated: 2018/05/17 21:32:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_print_alphabet(void)
{
	char	alphabet_char;

	alphabet_char = 'z';
	while (alphabet_char >= 'a')
	{
		ft_putchar(alphabet_char);
		alphabet_char--;
	}
}
