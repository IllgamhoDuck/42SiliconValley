/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:26:10 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 20:29:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** he isdigit() function tests for a decimal digit character.
** The isdigit() and isnumber() functions return zero if the character
** tests false and return non-zero if the character tests true.
*/

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
