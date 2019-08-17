/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:19:43 by hypark            #+#    #+#             */
/*   Updated: 2019/07/27 03:54:05 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isalpha() function tests for any character for which isupper(3) or
** islower(3) is true.  The value of the argument must be representable as
** an unsigned char or the value of EOF.
** The isalpha() function returns zero if the character tests false and
** returns non-zero if the character tests true.
*/

int				ft_isalpha(int c)
{
	return (('A' <= c && 'Z' >= c) || ('a' <= c && 'z' >= c));
}
