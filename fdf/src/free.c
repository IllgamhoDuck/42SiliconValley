/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 03:14:42 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 22:18:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				free_reader(t_reader *reader)
{
	if (reader->next == NULL)
		free(reader);
	else
	{
		free_reader(reader->next);
		free(reader);
	}
}

void				free_pos(t_pos *p1, t_pos *p2, t_pos *p3)
{
	free(p1);
	free(p2);
	free(p3);
}

void				free_str(char **str)
{
	int				i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}

void				free_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->map)
		{
			if (fdf->map->position)
				free(fdf->map->position);
			if (fdf->map->color)
				free(fdf->map->color);
			free(fdf->map);
		}
		if (fdf->camera)
			free(fdf->camera);
		if (fdf->mouse)
			free(fdf->mouse);
		free(fdf);
	}
}
