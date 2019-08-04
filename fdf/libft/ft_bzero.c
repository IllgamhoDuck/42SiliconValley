/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:44:28 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 21:19:51 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	   The bzero() function writes n zeroed bytes to the string s.
**     If n is zero, bzero() does nothing.
*/

void				ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
