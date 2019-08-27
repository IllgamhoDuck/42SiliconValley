/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:17:46 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 21:34:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"
#include "libft.h"

static uint32_t g_sha256_init[8] = {
	0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
	0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

t_sha256			*init_sha256(t_ssl *ssl)
{
	t_sha256		*sha256;
	int8_t			i;

	if (!(sha256 = (t_sha256 *)ft_memalloc(sizeof(t_sha256))))
		malloc_error("t_sha256");
	sha256->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	sha256->len = ft_strlen((char *)sha256->str);
	i = -1;
	while (++i < ssl->hash_size)
		sha256->h[i] = g_sha256_init[i];
	return (sha256);
}

void				store_result_sha256(t_ssl *ssl, t_sha256 *sha256)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output32[i] = sha256->h[i];
}

void				free_sha256(t_sha256 *sha256)
{
	if (sha256)
	{
		if (sha256->str)
			free(sha256->str);
		if (sha256->padded_str)
			free(sha256->padded_str);
		free(sha256);
	}
}
