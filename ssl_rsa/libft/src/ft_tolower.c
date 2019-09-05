/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:55:04 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 21:18:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The tolower() function converts an upper-case letter to the correspond-
** ing lower-case letter.  The argument must be representable as an
** unsigned char or the value of EOF.
** If the argument is an upper-case letter, the tolower() function returns
** the corresponding lower-case letter if there is one; otherwise, the
** argument is returned unchanged.
*/

int				ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
