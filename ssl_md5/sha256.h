/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:15:55 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 16:16:41 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# define F(x,y,z) ((x & y) | (~x & z))
# define G(x,y,z) ((x & z) | (y & ~z))
# define H(x,y,z) (x ^ y ^ z)
# define I(x,y,z) (y ^ (x | ~z))
# define ROTLEFT(w,n) ((w << n) | (w >> (32 - n)))

# define R1(a,b,c,d,w,k,r) b + ROTLEFT((a + F(b,c,d) + k + w), r)
# define R2(a,b,c,d,w,k,r) b + ROTLEFT((a + G(b,c,d) + k + w), r)
# define R3(a,b,c,d,w,k,r) b + ROTLEFT((a + H(b,c,d) + k + w), r)
# define R4(a,b,c,d,w,k,r) b + ROTLEFT((a + I(b,c,d) + k + w), r)

void				sha256(t_ssl *ssl);

typedef struct		s_sha256
{
	uint8_t			*str;
	uint8_t			*padded_str;
	uint32_t		len;
	uint32_t		h[4];
	uint32_t		abcd[4];
	uint32_t		w[16];
}					t_sha256;

t_sha256			*init_sha256(t_ssl *ssl);
void				print_sha256(t_sha256 *sha256);
void				store_result_sha256(t_ssl *ssl, t_sha256 *sha256);
void				free_sha256(t_sha256 *sha256);

#endif
