/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:41:56 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:21:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string _type;

	public:
		ZombieEvent( void );
		~ZombieEvent( void );

		void 		setZombieType( std::string type );
		Zombie*		newZombie( std::string name );
};

#endif
