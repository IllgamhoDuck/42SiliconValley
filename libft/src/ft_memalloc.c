/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:59:47 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 23:39:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*memory;

	memory = (unsigned char *)malloc(size);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
