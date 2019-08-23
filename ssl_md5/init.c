/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:07:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/23 12:01:59 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_reader			*init_reader(uint16_t fd)
{
	t_reader		*r;

	if (!(r = (t_reader *)malloc(sizeof(t_reader))))
		return (0);
	if (!(r->buff = (char *)malloc(sizeof(char) * BUFF_SIZE_SSL)))
	{
		free(r);
		return (0);
	}
	r->i = 0;
	r->len = 0;
	r->fd = fd;
	return (r);
}

t_c_list			*init_c_list(char c)
{
	t_c_list		*list;

	if (!(list = (t_c_list *)malloc(sizeof(t_c_list))))
		malloc_error("t_c_list");
	list->c = c;
	list->next = NULL;
	return (list);
}

t_ssl				*init_ssl(void)
{
	t_ssl			*ssl;

	if (!(ssl = (t_ssl *)malloc(sizeof(t_ssl))))
		return (0);
	ssl->files = NULL;
	ssl->total = 0;
	ssl->op = 0;
	ssl->sc = 0;
	ssl->mdc = 0;
	ssl->cc = 0;
	ssl->p_stdin = 0;
	return (ssl);
}
