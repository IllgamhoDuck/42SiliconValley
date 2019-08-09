/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:41:06 by hypark            #+#    #+#             */
/*   Updated: 2019/08/09 02:36:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			what_num(char c)
{
	char			*hex;
	int				num;

	hex = "0123456789ABCDEF";
	c = ft_toupper(c);
	num = 0;
	while (num < 16)
	{
		if (hex[num] == c)
			return (num);
		num++;
	}
	print_error("Color number has a wrong number. only 0~F is valid");
	return (0);
}

static void			string_upper(char *str)
{
	str += 2;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

t_pos				*make_pos(int x, int y, int z, int color)
{
	t_pos			*pos;

	if (!(pos = (t_pos *)ft_memalloc(sizeof(t_pos))))
		print_error("Memory allocating fail at t_pos");
	pos->x = x;
	pos->y = y;
	pos->z = z;
	pos->color = color;
	return (pos);
}

int					ft_abs(int number)
{
	if (number == -2147483648)
		print_error("-2147483648 is not supported number at ft_abs");
	else if (number < 0)
		return (-1 * number);
	else if (number >= 0)
		return (number);
	return (0);
}

int					atoi_h(char *str)
{
	unsigned long	result;
	int				i;

	result = 0;
	i = -1;
	if (ft_strlen(str) == 8)
	{
		i += 2;
		while (str[++i])
			result = result * 16 + what_num(str[i]);
		return (result);
	}
	string_upper(str);
	if (strcmp(str, "0x0") == 0)
		return (0x000000);
	if (strcmp(str, "0xFF") == 0)
		return (0x0000FF);
	if (strcmp(str, "0xFF00") == 0)
		return (0x00FF00);
	if (strcmp(str, "0xFFFF") == 0)
		return (0xFFFF00);
	ft_putstr("color code is wrong : ");
	ft_putstr(str);
	print_error("\nThe color code is written wrong");
	return (0);
}
