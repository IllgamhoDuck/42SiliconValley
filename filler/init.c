/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:53:04 by hypark            #+#    #+#             */
/*   Updated: 2019/09/09 22:55:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

t_filler				*init_filler(void)
{
	t_filler			*filler;

	if (!(filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
		print_error("Memory allocation failed at t_filler\n");
	return (filler);
}
