/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 00:11:17 by hypark            #+#    #+#             */
/*   Updated: 2018/05/27 14:13:53 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Print out sudoku in stardard output*/
void		ft_print_sudoku(char **sudoku)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(sudoku[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/* Find the empty block to fill in. */
int			ft_find_empty_block(char **sudoku, int *row, int *col)
{
	while (*row < 9)
	{
		while (*col < 9)
		{
			/* If we find the empty block return 0.
			 * And this means the sudoku is not over */
			if (sudoku[*row][*col] == '.')
				return (0);
			*col += 1;
		}
		*col = 0;
		*row += 1;
	}
	/* We checked every block but there was no empty block. 
	 * Great! It means we finished the sudoku!!! Lets return 1!*/
	return (1);
}

int			ft_check_available(char **sudoku, int row, int col, int num)
{
	int		rowstart = (row / 3) * 3;
	int		colstart = (col / 3) * 3;
	int		i;

	i = 0;
	while (i < 9)
	{
		/* Check the column */
		if (sudoku[row][i] == (num + '0'))
			return (0);
		/* Check the row */
		else if (sudoku[i][col] == (num + '0'))
			return (0);
		/* Check the grid. This is a tricky one. Look carefully */ 
		else if (sudoku[rowstart + (i % 3)][colstart + (i / 3)] == (num + '0'))
			return (0);
		i++;
	}
	/* If there is no matching number at row, column, grid then
	 * it means we can use this. So return 1 */
	return (1);
}

/* Use this when we are making a copy of a sudoku 2dim array */
void		ft_copy(char **dest, char **copy)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			dest[i][j] = copy[i][j];
			j++;
		}
		i++;
	}
}

/* Use this when we are making a new memory space at HEAP
 * with malloc and copy to it */
char		**ft_copy_malloc(char **copy)
{
	char	**next_copy;
	int		i;

	i = 0;
	next_copy = (char **)malloc(sizeof(char *) * 9);
	while (i < 9)
	{
		next_copy[i] = (char *)malloc(sizeof(char) * 9);
		i++;
	}
	ft_copy(next_copy, copy);
	return (next_copy);
}

int			ft_sudoku_solver(char **origin, char **copy, int row, int col)
{
	int		number;
	char	**next_copy;
	
	number = 1;
	/* Find the empty block to fill. We will search the grid horizontally and
	 * and next vertically. We send the memory address of row & column so
	 * it will automatically change our address */ 
	if (ft_find_empty_block(copy, &row, &col))
	{
		/* At ft_find_empty_block function we search for empty block but also
		 * check is this sudoku is completed. If sudoku is completed than
		 * 1 will be return and end at here. Its time to move the answer
		 * at copy to the origin sudoku fill!*/
		ft_copy(origin, copy);
		/* Return 1 to know the world that sudoku has conquered! */
		return (1);
	}

	/* Copy the copy file using malloc file*/
	next_copy = ft_copy_malloc(copy);

	/* If we find the empty block we are going to fill this block with number
	 * from 1 to 9.*/
	while (number < 10)
	{
		/* Check is this number available to this block. In other words
		 * is this number following the rules? 
		 * If that so lets start the recursion! */
		if (ft_check_available(next_copy, row, col, number))
		{
			/* Put the number to the next copy */
			next_copy[row][col] = number + '0';
			/* !!!!!FOR WATCH!!!!! */
			ft_putchar('\n');
			ft_print_sudoku(next_copy);
			ft_putchar('\n');
			/* We send the sudoku to the next recursion step! Better luck!
			 * If the sudoku solver solved the solved the sudoku it will
			 * send 1 to us and we will send it up again! */
			if (ft_sudoku_solver(origin, next_copy, row, col))
			{
				free(next_copy);
				return (1);
			}
			/* If we are passing this step it means attempt failed.
			 * Its time to try another number */
			next_copy[row][col] = '.';
		}
		number++;
	}
	/* If we can do nothing at here it means it failed. So return 0 */
	free(next_copy);
	return (0);
}


/* Use this only when copying command line argument sudoku 2dim array */
void		ft_copy_main(char **dest, char **copy)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			dest[i][j] = copy[i + 1][j];
			j++;
		}
		i++;
	}
}

/* Use this only when we are moving the value from command line argument
 * to the new memory space at HEAP with malloc and copy to it */
char		**ft_malloc_copy_main(char **main_arg)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * 9);
	while (i < 9)
	{
		copy[i] = (char *)malloc(sizeof(char) * 9);
		i++;
	}
	ft_copy_main(copy, main_arg);
	return (copy);
}

int			main(int argc, char *argv[])
{
	char	**copy;
	char	**origin;

	origin = 0;
	/* Only do this when the argument number is 9 */
	if (argc == 10)
	{
		origin = ft_malloc_copy_main(argv);
		copy = origin;
		ft_print_sudoku(origin);
		/* This might be weire but original sudoku and copy sudoku
		 * is same at the first time */
		if(ft_sudoku_solver(origin, copy, 0, 0))
			ft_print_sudoku(origin);
		else
		{
			/* Failed! Fail message expected */
			return (0);
		}
	}
	free(origin);
	return (0);
}
