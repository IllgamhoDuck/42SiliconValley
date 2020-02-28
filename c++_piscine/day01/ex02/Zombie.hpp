/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:41:22 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 21:59:58 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;
		std::string _type;

	public:
		Zombie(std::string name, std::string type);
		~Zombie();

		void announce( void ) const;
		void dead( void ) const;
};

void			randomChump( void );

#endif
