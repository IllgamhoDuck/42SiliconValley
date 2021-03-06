/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:01:34 by hypark            #+#    #+#             */
/*   Updated: 2019/08/02 01:40:46 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					valid_char(char c)
{
	return (c == '#' || c == '.' || c == '\n' || c == '\0');
}

char				**valid_place(char **m, t_map *c_m, int y, int x)
{
	int				i;
	int				j;

	i = 0;
	while (i < c_m->y_len)
	{
		j = 0;
		while (j < c_m->x_len)
		{
			if (m[y + i][x + j] != '.' && c_m->map[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (copy_map(m, c_m, y, x));
}

/*
**=============================================
** PIECE 1 & 2
**=============================================
** #### #... #### .... .... ....
** .... #... 1111 0000 0000 0000  NUMBER  61440
** .... #... #... #... #... #...
** .... #... 1000 1000 1000 1000  NUMBER  34952
**=============================================
** PIECE 3 & 4
**=============================================
** ##.. .#.. ##.. .##. .... ....
** .##. ##.. 1100 0110 0000 0000  NUMBER  50688
** .... #... .#.. ##.. #... ....
** .... .... 0100 1100 1000 0000  NUMBER  19584
**=============================================
** PIECE 5 & 6
**=============================================
** .##. #... .##. ##.. .... ....
** ##.. ##.. 0110 1100 0000 0000  NUMBER  27648
** .... .#.. #... ##.. .#.. ....
** .... .... 1000 1100 0100 0000  NUMBER  35904
**=============================================
** PIECE 7 & 8 & 9 & 10
**=============================================
** ###. #... ###. #... .... ....
** #... #... 1110 1000 0000 0000  NUMBER  59392
** .... ##.. #... #... ##.. ....
** .... .... 1000 1000 1100 0000  NUMBER  35008
** ..#. ##.. ..#. ###. .... ....
** ###. .#.. 0010 1110 0000 0000  NUMBER  11776
** .... .#.. ##.. .#.. .#.. ....
** .... .... 1100 0100 0100 0000  NUMBER  50240
** =============================================
** PIECE 11 & 12 & 13 & 14
** =============================================
** ###. ##.. ###. ..#. .... ....
** ..#. #... 1110 0010 0000 0000  NUMBER  57856
** .... #... ##.. #... #... ....
** .... .... 1100 1000 1000 0000  NUMBER  51328
** #... .#.. #... ###. .... ....
** ###. .#.. 1000 1110 0000 0000  NUMBER  36352
** .... ##.. .#.. .#.. ##.. ....
** .... .... 0100 0100 1100 0000  NUMBER  17600
** =============================================
** PIECE 15 & 16 & 17 & 18
** =============================================
** ###. .#.. ###. .#.. .... ....
** .#.. ##.. 1110 0100 0000 0000  NUMBER  58368
** .... .#.. .#.. ##.. .#.. ....
** .... .,.. 0100 1100 0100 0000  NUMBER  19520
** .#.. #... .#.. ###. .... ....
** ###. ##.. 0100 1110 0000 0000  NUMBER  19968
** .... #... #... ##.. #... ....
** .... .... 1000 1100 1000 0000  NUMBER  35968
** =============================================
** PIECE 19
** =============================================
** ##..      ##.. ##.. .... ....
** ##..      1100 1100 0000 0000  NUMBER  52224
** ....
** ....
*/

unsigned short		*compare_list(void)
{
	unsigned short	i;
	unsigned short	*cmp_list;

	i = 0;
	cmp_list = (unsigned short *)malloc(sizeof(unsigned short) * 19);
	cmp_list[i++] = 61440;
	cmp_list[i++] = 34952;
	cmp_list[i++] = 50688;
	cmp_list[i++] = 19584;
	cmp_list[i++] = 27648;
	cmp_list[i++] = 35904;
	cmp_list[i++] = 59392;
	cmp_list[i++] = 35008;
	cmp_list[i++] = 11776;
	cmp_list[i++] = 50240;
	cmp_list[i++] = 57856;
	cmp_list[i++] = 51328;
	cmp_list[i++] = 36352;
	cmp_list[i++] = 17600;
	cmp_list[i++] = 58368;
	cmp_list[i++] = 19520;
	cmp_list[i++] = 19968;
	cmp_list[i++] = 35968;
	cmp_list[i++] = 52224;
	return (cmp_list);
}

int					valid_piece(t_reader *r, t_input *input)
{
	unsigned short	cmp_num;
	unsigned short	*cmp_list;
	unsigned short	i;
	char			result;

	i = 0;
	result = 0;
	cmp_num = bit_transfer(r);
	cmp_list = compare_list();
	while (i < 19)
	{
		if (cmp_list[i] == cmp_num)
			result = i + 1;
		i++;
	}
	free(cmp_list);
	if (result == 0)
		return (0);
	input->piece = result;
	r->sharp_num = 0;
	r->dot_num = 0;
	return (1);
}

/*
** transfer the 4 numbers into 2bytes of bits
** example 0 5 10 15
**=============================================
** #...
** #...
** #...
** #...
** =============================================
** #... #... #... #...
** 1000 1000 1000 1000
** =============================================
** 34952
*/

unsigned short		bit_transfer(t_reader *r)
{
	unsigned short	result;
	unsigned short	tmp;
	unsigned short	move;
	int				i;

	result = 0;
	i = -1;
	while (++i < 4)
	{
		move = 15 - ((r->sharp[i] % 5) + 4 * (r->sharp[i] / 5));
		tmp = 0;
		tmp = tmp | 1;
		while (move)
		{
			tmp <<= 1;
			move--;
		}
		result |= tmp;
	}
	return (result);
}
