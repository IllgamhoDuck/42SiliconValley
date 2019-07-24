/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:01:02 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 21:16:51 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				is_header_valid(t_map_info *map_info)
{
	if (map_info->height < 1)
		return (0);
	if (map_info->empty == map_info->obs)
		return (0);
	if (map_info->obs == map_info->full)
		return (0);
	if (map_info->full == map_info->empty)
		return (0);
	return (1);
}

int				read_header(t_reader *reader, t_map_info *map_info)
{
	int		line_count;
	t_u8	c;

	line_count = 0;
	while ((c = next_input(reader)))
	{
		if (c < '0' || c > '9')
			break ;
		line_count *= 10;
		line_count += c - '0';
	}
	if ((map_info->height = line_count) == 0 ||
		(map_info->empty = c) == 0 ||
		(map_info->obs = next_input(reader)) == 0 ||
		(map_info->full = next_input(reader)) == 0 ||
		(next_input(reader) != '\n'))
		return (-1);
	return (0);
}
