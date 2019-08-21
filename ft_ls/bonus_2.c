/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 03:10:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 03:27:28 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void				multi_col_color(t_file *f, uint16_t len)
{
	if (f->mode == 'd')
		ft_printf("\033[1;36m%-*s{eos}", len, f->name);
	else if (f->mode == 'l')
		ft_printf("{magenta}%-*s{eos}", len, f->name);
	else if (f->mode == '-')
	{
		if (f->permission[2] == 'x' || f->permission[5] == 'x' || \
				f->permission[8] == 'x')
			ft_printf("{red}%-*s{eos}", len, f->name);
		else
			ft_printf("%-*s", len, f->name);
	}
	else if (f->mode == 'c' || f->mode == 'b')
		ft_printf("\033[1;33m%-*s{eos}", len, f->name);
	else
		ft_printf("%-*s", len, f->name);
}
