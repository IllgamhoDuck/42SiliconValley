/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:32:45 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 01:11:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "libft.h"

static uint32_t g_md5_init[4] = {0x67452301,0xEFCDAB89, 0x98BADCFE, 0x10325476
};

t_md5				*init_md5(t_ssl *ssl)
{
	t_md5			*md5;
	int8_t			i;

	if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
		malloc_error("t_md5");
	md5->str = (uint8_t *)ft_strdup(ssl->hash_input);
	md5->len = ft_strlen((char *)md5->str);
	i = -1;
	while (++i < 4)
		md5->h[i] = g_md5_init[i];
	free(ssl->hash_input);
	return (md5);
}

void				store_result_md5(t_ssl *ssl, t_md5 *md5)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output[i] = md5->h[i];
}

void				free_md5(t_md5 *md5)
{
	if (md5)
	{
		if (md5->str)
			free(md5->str);
		if (md5->padded_str)
			free(md5->str);
		free(md5);
	}
}
