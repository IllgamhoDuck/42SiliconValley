/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:53:04 by hypark            #+#    #+#             */
/*   Updated: 2019/09/12 22:25:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

t_filler				*init_filler(void)
{
	t_filler			*filler;

	if (!(filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
		print_error("Memory allocation failed at t_filler\n");
	filler->enemy_score = INT_MAX;
	return (filler);
}

t_reader			*init_reader(uint16_t fd)
{
	t_reader		*r;

	if (!(r = (t_reader *)malloc(sizeof(t_reader))))
		return (0);
	if (!(r->buff = (char *)malloc(sizeof(char) * BUFF_SIZE_FILLER)))
	{
		free(r);
		return (0);
	}
	r->i = 0;
	r->len = 0;
	r->fd = fd;
	return (r);
}

t_c_list			*init_c_list(char c)
{
	t_c_list		*list;

	if (!(list = (t_c_list *)malloc(sizeof(t_c_list))))
		print_error("t_c_list");
	list->c = c;
	list->next = NULL;
	return (list);
}
