/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:50:45 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 19:59:39 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
	private:
		std::string _login;

	public:
		Student(std::string login) : _login(login) 
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}

		~Student()
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
};

class Students
{
	private:
		std::string _login;

	public:
		Students() : _login("ldefault") 
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}

		~Students()
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
};

int main()
{
	Student		bob = Student("bfubar");
	Student*	jim = new Student("jfubar");
	Students*	students = new Students[42];

	// Do some stuff here
	
	delete jim; //jim is destroyed
	delete [] students;

	return (0); // bob is destroyed
}
