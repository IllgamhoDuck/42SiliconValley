/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:02:18 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 20:08:23 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	int 		numberOfBalls = 42;

	int*		ballsPtr = &numberOfBalls;
	int&		ballsRef = numberOfBalls;
	//int&		ballsRef2 - reference variable cannot point nothing
	//because it is * const so it cannot change the address later on
	
	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;

	return (0);
};
