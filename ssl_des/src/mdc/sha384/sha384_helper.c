/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:17:46 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:55:03 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha384.h"
#include "libft.h"

static uint64_t g_sha384_init[8] = {
	0xcbbb9d5dc1059ed8, 0x629a292a367cd507,
	0x9159015a3070dd17, 0x152fecd8f70e5939,
	0x67332667ffc00b31, 0x8eb44a8768581511,
	0xdb0c2e0d64f98fa7, 0x47b5481dbefa4fa4
};

t_sha384			*init_sha384(t_ssl *ssl)
{
	t_sha384		*sha384;
	int8_t			i;

	if (!(sha384 = (t_sha384 *)ft_memalloc(sizeof(t_sha384))))
		malloc_error("t_sha384");
	sha384->str = (uint8_t *)ft_strdup(ssl->ssl_input);
	sha384->len = ft_strlen((char *)sha384->str);
	i = -1;
	while (++i < 8)
		sha384->h[i] = g_sha384_init[i];
	return (sha384);
}

void				store_result_sha384(t_ssl *ssl, t_sha384 *sha384)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output64[i] = sha384->h[i];
}

void				free_sha384(t_sha384 *sha384)
{
	if (sha384)
	{
		if (sha384->str)
			free(sha384->str);
		if (sha384->padded_str)
			free(sha384->padded_str);
		free(sha384);
	}
}
