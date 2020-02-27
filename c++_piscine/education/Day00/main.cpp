/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:08:31 by hypark            #+#    #+#             */
/*   Updated: 2020/01/13 23:28:20 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "struct.hpp"
#include "class.hpp"
#include "class1.hpp"
#include "class2.hpp"

//void		f0( void ) {
//	Sample instance;
//
//	std::cout << "Number of instances" << Sample::getNbInst() << std::endl;
//
//	return ;
//}
//
//void		f1( void ) {
//	Sample instance;
//
//	std::cout << "Number of instances" << Sample::getNbInst() << std::endl;
//	f0();
//
//	return ;
//}

void		testing( void (Sample::*f)( void ) const, Sample * instance ) {
	(instance->*f)();
}

//void		testing( Sample * instance ) {
//	(instance->*f)();
//}

int			main() {

	Sample		instance;
	Sample*		instancep = &instance;

	int			Sample::*p = NULL;
	void		(Sample::*f)( void ) const;

	p = &Sample::foo;

	std::cout << "Value of member foo" << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo" << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo" << instance.foo << std::endl;


	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();
	testing(f, instancep);
	//testing(instancep);

//	std::cout << "Number of instances" << Sample::getNbInst() << std::endl;
//	f1();
//	std::cout << "Number of instances" << Sample::getNbInst() << std::endl;

//	if ( &instance1 == &instance1 )
//		std::cout << "instance1 and instance 1 are physically equal" << std::endl;
//	else
//		std::cout << "instance1 and instance 1 are not physically equal" << std::endl;
//
//	if ( &instance1 == &instance2 )
//		std::cout << "instance1 and instance 2 are physically equal" << std::endl;
//	else
//		std::cout << "instance1 and instance 2 are not physically equal" << std::endl;
//
//	if ( instance1.compare( &instance1 ) == 0 )
//		std::cout << "instance1 and instance 1 are physically equal" << std::endl;
//	else
//		std::cout << "instance1 and instance 1 are not physically equal" << std::endl;
//
//	if ( instance1.compare( &instance2 ) == 0 )
//		std::cout << "instance1 and instance 2 are physically equal" << std::endl;
//	else
//		std::cout << "instance1 and instance 2 are not physically equal" << std::endl;
//	instance.setFoo( 42 );
//	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
//	instance.setFoo( -42 );
//	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
//	instance.publicfoo = 42;
//	std::cout << "instance.publicfoo: " << instance.publicfoo << std::endl;
//	instance._privatefoo = 42;
//	std::cout << "instance._privatefoo: " << instance._privatefoo << std::endl;

//	instance.publicBar();
//	instance._privateBar();

	return 0;
}
