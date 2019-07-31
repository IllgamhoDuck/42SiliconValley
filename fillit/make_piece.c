/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:59:48 by hypark            #+#    #+#             */
/*   Updated: 2019/07/31 01:00:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_input				*init_input(void)
{
	t_input			*input;

	if (!(input = (t_input *)malloc(sizeof(t_input))))
		return (0);
	if (!(input->piece = (char *)malloc(17)))
		return (0);
	input->next = NULL;
	input->reader = NULL;
	return (input);
}

int					fill_input(t_reader *r, t_input *input)
{
	int				i;
	int				j;
	int				dot;
	int				sharp;
	char			c;

	i = 0;
	j = 0;
	dot = 0;
	sharp = 0;
	while (i < 20)
	{
		if (!(c = get_next_char(r)))
			return (0);
		c == '#' ? sharp++ : sharp + 0; 
		c == '.' ? dot++ : dot + 0; 
		if (i != 4 && i != 9 && i != 14 && i != 19) 
			input->piece[j++] = c;
		else
			if (c != '\n')
				return (0);
		i++;
	}
	input->piece[j] = '\0';
	return (sharp == 4 && dot == 12 ? 1 : 0);
}

int					fill_repeat(t_reader *r, t_input *input)
{
	char			c;
	t_input			*current;

	current = input;
	while (1)
	{
		c = get_next_char(r);
		if (c == '\0')
		{
			return (1);
		}
		else if (c == '\n')
		{
			current->next = init_input();
			current = current->next;
			if (!(fill_input(r, current)))
				return (0);
		}
		else
			return (0);
	}
}
