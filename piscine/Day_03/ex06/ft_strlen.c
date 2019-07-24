/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:13:22 by hypark            #+#    #+#             */
/*   Updated: 2018/05/18 00:41:38 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int count_char;

	count_char = 0;
	while (*str)
	{
		count_char += 1;
		str++;
	}
	return (count_char);
}
