/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 22:37:20 by hypark            #+#    #+#             */
/*   Updated: 2018/05/17 23:02:04 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_putstr(char *str)
{
	int check_done;
	int i;

	check_done = 0;
	i = 0;
	while (check_done == 0)
	{
		if (str[i] != '\0')
		{
			ft_putchar(str[i]);
		}
		else
		{
			check_done = 1;
		}
		i++;
	}
}
