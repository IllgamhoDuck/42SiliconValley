/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:40:51 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:28:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
# define SHA224_H

# define S0_224(w_15) (ROTR32(w_15, 7) ^ ROTR32(w_15, 18) ^ SHIFTR(w_15, 3))
# define S1_224(w_2) (ROTR32(w_2, 17) ^ ROTR32(w_2, 19) ^ SHIFTR(w_2, 10))
# define WI_SHA224(w_2,w_7,w_15,w_16) (w_16 + S0_224(w_15) + w_7 + S1_224(w_2))

# define SS0_SHA224(a) (ROTR32(a, 2) ^ ROTR32(a, 13) ^ ROTR32(a, 22))
# define SS1_SHA224(e) (ROTR32(e, 6) ^ ROTR32(e, 11) ^ ROTR32(e, 25))
# define CH_SHA224(e,f,g) ((e & f) ^ (~e & g))
# define MAJ_SHA224(a,b,c) ((a & b) ^ (a & c) ^ (b & c))

# define T1_SHA224(e,f,g,h,k,w) (h + SS1_SHA224(e) + CH_SHA224(e,f,g) + k + w)
# define T2_SHA224(a,b,c) (SS0_SHA224(a) + MAJ_SHA224(a,b,c))

void				sha224(t_ssl *ssl);

typedef struct		s_sha224
{
	uint8_t			*str;
	uint8_t			*padded_str;
	uint32_t		len;
	uint32_t		h[8];
	uint32_t		words[8];
	uint32_t		w[64];
}					t_sha224;

t_sha224			*init_sha224(t_ssl *ssl);
void				print_sha224(t_sha224 *sha224);
void				store_result_sha224(t_ssl *ssl, t_sha224 *sha224);
void				free_sha224(t_sha224 *sha224);

#endif
