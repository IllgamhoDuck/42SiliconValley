/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 23:36:25 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:27:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define F_MD5(x,y,z) ((x & y) | (~x & z))
# define G_MD5(x,y,z) ((x & z) | (y & ~z))
# define H_MD5(x,y,z) (x ^ y ^ z)
# define I_MD5(x,y,z) (y ^ (x | ~z))

# define R1_MD5(a,b,c,d,w,k,r) b + ROTL32((a + F_MD5(b,c,d) + k + w), r)
# define R2_MD5(a,b,c,d,w,k,r) b + ROTL32((a + G_MD5(b,c,d) + k + w), r)
# define R3_MD5(a,b,c,d,w,k,r) b + ROTL32((a + H_MD5(b,c,d) + k + w), r)
# define R4_MD5(a,b,c,d,w,k,r) b + ROTL32((a + I_MD5(b,c,d) + k + w), r)

void				md5(t_ssl *ssl);

typedef struct		s_md5
{
	uint8_t			*str;
	uint8_t			*padded_str;
	uint32_t		len;
	uint32_t		h[4];
	uint32_t		abcd[4];
	uint32_t		w[16];
}					t_md5;

t_md5				*init_md5(t_ssl *ssl);
void				print_md5(t_md5 *md5);
void				store_result_md5(t_ssl *ssl, t_md5 *md5);
void				free_md5(t_md5 *md5);

#endif
