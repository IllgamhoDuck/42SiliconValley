/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:39:46 by hypark            #+#    #+#             */
/*   Updated: 2019/08/27 23:44:53 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "base64.h"

void				base64_invalid_decode_value(void)
{
	ft_printf("Invalid decode string has been inputed\n");
	ft_printf("Please check the value again.\n");
	exit(1);
}
