/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:01:48 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 21:20:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony
{
	private:
		std::string _name;

	public:
		Pony(std::string name);
		~Pony();

		void ponySay( void ) const;
};

void		ponyOnTheStack(std::string name);
void		ponyOnTheHeap(std::string name);

#endif
