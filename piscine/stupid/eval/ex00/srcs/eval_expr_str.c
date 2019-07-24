/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:19:15 by hypark            #+#    #+#             */
/*   Updated: 2018/06/02 21:20:25 by hypark           ###   ########.fr       */
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

int			ft_check_char(char *c)
{
	if (*c == '(')
		return (3);
	else if (c[1] == ' ' &&
			(*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%'))
		return (2);
	else
		return (1);
}

void		ft_copy(char *copy, char *first, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		copy[i] = first[i];
		i++;
	}
	copy[i] = '\0';
}
