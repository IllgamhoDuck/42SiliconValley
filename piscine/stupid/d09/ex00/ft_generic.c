/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:23:27 by hypark            #+#    #+#             */
/*   Updated: 2018/05/24 18:26:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_generic(void)
{
	char	*str;

	str = "Tut tut ; Tut tut\n";
	while(*str)
		write(1, str++, 1);
}
