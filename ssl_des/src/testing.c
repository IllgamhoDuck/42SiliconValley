/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:09:20 by hypark            #+#    #+#             */
/*   Updated: 2019/08/28 00:19:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include <fcntl.h>

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

void					write_file(char *file, uint8_t *content)
{
	int32_t				fd;

	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC)) < 0)
		p_error("Failed to open the file to write");
	write(fd, content, ft_strlen((char *)content));
	close(fd);
}
