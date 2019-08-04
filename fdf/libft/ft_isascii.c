/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:35:03 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 20:37:34 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isascii() function tests for an ASCII character, which is any char-
** acter between 0 and octal 0177 inclusive.
*/

int				ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
