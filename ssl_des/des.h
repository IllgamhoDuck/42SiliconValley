/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:44:19 by hypark            #+#    #+#             */
/*   Updated: 2019/08/29 17:57:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
# define DES_H

# define START8 0x80
# define START16 0x8000
# define START32 0x80000000
# define START64 0x8000000000000000

# define FINDBIT8(n,i) ((n & (START8 >> (i - 1))) ? 1 : 0)
# define FINDBIT16(n,i) ((n & (START16 >> (i - 1))) ? 1 : 0)
# define FINDBIT32(n,i) ((n & (START32 >> (i - 1))) ? 1 : 0)
# define FINDBIT64(n,i) ((n & (START64 >> (i - 1))) ? 1 : 0)

# define PUTBIT8(i) (START8 >> i)
# define PUTBIT16(i) (START16 >> i)
# define PUTBIT32(i) (START32 >> i)
# define PUTBIT64(i) (START64 >> i)

extern uint8_t g_pc1[56];
extern uint8_t g_pc2[48];
extern uint8_t g_ip1[64];
extern uint8_t g_ip2[64];

extern uint8_t g_p[32];
extern uint8_t g_expand[48];

extern uint8_t g_s1[64];
extern uint8_t g_s2[64];
extern uint8_t g_s3[64];
extern uint8_t g_s4[64];
extern uint8_t g_s5[64];
extern uint8_t g_s6[64];
extern uint8_t g_s7[64];
extern uint8_t g_s8[64];

typedef struct		s_des
{
	uint8_t			*str;
	uint32_t		len;
	uint8_t			*padded_str;
	uint8_t			*prev_block;
	uint8_t			*encode;
	uint8_t			*decode;
	uint8_t			*key;
	uint8_t			*password;
	uint8_t			*salt;
	uint8_t			*iv;
}					t_des;

void				des_process(t_ssl *ssl, t_des *des);

t_des				*init_des(t_ssl *ssl);
void				store_result_des(t_ssl *ssl, t_des *des);
void				free_des(t_des *des);

void				des_invalid_password(void);
void				des_invalid_salt(uint8_t salt_op);
void				des_invalid_key(void);
void				des_invalid_iv(uint8_t salt_iv);

#endif
