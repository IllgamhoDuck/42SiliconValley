/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:34:50 by hypark            #+#    #+#             */
/*   Updated: 2020/03/04 23:40:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void sinkIsland(int **map, int row, int col)
{
	if (map[row][col] == 0)
		return ;
	map[row][col] = 0;
	if (row - 1 >= 0)
		sinkIsland(map, row - 1, col);
	if (map[row + 1])
		sinkIsland(map, row + 1, col);
	if (col - 1 >= 0)
		sinkIsland(map, row, col - 1);
	if (map[row][col + 1] != -1)
		sinkIsland(map, row, col + 1);
}
