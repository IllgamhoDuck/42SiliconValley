/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 00:12:18 by hypark            #+#    #+#             */
/*   Updated: 2019/08/26 00:19:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_2_H
# define SHA512_2_H

# define S0_5_2(w_15) (ROTR64(w_15, 1) ^ ROTR64(w_15, 8) ^ SHIFTR(w_15, 7))
# define S1_5_2(w_2) (ROTR64(w_2, 19) ^ ROTR64(w_2, 61) ^ SHIFTR(w_2, 6))
# define WI_SHA5_2(w_2,w_7,w_15,w_16) (w_16 + S0_5_2(w_15) + w_7 + S1_5_2(w_2))

# define SS0_512_2(a) (ROTR64(a, 28) ^ ROTR64(a, 34) ^ ROTR64(a, 39))
# define SS1_512_2(e) (ROTR64(e, 14) ^ ROTR64(e, 18) ^ ROTR64(e, 41))
# define CH_512_2(e,f,g) ((e & f) ^ (~e & g))
# define MAJ_512_2(a,b,c) ((a & b) ^ (a & c) ^ (b & c))

# define T1_SHA512_2(e,f,g,h,k,w) (h + SS1_512_2(e) + CH_512_2(e,f,g) + k + w)
# define T2_SHA512_2(a,b,c) (SS0_512_2(a) + MAJ_512_2(a,b,c))

void				sha512t256(t_ssl *ssl);

typedef struct		s_sha512_2
{
	uint8_t			*str;
	uint8_t			*padded_str;
	uint32_t		len;
	uint64_t		h[8];
	uint64_t		words[8];
	uint64_t		w[80];
}					t_sha512_2;

t_sha512_2			*init_sha512_2(t_ssl *ssl);
void				print_sha512_2(t_sha512_2 *sha512_2);
void				store_result_sha512_2(t_ssl *ssl, t_sha512_2 *sha512_2);
void				free_sha512_2(t_sha512_2 *sha512_2);

#endif
