/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:09:41 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 23:36:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"
# include <iostream>

class Human
{
	public:
		Human( void );
		~Human( void );

		std::string identify( void );
		Brain getBrain( void );
	
	private:
		Brain _brain;

};

#endif
