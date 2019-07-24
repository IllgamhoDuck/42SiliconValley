/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:33:11 by hypark            #+#    #+#             */
/*   Updated: 2018/06/07 23:34:45 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void			base(int nb, int base)
{
	int			i;
	int			j;
	int			tmp;
	char		*r;
	
	i = 0;
	j = 1;
	tmp = nb;
	while (nb >= base)
	{
		nb /= base;
		i++;
	}
	i++;
	r = (char *)malloc(sizeof(char) * (i + 1));
	r[i] = '\0';
	while (j <= i)
	{
		r[i - j] = tmp % base + '0';
		tmp /= base;
		j++;
	}
	printf("%s", r);
	printf("\n");
}

unsigned char		reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				len;
	
	len = 8;
	result = 0;
	while (len--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	base(result, 2);

/*	
	result = 0;
	base(octet, 2);
	result += (octet & 1 << 7) >> 7;
	result += (octet & 1 << 6) >> 5;
	result += (octet & 1 << 5) >> 3;
	base(result, 2);
	result += (octet & 1 << 4) >> 1;
	result += (octet & 1 << 3) << 4;
	result += (octet & 1 << 2) << 4;
	result += (octet & 1 << 1) << 4;
	result += (octet & 1) << 4;
	base(result, 2);
	*/
	return (result);
}

int 			main(void)
{
	printf("%d", reverse_bits(38));
	return (0);
}
