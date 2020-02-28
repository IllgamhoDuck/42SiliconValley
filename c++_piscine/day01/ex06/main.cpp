/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:52:47 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 00:50:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

int				main()
{
	// PDF test code
	{
		Weapon			club = Weapon("Crude spiked club");

		HumanA bob("bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		// This should be made as a pointer
		// because reference variable should be choosen when it is initialized
		// but jim set weapon later. in this case reference variable cannot be used
		Weapon			club = Weapon("Crude spiked club");

		HumanB jim("jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

//	// Human A
//	Weapon* weapon1 = new Weapon("crude spiked club");
//	HumanA* human1 = new HumanA("greg", weapon1);	
//
//	// Human B
//	Weapon* weapon2 = new Weapon("goose");
//	HumanB* human2 = new HumanB("ducky", weapon2);	
//
//	// Fight round 1
//	human1->attack();
//	human2->attack();
//
//	// Change weapon!
//	weapon1->setType("ice frozen club");
//	weapon2->setType("ANGRYY GOOSE");
//
//	// Fight round 2
//	human1->attack();
//	human2->attack();
//
//	// delete all
//	delete weapon1;
//	delete weapon2;
//	delete human1;
//	delete human2;
	
	return 0;
}
