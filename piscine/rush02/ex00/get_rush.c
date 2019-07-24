/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:31:58 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/06/03 23:33:06 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	get_rush0(int columns, int rows, int col, int row)
{
	if (col == 0 && (row == 0 || row == rows - 1))
		return ('A');
	else if ((col == columns - 1) && (row == 0 || row == rows - 1))
		return ('C');
	else if (col == columns)
		return ('\n');
	else if ((col == 0 || col == columns - 1 || row == 0 || row == rows - 1))
		return ('B');
	else if ((col > 0 && col < columns - 1) && (row > 0 && row < rows - 1))
		return (' ');
	return (0);
}

char	get_rush1(int columns, int rows, int col, int row)
{
	if (col == 0 && (row == 0 || row == rows - 1))
		return ('A');
	else if ((col == columns - 1) && (row == 0 || row == rows - 1))
		return ('C');
	else if (col == columns)
		return ('\n');
	else if ((col == 0 || col == columns - 1 || row == 0 || row == rows - 1))
		return ('B');
	else if ((col > 0 && col < columns - 1) && (row > 0 && row < rows - 1))
		return (' ');
	return (0);
}

char	get_rush2(int columns, int rows, int col, int row)
{
	if (col == 0 && (row == 0 || row == rows - 1))
		return ('A');
	else if ((col == columns - 1) && (row == 0 || row == rows - 1))
		return ('C');
	else if (col == columns)
		return ('\n');
	else if ((col == 0 || col == columns - 1 || row == 0 || row == rows - 1))
		return ('B');
	else if ((col > 0 && col < columns - 1) && (row > 0 && row < rows - 1))
		return (' ');
	return (0);
}

char	get_rush3(int columns, int rows, int col, int row)
{
	if (col == 0 && (row == 0 || row == rows - 1))
		return ('A');
	else if ((col == columns - 1) && (row == 0 || row == rows - 1))
		return ('C');
	else if (col == columns)
		return ('\n');
	else if ((col == 0 || col == columns - 1 || row == 0 || row == rows - 1))
		return ('B');
	else if ((col > 0 && col < columns - 1) && (row > 0 && row < rows - 1))
		return (' ');
	return (0);
}

char	get_rush4(int columns, int rows, int col, int row)
{
	if (col == 0 && (row == 0 || row == rows - 1))
		return ('A');
	else if ((col == columns - 1) && (row == 0 || row == rows - 1))
		return ('C');
	else if (col == columns)
		return ('\n');
	else if ((col == 0 || col == columns - 1 || row == 0 || row == rows - 1))
		return ('B');
	else if ((col > 0 && col < columns - 1) && (row > 0 && row < rows - 1))
		return (' ');
	return (0);
}
