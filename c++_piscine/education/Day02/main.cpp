/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:29:54 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 22:02:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include "Sample.class.hpp"
#include "Integer.hpp"
#include "canonical.hpp"

int		main()
{

	// Lesson1 - Sample.class.hpp
//	Sample sample = Sample();
//
//	sample.bar('a');
//	sample.bar(42);
//	sample.bar((float)3.14);
//	sample.bar(sample);


	// Lesson2 - Integer.hpp
//	Integer		x(30);
//	Integer		y(10);
//	Integer		z(0);

//	std::cout << "Value of x : " << x << std::endl;
//	std::cout << "Value of y : " << y << std::endl;
//	y = Integer(12);
//
//	std::cout << "Value of y : " << y << std::endl;
//
//	std::cout << "Value of z : " << z << std::endl;
//	z = x + y;
//	std::cout << "Value of z : " << z << std::endl;

	// Lesson3 - canonical.hpp
	Sample instance1;
	Sample instance2(42);
	Sample instance3(instance1);
	
	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;
	std::cout << instance3 << std::endl;

	return 0;
}
