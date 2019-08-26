/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:17:46 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:26:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha512.h"
#include "libft.h"

static uint64_t g_sha512_init[8] = {
	0x6a09e667f3bcc908, 0xbb67ae8584caa73b,
	0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
	0x510e527fade682d1, 0x9b05688c2b3e6c1f,
	0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
};

t_sha512			*init_sha512(t_ssl *ssl)
{
	t_sha512		*sha512;
	int8_t			i;

	if (!(sha512 = (t_sha512 *)ft_memalloc(sizeof(t_sha512))))
		malloc_error("t_sha512");
	sha512->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	sha512->len = ft_strlen((char *)sha512->str);
	i = -1;
	while (++i < ssl->hash_size)
		sha512->h[i] = g_sha512_init[i];
	return (sha512);
}

void				store_result_sha512(t_ssl *ssl, t_sha512 *sha512)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output64[i] = sha512->h[i];
}

void				free_sha512(t_sha512 *sha512)
{
	if (sha512)
	{
		if (sha512->str)
			free(sha512->str);
		if (sha512->padded_str)
			free(sha512->padded_str);
		free(sha512);
	}
}
