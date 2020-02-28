/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:05:20 by hypark            #+#    #+#             */
/*   Updated: 2020/01/16 00:24:44 by hypark           ###   ########.fr       */
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

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		float				toFloat(void) const;
		int					toInt(void) const;
	
	private:
		int					_fixedPoint;
		static const int	_bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
