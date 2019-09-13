/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:30:09 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 12:34:54 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int					main(void)
{
	t_filler		*filler;

	filler = init_filler();
	process_file(filler);
	free_filler(filler);
	return (0);
}
