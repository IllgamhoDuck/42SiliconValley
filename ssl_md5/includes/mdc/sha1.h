/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:24:09 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:36:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA1_H
# define SHA1_H

# define WI_SHA1(w_3,w_8,w_14,w_16) ROTL32((w_3 ^ w_8 ^ w_14 ^ w_16), 1)

# define A_SHA1(b,c,d) ((b & c) | (~b & d))
# define B_SHA1(b,c,d) (b ^ c ^ d)
# define C_SHA1(b,c,d) ((b & c) | (b & d) | (c & d))
# define D_SHA1(b,c,d) (b ^ c ^ d)

# define R1_SHA1(a,b,c,d,e,k,w) (ROTL32(a, 5) + A_SHA1(b,c,d) + e + k + w)
# define R2_SHA1(a,b,c,d,e,k,w) (ROTL32(a, 5) + B_SHA1(b,c,d) + e + k + w)
# define R3_SHA1(a,b,c,d,e,k,w) (ROTL32(a, 5) + C_SHA1(b,c,d) + e + k + w)
# define R4_SHA1(a,b,c,d,e,k,w) (ROTL32(a, 5) + D_SHA1(b,c,d) + e + k + w)

void				sha1(t_ssl *ssl);

typedef struct		s_sha1
{
	uint8_t			*str;
	uint8_t			*padded_str;
	uint32_t		len;
	uint32_t		h[5];
	uint32_t		words[5];
	uint32_t		w[80];
}					t_sha1;

t_sha1				*init_sha1(t_ssl *ssl);
void				print_sha1(t_sha1 *sha1);
void				store_result_sha1(t_ssl *ssl, t_sha1 *sha1);
void				free_sha1(t_sha1 *sha1);

#endif
