/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 01:07:12 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 15:00:04 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *c)
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

unsigned int		ft_strnlen(char *c, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*c != '\0' && i < size)
	{
		c++;
		i++;
	}
	return (i);
}

char				*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

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

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dest, size);
	if (dstlen == size)
		return (size + srclen);
	if (srclen < size - dstlen)
		ft_strncpy(dest + dstlen, src, srclen + 1);
	else
	{
		ft_strncpy(dest + dstlen, src, size - dstlen - 1);
		dest[size - 1] = '\0';
	}
	return (dstlen + srclen);
}
