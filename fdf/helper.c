/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:41:06 by hypark            #+#    #+#             */
/*   Updated: 2019/08/07 02:47:50 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos				*position(t_fdf *fdf, int x, int y)
{
	t_pos			*pos;
	int				index;

	index = x + (y * fdf->map->width);
	if (!(pos = (t_pos *)ft_memalloc(sizeof(t_pose))))
		print_error("Memory allocating fail at t_pos");
	pos->x = x;
	pos->y = y;
	pos->z = fdf->map->position[index];
	pos->color = fdf->map->color[index];
	return (pos);
}

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
		return (0xFF0000);
	if (strcmp(str, "0xFF00") == 0)
		return (0x00FF00);
	if (strcmp(str, "0xFFFF") == 0)
		return (0xFFFF00);
	ft_putstr("color code is wrong : ");
	ft_putstr(str);
	print_error("\nThe color code is written wrong");
	return (0);
}
