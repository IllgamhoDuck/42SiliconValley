/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream1.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:48:19 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 20:54:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream	ifs("numbers");
	unsigned int	dst;
	unsigned int	dst2;
	unsigned int	dst3;
	ifs >> dst >> dst2 >> dst3;

	std::cout << dst << " " << dst2 << " " << dst3 << std::endl;
	ifs.close();

	//-----------------------------
	
	std::ofstream 	ofs("test.out");

	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
}
