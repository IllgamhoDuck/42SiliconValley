/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:41:42 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 22:56:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha224.h"
#include "libft.h"

static uint32_t g_sha224_init[8] = {
	0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939,
	0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4
};

t_sha224			*init_sha224(t_ssl *ssl)
{
	t_sha224		*sha224;
	int8_t			i;

	if (!(sha224 = (t_sha224 *)ft_memalloc(sizeof(t_sha224))))
		malloc_error("t_sha224");
	sha224->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	sha224->len = ft_strlen((char *)sha224->str);
	i = -1;
	while (++i < 8)
		sha224->h[i] = g_sha224_init[i];
	return (sha224);
}

void				store_result_sha224(t_ssl *ssl, t_sha224 *sha224)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output32[i] = sha224->h[i];
}

void				free_sha224(t_sha224 *sha224)
{
	if (sha224)
	{
		if (sha224->str)
			free(sha224->str);
		if (sha224->padded_str)
			free(sha224->padded_str);
		free(sha224);
	}
}
