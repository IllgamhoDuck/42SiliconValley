/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 22:33:16 by hypark            #+#    #+#             */
/*   Updated: 2018/05/23 22:44:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

void		ft_print_words_tables(char **tab)
{
	int		i;
	int		n_add;

	i = 0;
	n_add = 0;
	while (tab[i++] != 0)
		n_add++;
	i = 0;
	while (i <= n_add)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
