/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:38:53 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 12:46:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			power_ten(int iter_num)
{
	int		i;
	int		total;

	i = 1;
	total = 1;
	while (i <= iter_num)
	{
		total *= 10;
		i++;
	}
	return (total);
}

int			ft_check_char(char c)
{
	if (c == ' ' || c == '\'' || c == '\"' || c == '/' || c == '\\')
		return (0);
	else if (c == '\n' || c == '\r' || c == '\t' || c == '\b')
		return (0);
	else if (c == '\f' || c == '\v' || c == '\0' || c == '$')
		return (0);
	else
		return (1);
}

int			cal_digit(char **c, int *sign)
{
	int		digit;
	int		i;

	digit = 0;
	i = 0;
	while (ft_check_char(c[0][0]) == 0)
		c[0]++;
	if (c[0][0] == '-')
	{
		c[0]++;
		*sign = -1;
	}
	else if (c[0][0] == '+')
	{
		c[0]++;
		*sign = 1;
	}
	while (c[0][i] >= '0' && c[0][i] <= '9')
	{
		digit++;
		i++;
	}
	return (digit);
}

int			ft_atoi(char *str)
{
	int		digit;
	int		total;
	int		sign;
	int		i;

	total = 0;
	sign = 1;
	if (!str)
		return (0);
	digit = cal_digit(&str, &sign);
	if (digit == 0)
		return (0);
	i = 0;
	total = 0;
	while (i < digit)
	{
		total += ((int)(str[i] - '0') * power_ten(digit - (i + 1)));
		i++;
	}
	total *= sign;
	return (total);
}
