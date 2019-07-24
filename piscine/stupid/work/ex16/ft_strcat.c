/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:00:19 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 00:10:34 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, char *src)
{
	char	*strcat;

	strcat = dest;
	while (*strcat != '\0')
		strcat++;
	while (*src != '\0')
	{
		*strcat = *src;
		strcat++;
		src++;
	}
	*strcat = '\0';
	return (dest);
}
