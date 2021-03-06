/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 21:49:19 by hypark            #+#    #+#             */
/*   Updated: 2018/05/21 22:36:14 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strupcase(char *str)
{
	char	*upcase;

	upcase = str;
	while (*upcase != '\0')
	{
		if (*upcase >= 97 && *upcase <= 122)
			*upcase -= 32;
		upcase++;
	}
	return (str);
}
