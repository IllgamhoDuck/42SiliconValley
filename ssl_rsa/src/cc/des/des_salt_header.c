/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_salt_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:10:28 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 21:16:04 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

/*
** salt_op 0 - Encryption
** salt_op 1 - Decryption
*/

static void				des_salt_encode(t_des *des)
{
	char				*salt;

	salt = ft_strnew(16 + des->len);
	ft_memcpy(salt, "Salted__", 8);
	ft_memcpy(salt + 8, &des->salt, 8);
	ft_memcpy(salt + 16, des->padded_str, des->len);
	free(des->padded_str);
	des->padded_str = (uint8_t *)salt;
	des->len += 16;
}

static void				des_salt_decode(t_des *des)
{
	char				*temp;

	if (des->len <= 16)
		des_invalid_input(0);
	if (ft_strnequ("Salted__", (char *)des->str, 8))
	{
		ft_memcpy(&des->salt, des->str + 8, 8);
		temp = ft_strnew(des->len - 16);
		ft_memcpy(temp, des->str + 16, des->len - 16);
		free(des->str);
		des->str = (uint8_t *)temp;
		des->len = des->len - 16;
	}
	else
		des_invalid_input(2);
}

void					des_salt_header(t_des *des, uint8_t salt_op)
{
	if (salt_op == 0)
		des_salt_encode(des);
	else if (salt_op == 1)
		des_salt_decode(des);
}
