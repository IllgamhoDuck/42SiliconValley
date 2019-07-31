/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:15:51 by hypark            #+#    #+#             */
/*   Updated: 2018/06/07 20:58:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int        ft_countbase(long value, int base)
{
    int        count;

    count = 0;
    while (value >= base)
    {
        value /= base;
        count++;
    }
    return (count + 1);
}

char   		 convert(long value, int base)
{
    int thing;
    thing = (value % base);
    if (thing >= 10)
        return ('A' + (thing % 10));
    else
        return (thing + '0');
}

char			*ft_itoa_base(int value, int base)
{
    char		*str;
    int			count;
    int			i;
    int			neg;
	long		result;

    neg = 1;
    if (value < 0)
    {
        neg = -1;
        result = -(long)value;
    }
	else
		result = (long)value;
    count = ft_countbase(result, base);
    if (base == 10 && neg < 0)
        count++;
    str = (char*)malloc(sizeof(char) * (count + 1));
    i = 1;
    str[count] = '\0';
    while (i <= count)
    {
        str[count - i] = convert(result, base);
        result /= base;
        i++;
    }
    if (base == 10 && neg < 0)
        str[0] = '-';

    return (str);
}

void			ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int				main(void)
{
	char		*r;

	r = ft_itoa_base(-2147483648, 10);
	ft_putstr(r);
	ft_putstr("\n");
	r = ft_itoa_base(2147483647, 10);
	ft_putstr(r);
	ft_putstr("\n");
	r = ft_itoa_base(-2147483648, 16);
	ft_putstr(r);
	ft_putstr("\n");
	r = ft_itoa_base(-2147483648, 2);
	ft_putstr(r);
	ft_putstr("\n");
	return (0);
}
