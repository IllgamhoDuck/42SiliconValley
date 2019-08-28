/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:46:04 by hypark            #+#    #+#             */
/*   Updated: 2019/08/27 23:42:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

void				base64(t_ssl *ssl);

typedef struct		s_base64
{
	uint8_t			*str;
	uint32_t		len;
	uint8_t			pad_len;
	uint8_t			*padded_str;
	uint8_t			*encode;
	uint8_t			*decode;
}					t_base64;

t_base64			*init_base64(t_ssl *ssl);
void				print_base64(t_base64 *base64);
void				store_result_base64(t_ssl *ssl, t_base64 *base64);
void				free_base64(t_base64 *base64);
int8_t				is_valid_char_base64(uint8_t c);

void				base64_invalid_decode_value(void);

#endif
