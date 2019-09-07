/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:09:20 by hypark            #+#    #+#             */
/*   Updated: 2019/09/06 11:42:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void					print_bits(uint8_t *str, uint32_t len, char *where)
{
	uint8_t				*block;
	uint32_t			i;

	i = 0;
	block = (uint8_t *)str;
	ft_printf("{red}TESTING{eos} : {cyan}%s{eos}\n", where);
	while (i < len)
	{
		ft_printf("%08b ", block[i++]);
		i % 8 == 0 ? ft_printf("\n") : 0;
		i % 64 == 0 ? ft_printf("\n") : 0;
	}
	ft_putchar('\n');
}
