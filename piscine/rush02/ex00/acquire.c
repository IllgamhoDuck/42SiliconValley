/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:35:58 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/06/03 23:36:18 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

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
