/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:20:32 by hypark            #+#    #+#             */
/*   Updated: 2018/06/07 19:45:10 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

char			*ft_itoa(int nbr)
{
	char		*r;
	int			sign;
	int			len;
	int			tmp;
	int			i;

	i = 0;
	r = 0;
	len = 0;
	sign = 1;
	if (nbr == -2147483648)
	{
		r = "-2147483648";
		return (r);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		sign *= -1;
	}
	tmp = nbr;
	while (nbr /= 10)
		len++;
	len++;
	nbr = tmp;
	if (sign == -1)
		len++;
	r = (char *)malloc(sizeof(char) * (len + 1));
	printf("len : %d\n", len);
	if (sign == -1)
		r[i++] = '-';
	tmp = i;
	i = len - 1;
	while (i >= tmp)
	{
		r[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	r[len] = '\0';
	return (r);
}


int				main(void)
{
	char		*result;

	result = ft_itoa(-2147483648);
	ft_putstr(result);
	printf("\n");
	result = ft_itoa(2147483648);
	ft_putstr(result);
	printf("\n");
	result = ft_itoa(2147483647);
	ft_putstr(result);	
	printf("\n");
	result = ft_itoa(483648);
	ft_putstr(result);
	printf("\n");
	result = ft_itoa(-23648);
	ft_putstr(result);
	printf("\n");
	result = ft_itoa(0);
	ft_putstr(result);
	printf("\n");
	return (0);
}
