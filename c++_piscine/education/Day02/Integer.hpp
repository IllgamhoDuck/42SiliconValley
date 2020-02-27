/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:57:04 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 21:30:24 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>

class Integer {
	public:
		Integer(int const n);
		~Integer(void);

		int		getValue(void) const;

		// operand on the left and the other one on the right
		// a = b = c = d;
		Integer & operator=(Integer const & rhs);
		Integer   operator+(Integer const & rhs) const;

	private:
		int		_n;
};

// we cannot use << (less than less than)
std::ostream & operator<<(std::ostream & o, Integer const & rhs);

#endif
