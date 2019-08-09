/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 03:14:42 by hypark            #+#    #+#             */
/*   Updated: 2019/08/06 03:20:16 by hypark           ###   ########.fr       */
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
