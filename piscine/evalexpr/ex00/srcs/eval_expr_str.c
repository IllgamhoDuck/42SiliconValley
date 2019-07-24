/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:19:15 by hypark            #+#    #+#             */
/*   Updated: 2018/06/03 20:08:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(char **str)
{
	int		neg;
	int		result;

	neg = 1;
	result = 0;
	if (!(**str >= '0' && **str <= '9') && (**str != '+') && (**str != '-'))
		return (0);
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		neg *= -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	(*str)--;
	return (result * neg);
}

int			ft_is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int			ft_sign(char c)
{
	return (c == '+' || c == '-');
}

int			ft_op_check(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int			ft_check_char(char *c)
{
	if (*c == '(')
		return (3);
	else if (ft_is_num(*c))
		return (1);
	else if (!(*(c - 1)) && ft_sign(*c) && (*(c + 1) == '('))
		return (4);
	else if (ft_op_check(*(c - 1)) && ft_sign(*c) && (*(c + 1) == '('))
		return (4);
	else if (ft_sign(*c) && ft_is_num(*(c + 1)) && (*(c - 1) == '('))
		return (1);
	else if (ft_sign(*c) && ft_is_num(*(c + 1)) && (ft_op_check(*(c - 1))))
		return (1);
	else if (ft_sign(*c) && ft_is_num(*(c + 1)) && !*(c - 1))
		return (1);
	else
		return (2);
}
