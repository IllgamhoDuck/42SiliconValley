/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:41:01 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 17:37:11 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int			ft_strlen(char *c)
{
	unsigned int	i;

	i = 0;
	while (*c != '\0')
	{
		c++;
		i++;
	}
	return (i);
}

char					*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		else
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}

unsigned int			ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		srclen;
	unsigned int		dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dest);
	if (srclen < size)
		ft_strncpy(dest, src, srclen + 1);
	else if (size != 0)
	{
		ft_strncpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}
