/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:58:36 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 00:14:18 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_strclr(char *s)
{
	size_t			size;

	if (s == NULL)
		return ;
	size = ft_strlen(s);
	ft_memset(s, '\0', size);
}
