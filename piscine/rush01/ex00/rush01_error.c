/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:39:23 by hypark            #+#    #+#             */
/*   Updated: 2018/05/27 20:39:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_check_input(char **argv)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			c = argv[row + 1][col];
			if (!((c >= '1' && c <= '9') || (c == '.')))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int			ft_check_len(char **argv)
{
	int		row;
	int		col;
	int		row_len;
	int		col_len;

	row = 0;
	row_len = 0;
	while (argv[row + 1])
	{
		row_len++;
		col = 0;
		col_len = 0;
		while (argv[row + 1][col])
		{
			col_len++;
			col++;
		}
		if (col_len != 9)
			return (1);
		row++;
	}
	if (row_len != 9)
		return (1);
	return (0);
}
