/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:05:20 by hypark            #+#    #+#             */
/*   Updated: 2020/01/16 01:50:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const z);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);

		// Comparison operators
		bool 	operator>(Fixed const & rhs) const;
		bool 	operator<(Fixed const & rhs) const;
		bool 	operator>=(Fixed const & rhs) const;
		bool 	operator<=(Fixed const & rhs) const;
		bool 	operator==(Fixed const & rhs) const;

		// Arithmetic operators
		Fixed 	operator+(Fixed const & rhs) const;
		Fixed 	operator-(Fixed const & rhs) const;
		Fixed 	operator*(Fixed const & rhs) const;
		Fixed 	operator/(Fixed const & rhs) const;

		// pre, post - increment
		Fixed &	operator++(void);
		Fixed 	operator++(int);

		// pre, post - decrement
		Fixed &	operator--(void);
		Fixed 	operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		float				toFloat(void) const;
		int					toInt(void) const;
	
	private:
		int					_fixedPoint;
		static const int	_bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

// non member min & max function
Fixed & 		max(Fixed & c1, Fixed & c2);
Fixed & 		min(Fixed & c1, Fixed & c2);
Fixed const & 	max(Fixed const & c1, Fixed const & c2);
Fixed const & 	min(Fixed const & c1, Fixed const & c2);

#endif
