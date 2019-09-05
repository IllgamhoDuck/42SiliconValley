/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_2_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 00:14:48 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 23:45:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha512_2.h"
#include "libft.h"

static uint64_t g_sha512_2_init[8] = {
	0x22312194fc2bf72c, 0x9f555fa3c84c64c2,
	0x2393b86b6f53b151, 0x963877195940eabd,
	0x96283ee2a88effe3, 0xbe5e1e2553863992,
	0x2b0199fc2c85b8aa, 0x0eb72ddc81c52ca2
};

t_sha512_2			*init_sha512_2(t_ssl *ssl)
{
	t_sha512_2		*sha512_2;
	int8_t			i;

	if (!(sha512_2 = (t_sha512_2 *)ft_memalloc(sizeof(t_sha512_2))))
		malloc_error("t_sha512_2");
	if (ssl->p_mutual)
		sha512_2->len = ssl->mut_len;
	else
		sha512_2->len = ssl->read_len;
	sha512_2->str = (uint8_t *)ft_strnew(sha512_2->len);
	ft_memcpy(sha512_2->str, ssl->ssl_input, sha512_2->len);
	i = -1;
	while (++i < 8)
		sha512_2->h[i] = g_sha512_2_init[i];
	return (sha512_2);
}

void				store_result_sha512_2(t_ssl *ssl, t_sha512_2 *sha512_2)
{
	int32_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ssl->hash_output64[i] = sha512_2->h[i];
}

void				free_sha512_2(t_sha512_2 *sha512_2)
{
	if (sha512_2)
	{
		if (sha512_2->str)
			free(sha512_2->str);
		if (sha512_2->padded_str)
			free(sha512_2->padded_str);
		free(sha512_2);
	}
}
