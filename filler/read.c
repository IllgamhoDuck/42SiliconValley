/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:36:00 by hypark            #+#    #+#             */
/*   Updated: 2019/09/09 23:12:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <fcntl.h>

static void				write_file(char *f, char *content, uint32_t len)
{
	int32_t				fd;

	if ((fd = open(f, (O_RDWR | O_CREAT | O_TRUNC), \
				(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))) < 0)
		print_error("Failed to open the file to write\n");
	write(fd, content, len);
	close(fd);
}

/*
** $$$ exec p1 : [../hypark.filler]
** Plateau 15 17:
*/

/*
** Read the input from standard input and return the necessary information
*/

static void				read_map(t_filler *filler)
{
	char				*line;
	char				*map;
	char				*temp;
	int32_t				i;

	i = -1;
	map = NULL;
	while (++i < 15)//filler->y)
	{
		get_next_line(0, &line);
		if (map == NULL)
			map = line;
		else
		{
			temp = map;
			map = ft_strjoin(map, line);
			free(temp);
		}
		free(line);
	}
	write_file("duck", map, ft_strlen(map));
}

void					process_file(t_filler *filler)
{
	char				*line;
	char				**info;
	
	get_next_line(0, &line);
	info = ft_strsplit(line, ' ');
	free(line);
	free(info);
	filler->player = ft_strcmp(info[2], "p1") ? 1 : 2;
	get_next_line(0, &line);
	info = ft_strsplit(line, ' ');
	filler->y = ft_atoi(info[0]);
	filler->x = ft_atoi(info[1]);
	free(line);
	free(info);
	read_map(filler);
}
