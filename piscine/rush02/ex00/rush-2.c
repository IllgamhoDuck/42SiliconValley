/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-2-hypark.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:05:45 by hypark            #+#    #+#             */
/*   Updated: 2018/06/03 23:38:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void			ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int				ft_row_len(char *str)
{
	int			row;

	row = 0;
	if (!(*str))
		return (0);
	while (*str)
	{
		if (*str == '\n')
			row++;
		str++;
	}
	if (*(str - 1) != '\n')
		row++;
	return (row);
}

int				*ft_col_arr(char *str, int row)
{
	char		*start;
	int			*col_arr;
	int			col;
	int			i;
	
	col = 0;
	i = 0;
	start = str;
	col_arr = (int *)malloc(sizeof(int) * row);
	while (*str)
	{
		col++;
		if (*str == '\n')
		{
			col_arr[i] = col;
			start = str + 1;
			i++;
			col = 0;
		}
		str++;
	}
	if (*start)
		col_arr[i] = col;
	return (col_arr);
}

int				*ft_str_array(char *str, int *row)
{
	int			col;
	int			*col_arr;

	*row = ft_row_len(str);
	col_arr = ft_col_arr(str, *row);
	return (col_arr);
}

int				ft_check_same(int *arr, int size)
{
	int			i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] != arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char			get_rush0(int x, int y, int i, int j)
{
	if (i == 0 && (j == 0 || j == y - 1))
		return ('o');
	else if ((i == x - 1) && (j == 0 || j == y - 1))
		return ('o');
	else if (i == x)
		return ('\n');
	else if (i == 0 || col == x - 1)
		return ('|');
	else if (j == 0 || j == y - 1)
		return ('-');
	else if ((i > 0 && col < x - 1) && (j > 0 && j < y - 1))
		return (' ');
	return (0);
}

char			*rush0(int columns, int rows)
{
	int			row;
	int			col;
	char 		*arr = (char *)malloc(sizeof(arr) * (columns * rows + rows));
	int		 	count;

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

char	get_rush1(int x, int y, int i, int j)
{
	if ((i == 0 && j == 0) || (i != 0 && j != 0 && i == x - 1 && j == y - 1))
		ft_putchar('/');
	else if ((i == 0 && j == y - 1) || (i == x - 1 && j == 0))
		ft_putchar('\\');
	else if (j == y)
		ft_putchar('\n');
	else if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
	return (0);
}

char			*rush1(int columns, int rows)
{
	int			row;
	int 		col;
	char 		*arr = (char *)malloc(sizeof(arr) * (columns * rows + rows));
	int 		count;

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

char	get_rush2(int columns, int rows, int col, int row)
{
	if ((col == 0 || col == cols - 1) && row == 0)
		return ('A');
	else if ((col == 0 || col == cols - 1) && row == rows - 1)
		return ('C');
	else if (col == columns)
		return ('\n');
	else if ((col == 0 || col == columns - 1 || row == 0 || row == rows - 1))
		return ('B');
	else if ((col > 0 && col < columns - 1) && (row > 0 && row < rows - 1))
		return (' ');
	return (0);
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

char	get_rush4(int columns, int rows, int col, int row)
{
	if ((i == 0 && j == 0) || (i != 0 && j != 0 && i == x - 1 && j == y - 1))
		ft_putchar('A');
	else if ((i == 0 && j == y - 1) || (i == x - 1&& j == 0))
		ft_putchar('B');
	else if (j == y)
		ft_putchar('\n');
	else if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
		ft_putchar('C');
	else
		ft_putchar(' ');
	return (0);
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

int				ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void			ft_print(int col, int row, int r, int rush)
{
	if (r == 0)
	{
		ft_putstr("[rush-0");
		ft_putnbr(rush);
		ft_putstr("] [");
		ft_putnbr(row);
		ft_putstr("] [");
		ft_putnbr(col);
		ft_putstr("]");
	}
}

void			ft_rush0(char *str, int col, int row, int or)
{
	char		*rush;
	int			result;

	rush = rush0(col, row);
	result = ft_strcmp(str, rush);
	ft_print(col, row, result, 0);
	if (result == 0 && or == 0)
		or = 1;
	ft_rush1(str, col, row, or);
}

void			ft_rush1(char *str, int col, int row, int or)
{
	char		*rush;
	int			result;

	rush = rush1(col, row);
	result = ft_strcmp(str, rush);
	ft_print(col, row, result, 3);
	if (result == 0 && or == 1)
		ft_putstr(" || ");
	else if (result == 0 && or == 0)
		or = 1;
	ft_rush2(str, col, row, or);
}

void			ft_rush2(char *str, int col, int row, int or)
{
	char		*rush;
	int			result;

	rush = rush2(col, row);
	result = ft_strcmp(str, rush);
	ft_print(col, row, result, 3);
	if (result == 0 && or == 1)
		ft_putstr(" || ");
	else if (result == 0 && or == 0)
		or = 1;
	ft_rush3(str, col, row, or);
}

void			ft_rush3(char *str, int col, int row, int or)
{
	char		*rush;
	int			result;

	rush = rush3(col, row);
	result = ft_strcmp(str, rush);
	ft_print(col, row, result, 3);
	if (result == 0 && or == 1)
		ft_putstr(" || ");
	else if (result == 0 && or == 0)
		or = 1;
	ft_rush4(str, col, row, or);
}

void			ft_rush4(char *str, int col, int row, int or)
{
	rush = rush4(col, row);
	result = ft_strcmp(str, rush);
	ft_print(col, row, result, 3);
	if (result == 0 && or == 1)
		ft_putstr(" || ");
	if (or == 0 && result != 0)
		ft_putstr("error!");
}

void			ft_row_col(char *str)
{
	int			same;
	int			row;
	int			*col_arr;
	int			or;

	or = 0;
	col_arr = ft_str_array(str, &row);
	same = ft_check_same(col_arr, row);
	if (!same)
	{
		ft_putstr("error!");
		return ;
	}
	ft_rush0(str, col_arr[0] - 1, row, or);
}

char	*increase_n_transfer(char *str, int *size)
{
	int		i;
	int		new_size;
	char	*temp;

	i = 0;
	new_size = *size * 2;
	temp = malloc(sizeof(*str) * new_size);
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	*size = new_size;
	free(str);
	return (temp);
}

char	*input_acquire(void)
{
	char	buff;
	int		rd;
	char	*array;
	int		byte_c;
	int		size;

	size = 512;
	byte_c = 0;
	array = malloc(sizeof(*array) * size);
	rd = 1;
	while (rd != 0)
	{
		rd = read(0, &buff, 1);
		if (rd != 0)
		{
			if (byte_c == size - 2)
			{
				array = increase_n_transfer(array, &size);
			}
			array[byte_c] = buff;
			array[byte_c + 1] = '\0';
			byte_c++;
		}
	}
	return (array);
}

int				main(void)
{
	char		*buf;
	
	buff = input_acquire();
	ft_row_col(buf);
	return (0);
}
