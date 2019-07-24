/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:41:29 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 23:40:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

int			ft_strlen(char *c)
{
	int		i;

	i = 0;
	while (*c != '\0')
	{
		c++;
		i++;
	}
	return (i);
}

int			ft_strchar(char *str, char to_find)
{
	int		i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == to_find)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_check_base(char *base)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(base);
	if (!base || len <= 1)
		return (0);
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] <= 32 || base[i] >= 126)
			return (0);
		else if (ft_strchar(&base[i + 1], base[i]) == 1)
			return (0);
		i++;
	}
	return (len);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		result[1000];
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	base_len = ft_check_base(base);
	while (nbr >= base_len)
	{
		result[i] = nbr % base_len;
		nbr = nbr / base_len;
		i++;
	}
	result[i] = nbr;
	if (neg)
		result[i++] = '-';
	while (i >= 0)
		ft_putchar(base[result[i--]]);
}
