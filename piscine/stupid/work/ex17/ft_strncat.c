/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:48:29 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 00:54:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strncat(char *dest, char *src, int nb)
{
	char	*strcat;
	int		i;

	strcat = dest;
	i = 0;
	while (*strcat != '\0')
		strcat++;
	while (*src != '\0' && i < nb)
	{
		*strcat = *src;
		strcat++;
		src++;
		i++;
	}
	*strcat = '\0';
	return (dest);
}
