/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 23:34:10 by hypark            #+#    #+#             */
/*   Updated: 2018/05/21 23:37:39 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_str_is_numeric(char *str)
{
	if (!*str)
		return (1);
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
		}
		else
			return (0);
		str++;
	}
	return (1);
}
