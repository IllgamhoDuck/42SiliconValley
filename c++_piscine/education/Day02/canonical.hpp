/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonical.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 21:45:01 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 21:50:43 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANONICAL_HPP
# define CANONICAL_HPP

# include <iostream>

// Co clean form or Canonical form
// systematically write all the code in this form
class Sample
{
	public:
		Sample(void);
		Sample(int const n);
		Sample(Sample const & src);
		~Sample(void);

		Sample & operator=(Sample const & rhs);

		int		getFoo(void) const;
	
	private:
		int		_foo;
};

std::ostream & 		operator<<(std::ostream & o, Sample const & i);

#endif
