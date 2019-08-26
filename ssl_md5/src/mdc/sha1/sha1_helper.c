/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:24:51 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:45:23 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha1.h"
#include "libft.h"

static uint32_t g_sha1_init[5] = {
	0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476,
	0xC3D2E1F0
};

t_sha1				*init_sha1(t_ssl *ssl)
{
	t_sha1			*sha1;
	int8_t			i;

	if (!(sha1 = (t_sha1 *)ft_memalloc(sizeof(t_sha1))))
		malloc_error("t_sha1");
	sha1->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	sha1->len = ft_strlen((char *)sha1->str);
	i = -1;
	while (++i < ssl->hash_size)
		sha1->h[i] = g_sha1_init[i];
	return (sha1);
}

void				store_result_sha1(t_ssl *ssl, t_sha1 *sha1)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output32[i] = sha1->h[i];
}

void				free_sha1(t_sha1 *sha1)
{
	if (sha1)
	{
		if (sha1->str)
			free(sha1->str);
		if (sha1->padded_str)
			free(sha1->padded_str);
		free(sha1);
	}
}
