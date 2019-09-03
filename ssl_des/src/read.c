/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:04:17 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 00:47:16 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

static char			get_next_char(t_reader *r)
{
	if (r->i < r->len)
		return (r->buff[r->i++]);
	if ((r->len = read(r->fd, r->buff, BUFF_SIZE_SSL)) < 0)
		p_error("Error occur while reading the file");
	if (r->len == 0)
		return (0);
	r->i = 0;
	return (r->buff[r->i++]);
}

static void			fill_list(t_reader *r, t_c_list **c_list, uint32_t *len)
{
	t_c_list		*current;
	char			c;

	current = NULL;
	while ((c = get_next_char(r)))
	{
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
}

static char			*compress_data(t_c_list *c_list, uint32_t len)
{
	char			*result;
	uint32_t		i;

	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		malloc_error("compress_data - char *result");
	i = 0;
	while (i < len)
	{
		result[i++] = c_list->c;
		c_list = c_list->next;
	}
	result[i] = '\0';
	return (result);
}

char				*read_file(int16_t fd)
{
	t_reader		*r;
	t_c_list		*c_list;
	char			*result;
	uint32_t		len;

	len = 0;
	!(r = init_reader(fd)) ? malloc_error("t_reader") : 0;
	fill_list(r, &c_list, &len);
	result = compress_data(c_list, len);
	free_reader(r);
	free_c_list(c_list);
	return (result);
}
