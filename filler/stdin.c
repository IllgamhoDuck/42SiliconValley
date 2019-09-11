/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 03:37:50 by hypark            #+#    #+#             */
/*   Updated: 2019/09/11 04:13:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <fcntl.h>

int g_finish = 0;

static char			get_next_char(t_reader *r)
{
	if (r->i < r->len)
		return (r->buff[r->i++]);
	if (g_finish == 1)
		return (0);
	if ((r->len = read(r->fd, r->buff, BUFF_SIZE_FILLER)) < 0)
		return (-1);
	g_finish = 1;
	if (r->len == 0)
		return (0);
	r->i = 0;
	return (r->buff[r->i++]);
}

static int			fill_list(t_reader *r, t_c_list **c_list, uint32_t *len)
{
	t_c_list		*current;
	char			c;

	current = NULL;
	while ((c = get_next_char(r)))
	{
		if (c == -1)
			return (0);
		if (current == NULL)
		{
			current = init_c_list(c);
			*c_list = current;
		}
		else
		{
			current->next = init_c_list(c);
			current = current->next;
		}
		(*len)++;
	}
	if (current == NULL)
		*c_list = NULL;
	return (1);
}

static char			*compress_data(t_c_list *c_list, uint32_t len)
{
	char			*result;
	uint32_t		i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		result[i++] = c_list->c;
		c_list = c_list->next;
	}
	result[i - 1] = '\0';
	result[i] = '\0';
	return (result);
}

static char			*read_file_stdin(int16_t fd)
{
	t_reader		*r;
	t_c_list		*c_list;
	char			*result;
	uint32_t		len;

	len = 0;
	g_finish = 0;
	r = init_reader(fd);
	fill_list(r, &c_list, &len);
	result = len == 0 ? NULL : compress_data(c_list, len);
	free_reader(r);
	free_c_list(c_list);
	return (result);
}

static void				write_file(char *f, char *content, uint32_t len)
{
	int32_t				fd;

	if ((fd = open(f, (O_RDWR | O_CREAT | O_TRUNC), \
				(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))) < 0)
		print_error("Failed to open the file to write");
	write(fd, content, len);
	close(fd);
}

char				**stdin_filler(void)
{
	char			*input;
	char			**line;

	input = NULL;
	input = read_file_stdin(0);
	if (input == NULL || input[0] == '\0')
	{
		input == NULL ? exit(1) : free(input);
		return (NULL);
	}
	write_file("duck", input, ft_strlen(input));
	line = ft_strsplit(input, '\n');
	free(input);
	return (line);
}
