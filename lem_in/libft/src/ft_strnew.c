/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:39:32 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 21:53:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	char			*result;

	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}
