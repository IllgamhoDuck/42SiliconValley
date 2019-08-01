/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:08:50 by hypark            #+#    #+#             */
/*   Updated: 2019/08/01 03:29:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				free_list(t_tetris *t, t_input *input, int iter_num)
{
	if (iter_num == 1)
	{
		t->pieces[t->total - iter_num] = input->piece;
		t->pieces[t->total] = '\0';
		free(input);
		return ;
	}
	else
	{
		t->pieces[t->total - iter_num] = input->piece;
		free_list(t, input->next, iter_num - 1);
		free(input);
		return ;
	}
}
