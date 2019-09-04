/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:32:45 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 15:45:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "libft.h"

static uint32_t g_md5_init[4] = {
	0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
};

t_md5				*init_md5(t_ssl *ssl)
{
	t_md5			*md5;
	int8_t			i;

	if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
		malloc_error("t_md5");
	if (ssl->p_mutual)
		md5->len = ssl->mut_len;
	else
		md5->len = ssl->read_len;
	md5->str = (uint8_t *)ft_strnew(md5->len);
	ft_memcpy(md5->str, ssl->ssl_input, md5->len);
	i = -1;
	while (++i < ssl->hash_size)
		md5->h[i] = g_md5_init[i];
	return (md5);
}

void				store_result_md5(t_ssl *ssl, t_md5 *md5)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output32[i] = md5->h[i];
}

void				free_md5(t_md5 *md5)
{
	if (md5)
	{
		if (md5->str)
			free(md5->str);
		if (md5->padded_str)
			free(md5->padded_str);
		free(md5);
	}
}
