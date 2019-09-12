/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:30:09 by hypark            #+#    #+#             */
/*   Updated: 2019/09/12 13:21:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <fcntl.h>

int					main(void)
{
	t_filler		*filler;

	while (1)
	{
		filler_error("staring filler!=============");
		filler = init_filler();
		process_file(filler);
		filler_error("==============ending filler!");
	}
	return (0);
}
