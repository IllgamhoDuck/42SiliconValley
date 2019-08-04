/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:39:28 by hypark            #+#    #+#             */
/*   Updated: 2019/07/25 20:44:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isprint() function tests for any printing character, including space
** (` ').  The value of the argument must be representable as an unsigned
** char or the value of EOF.
** The isprint() function returns zero if the character tests false and
** returns non-zero if the character tests true.
*/

int				ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
