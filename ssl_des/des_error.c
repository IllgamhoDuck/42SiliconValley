/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:09:25 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 02:27:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "des.h"

void				des_invalid_password(void)
{
	ft_printf("%2@Verify failure\n");
	ft_printf("%2@bad password read\n");
	exit(1);
}

void				des_invalid_salt(uint8_t salt_op)
{
	if (salt_op == 0)
		ft_printf("%2@hex string is too long\ninvalid hex salt value\n");
	else if (salt_op == 1)
		ft_printf("%2@non-hex digit\ninvalid hex salt value\n");
	exit(1);
}

void				des_invalid_key(void)
{
	ft_printf("%2@non-hex digit\n");
	ft_printf("%2@invalid hex key value\n");
	exit(1);
}

void				des_invalid_iv(uint8_t iv_op)
{
	if (iv_op == 0)
		ft_printf("%2@hex string is too long\ninvalid hex iv value\n");
	else if (iv_op == 1)
		ft_printf("%2@non-hex digit\ninvalid hex iv value\n");
	else if (iv_op == 2)
		ft_printf("%2@iv undefined\n");
	exit(1);
}

void				des_invalid_input(uint8_t input_op)
{
	if (input_op == 0)
		ft_printf("%2@Input value is not valid\n");
	else if (input_op == 1)
		ft_printf("%2@bad decrypt\n");
	else if (input_op == 2)
	{
		ft_printf("%2@bad magic number\n");
		exit(1);
	}
	else if (input_op == 3)
	{
		ft_printf("%2@bad decrypt\n");
		exit(1);
	}
}
