/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:33:33 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/06/03 23:34:15 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*rush0(int columns, int rows)
{
	int row;
	int col;
	char 	*arr = (char *)malloc(sizeof(arr) * (columns * rows + rows));
	int 	count;

	count = 0;
	if (columns >= 0 && rows >= 0)
	{
		row = 0;
		while (row < rows)
		{
			col = 0;
			while (col <= columns)
			{
				arr[count] = get_rush0(columns, rows, col, row);
				count++;
				col++;
			}
			row++;
		}
	}
	return (arr);
}

char	*rush1(int columns, int rows)
{
	int row;
	int col;
	char 	*arr = (char *)malloc(sizeof(arr) * (columns * rows + rows));
	int 	count;

	count = 0;
	if (columns >= 0 && rows >= 0)
	{
		row = 0;
		while (row < rows)
		{
			col = 0;
			while (col <= columns)
			{
				arr[count] = get_rush1(columns, rows, col, row);
				count++;
				col++;
			}
			row++;
		}
	}
	return (arr);
}

char	*rush2(int columns, int rows)
{
	int row;
	int col;
	char 	*arr = (char *)malloc(sizeof(arr) * (columns * rows + rows));
	int 	count;

	count = 0;
	if (columns >= 0 && rows >= 0)
	{
		row = 0;
		while (row < rows)
		{
			col = 0;
			while (col <= columns)
			{
				arr[count] = get_rush2(columns, rows, col, row);
				count++;
				col++;
			}
			row++;
		}
	}
	return (arr);
}

char	*rush3(int columns, int rows)
{
	int row;
	int col;
	char 	*arr = (char *)malloc(sizeof(arr) * (columns * rows + rows));
	int 	count;

	count = 0;
	if (columns >= 0 && rows >= 0)
	{
		row = 0;
		while (row < rows)
		{
			col = 0;
			while (col <= columns)
			{
				arr[count] = get_rush3(columns, rows, col, row);
				count++;
				col++;
			}
			row++;
		}
	}
	return (arr);
}

char	*rush4(int columns, int rows)
{
	int row;
	int col;
	char 	*arr = (char *)malloc(sizeof(arr) * (columns * rows + rows));
	int 	count;

	count = 0;
	if (columns >= 0 && rows >= 0)
	{
		row = 0;
		while (row < rows)
		{
			col = 0;
			while (col <= columns)
			{
				arr[count] = get_rush4(columns, rows, col, row);
				count++;
				col++;
			}
			row++;
		}
	}
	return (arr);
}
