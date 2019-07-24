/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 22:43:34 by hypark            #+#    #+#             */
/*   Updated: 2018/05/28 22:43:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op_print.h"

int			ft_atoi(char *str)
{
	int		neg;
	int		result;

	neg = 1;
	result = 0;
	if (!(*str >= '0' && *str <= '9') && (*str != '+') && (*str != '-'))
		return (0);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * neg);
}

int			ft_special_op(char op, int first, int second, int *error)
{
	if (op == '/')
	{
		if (second == 0)
		{
			*error = 1;
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		return (first / second);
	}
	if (op == '%')
	{
		if (second == 0)
		{
			*error = 1;
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		return (first % second);
	}
	return (0);
}

int			ft_operator(char *op, int first, int second, int *error)
{
	int		i;

	i = 0;
	while (op[i])
		i++;
	if (i == 1)
	{
		if (*op == '+')
			return (first + second);
		else if (*op == '-')
			return (first - second);
		else if (*op == '*')
			return (first * second);
		else if (*op == '/')
			return (ft_special_op('/', first, second, error));
		else if (*op == '%')
			return (ft_special_op('%', first, second, error));
		else
			return (0);
	}
	else
		return (0);
}

int			main(int argc, char **argv)
{
	int		first_num;
	int		second_num;
	int		result;
	int		error;

	first_num = 0;
	second_num = 0;
	result = 0;
	error = 0;
	if (argc == 4)
	{
		first_num = ft_atoi(argv[1]);
		second_num = ft_atoi(argv[3]);
		result = ft_operator(argv[2], first_num, second_num, &error);
		if (error == 0)
		{
			ft_putnbr(result);
			ft_putstr("\n");
		}
	}
	return (0);
}
