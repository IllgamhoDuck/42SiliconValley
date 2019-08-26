/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:15:55 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 18:41:33 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# define ROTR(w,n) ((w >> n) | (w << (32 - n)))
# define SHIFTR(w,n) (w >> n)

# define S0(w_15) (ROTR(w_15, 7) ^ ROTR(w_15, 18) ^ SHIFTR(w_15, 3))
# define S1(w_2) (ROTR(w_2, 17) ^ ROTR(w_2, 19) ^ SHIFTR(w_2, 10))
# define W_I(w_2,w_7,w_15,w_16) (w_16 + S0(w_15) + w_7 + S1(w_2))

# define SS0(a) (ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22))
# define SS1(e) (ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25))
# define CH(e,f,g) ((e & f) ^ (~e & g))
# define MAJ(a,b,c) ((a & b) ^ (a & c) ^ (b & c))

# define T1(e,f,g,h,k,w) (h + SS1(e) + CH(e,f,g) + k + w)
# define T2(a,b,c) (SS0(a) + MAJ(a,b,c))

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
