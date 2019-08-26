/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:15:55 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:53:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA384_H
# define SHA384_H

# define S0_384(w_15) (ROTR64(w_15, 1) ^ ROTR64(w_15, 8) ^ SHIFTR(w_15, 7))
# define S1_384(w_2) (ROTR64(w_2, 19) ^ ROTR64(w_2, 61) ^ SHIFTR(w_2, 6))
# define WI_SHA384(w_2,w_7,w_15,w_16) (w_16 + S0_384(w_15) + w_7 + S1_384(w_2))

# define SS0_SHA384(a) (ROTR64(a, 28) ^ ROTR64(a, 34) ^ ROTR64(a, 39))
# define SS1_SHA384(e) (ROTR64(e, 14) ^ ROTR64(e, 18) ^ ROTR64(e, 41))
# define CH_SHA384(e,f,g) ((e & f) ^ (~e & g))
# define MAJ_SHA384(a,b,c) ((a & b) ^ (a & c) ^ (b & c))

# define T1_SHA384(e,f,g,h,k,w) (h + SS1_SHA384(e) + CH_SHA384(e,f,g) + k + w)
# define T2_SHA384(a,b,c) (SS0_SHA384(a) + MAJ_SHA384(a,b,c))

void				sha384(t_ssl *ssl);

typedef struct		s_sha384
{
	uint8_t			*str;
	uint8_t			*padded_str;
	uint32_t		len;
	uint64_t		h[8];
	uint64_t		words[8];
	uint64_t		w[80];
}					t_sha384;

t_sha384			*init_sha384(t_ssl *ssl);
void				print_sha384(t_sha384 *sha384);
void				store_result_sha384(t_ssl *ssl, t_sha384 *sha384);
void				free_sha384(t_sha384 *sha384);

#endif
