/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_salt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:20:19 by hypark            #+#    #+#             */
/*   Updated: 2019/08/31 11:31:45 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

/*
** salt_op 0 - Encryption
** salt_op 1 - Decryption
*/


void					des_salt_header(t_des *des, uint8_t salt_op)
{
	char				*temp;
	char				*salt;

	// ON PROGRESSS! NEED TO FIX!
	if (salt_op == 0)
	{
		temp = ft_strnew(8);
		ft_memcpy(temp, &des->salt, 8);
		salt = ft_strjoin("Salted__", temp);
		free(temp);
		temp = ft_strjoin(salt, (char *)des->encode);
		free(salt);
		free(des->encode);
		des->encode = (uint8_t *)temp;
	}
	else if (salt_op == 1)
	{
		if (ft_strnequ("Salted__", (char *)des->str, 8))
		{
			temp = ft_strsub(des->str, 16, des->len - 16);
			free(des->str);
			des->str = (uint8_t *)temp;
		}
		else
			ft_printf("%2@bad decrypt\n");
	}
}
