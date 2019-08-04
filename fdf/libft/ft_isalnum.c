/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:30:32 by hypark            #+#    #+#             */
/*   Updated: 2019/07/27 03:24:03 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isalnum() function tests for any character for which isalpha(3) or
** isdigit(3) is true.  The value of the argument must be representable as
** an unsigned char or the value of EOF.
** The isalnum() function returns zero if the character tests false and
** returns non-zero if the character tests true.
*/

int				ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
