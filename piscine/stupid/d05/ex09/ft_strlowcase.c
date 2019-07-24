/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:31:49 by hypark            #+#    #+#             */
/*   Updated: 2018/05/21 22:31:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strlowcase(char *str)
{
	char	*lowcase;

	lowcase = str;
	while (*lowcase != '\0')
	{
		if (*lowcase >= 65 && *lowcase <= 90)
			*lowcase += 32;
		lowcase++;
	}
	return (str);
}
