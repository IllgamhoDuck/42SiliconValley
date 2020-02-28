/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:26:33 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:49:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieHorde
{
	private:
		Zombie*		_zombies;
		int			_N;

	public:
		ZombieHorde( int N );
		~ZombieHorde( void );

		void 		announce( void );
};

#endif
