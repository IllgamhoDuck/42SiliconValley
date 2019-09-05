/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_eucleidian.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:26:21 by hypark            #+#    #+#             */
/*   Updated: 2019/09/05 01:06:50 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "ft_math.h"

/*
** "EXTENDED_EUCLEIDIAN"
** "====================================================================="
** "ax + by = c" (assume c = gcd(a, b))
** if we say "a = bq + r" (q is quotient, r is rest)
** ...
** "b(qx + y) + rx = c = gcd(a, b) = gcd(b, r)"
** ...
** this will be done recursively until "b = 0"
** when "b = 0" then "a" is the greatest common divisor
** ...
** "ax + by = gcd(a, b)"
** a is now known as the gcd(a, b)
** "gcd(a, b)x + by = gcd(a, b)"
** so we can say...
** "x = 1"
** "y = 0"
** Now we can go back tracking and use this bottom node "x, y" value
** to calculate the very first root node "ax + by = c"'s "x, y" value!
** ...
** ... I put the "()" because to distinguish '("litte quotation marks")
** ...
** when we use two stuff "ax + by = c" and "a = bq + r"
** we can make this -> "b(qx + y) + rx = c"
** and we could assume this is same as "b(qx + y) + rx  = a'(x') + b'(y')"
** we can write this like...
** "b = (a')" "qx + y = (x')" "r = (b')" "x = (y')"
** ...
** ARE GOAL IS TO GET THE VALUE OF "x, y" so we ignore the "(a'), (b')"
** "x = (y')"
** "y = (x') - qx" => "y = (x') - q(y')" also "q = a / b"
** "y = (x') - (a / b)(y')"
** So the we could return the value of "x, y" from "x', y'"
** As we say (g, x, y) -> (g, y', x' - (a / b) * y')
** "====================================================================="
** EXAMPLE from ... "https://casterian.net/archives/601"
** 1071 x + 1029 y = gcd(1071, 1029)
** (a, b) = (1914, 899) = (899, 116) = (116, 87) = (87, 29) = (29, 0)
** (x, y) = (8, -17)   <= (-1, 8)   <= (1, -1)  <= (0, 1)  <= (1, 0)
** ===========================================
** g will be gcd(greatest common divisor)
** x, y is the value we need to get
** ===========================================
** (g, x, y) ext_eucl(a, b)
** if (b == 0)
** 		return (a, 1, 0) 
** (g, x, y) = ext_eucl(b, a % b)
** return (g, y, x - (a / b) * y)
** ===========================================
*/
