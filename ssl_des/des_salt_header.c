/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_salt_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:10:28 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 03:17:29 by hypark           ###   ########.fr       */
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
	char				*temp;
	char				*salt;

	temp = ft_strnew(8);
	ft_memcpy(temp, &des->salt, 8);
	salt = ft_strjoin("Salted__", temp);
	free(temp);
	temp = ft_strjoin(salt, (char *)des->encode);
	free(salt);
	free(des->encode);
	des->encode = (uint8_t *)temp;
	des->len += 16;
}

//SEGFAULT!
static void				des_salt_decode(t_des *des)
{
	uint32_t			len;

	ft_printf("%c %c\n", des->str[15], des->str[16]);
	if (des->str[16] == '\0')
		des_invalid_input(0);
	len = ft_strlen((char *)(des->str + 16));
	des->len = len + 16;
	if (ft_strnequ("Salted__", (char *)des->str, 8))
	{
		ft_memcpy(&des->salt, des->str + 8, 8);
		des->str = (uint8_t *)ft_strsub((char *)des->str, 16, des->len - 16);
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
