/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:15:55 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:28:43 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# define S0_256(w_15) (ROTR32(w_15, 7) ^ ROTR32(w_15, 18) ^ SHIFTR(w_15, 3))
# define S1_256(w_2) (ROTR32(w_2, 17) ^ ROTR32(w_2, 19) ^ SHIFTR(w_2, 10))
# define WI_SHA256(w_2,w_7,w_15,w_16) (w_16 + S0_256(w_15) + w_7 + S1_256(w_2))

# define SS0_SHA256(a) (ROTR32(a, 2) ^ ROTR32(a, 13) ^ ROTR32(a, 22))
# define SS1_SHA256(e) (ROTR32(e, 6) ^ ROTR32(e, 11) ^ ROTR32(e, 25))
# define CH_SHA256(e,f,g) ((e & f) ^ (~e & g))
# define MAJ_SHA256(a,b,c) ((a & b) ^ (a & c) ^ (b & c))

# define T1_SHA256(e,f,g,h,k,w) (h + SS1_SHA256(e) + CH_SHA256(e,f,g) + k + w)
# define T2_SHA256(a,b,c) (SS0_SHA256(a) + MAJ_SHA256(a,b,c))

void				sha256(t_ssl *ssl);

typedef struct		s_sha256
{
	uint8_t			*str;
	uint8_t			*padded_str;
	uint32_t		len;
	uint32_t		h[8];
	uint32_t		words[8];
	uint32_t		w[64];
}					t_sha256;

t_sha256			*init_sha256(t_ssl *ssl);
void				print_sha256(t_sha256 *sha256);
void				store_result_sha256(t_ssl *ssl, t_sha256 *sha256);
void				free_sha256(t_sha256 *sha256);

#endif
