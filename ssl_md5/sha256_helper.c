/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:17:46 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 16:18:18 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"
#include "libft.h"

static uint32_t g_sha256_init[4] = {
	0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
};

t_sha256			*init_sha256(t_ssl *ssl)
{
	t_sha256		*sha256;
	int8_t			i;

	if (!(sha256 = (t_sha256 *)ft_memalloc(sizeof(t_sha256))))
		malloc_error("t_sha256");
	sha256->str = (uint8_t *)ft_strdup(ssl->hash_input);
	sha256->len = ft_strlen((char *)sha256->str);
	i = -1;
	while (++i < 4)
		sha256->h[i] = g_sha256_init[i];
	return (sha256);
}

void				store_result_sha256(t_ssl *ssl, t_sha256 *sha256)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output[i] = sha256->h[i];
}

void				free_sha256(t_sha256 *sha256)
{
	if (sha256)
	{
		if (sha256->str)
			free(sha256->str);
		if (sha256->padded_str)
			free(sha256->str);
		free(sha256);
	}
}
