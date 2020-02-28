/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:59:20 by hypark            #+#    #+#             */
/*   Updated: 2020/01/16 04:04:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include "Fixed.hpp"

int			is_space(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'; }
int			is_num(char c) { return c >= '0' && c <= '9'; }
int			is_braket(char c) { return c == ')' || c == '('; }
int			is_op(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

// Get number from stack
std::string	get_number(void)
{
	std::ifstream num_stack("number.stack");
	std::string number;
	
	std::getline(num_stack, number);
	num_stack.close();
	return number;
}

// Get operation from stack
std::string	get_op(void)
{
	std::ifstream op_stack("op.stack");
	std::string op;
	
	std::getline(op_stack, op);
	op_stack.close();
	return op;
}

// Parse information to the stack
void		parse_at_stack(std::string str)
{
	std::stringstream ss(str);
	std::ofstream num_stack("number.stack", std::ios::app);
	std::ofstream op_stack("op.stack", std::ios::app);

	char	c;

	// get one character by one
	while (ss.get(c))
	{
		if (is_space(c)) // ignore the isspace
			continue ;
		else if (is_braket(c) || is_op(c))
			op_stack << c << std::endl;
		else if (is_num(c))
			num_stack << c << std::endl;
	}
	std::cout << get_op() << std::endl;
	std::cout << get_number() << std::endl;
	num_stack.close();
	op_stack.close();
}

void		eval_expr(std::string str)
{
	// check is valid - braket / values / op
	// Parse the content to the file which will be used as stack
	parse_at_stack(str);
}

int			main(int ac, char **av)
{

	if (ac == 2)
		eval_expr(av[1]);
	else
		std::cout << "usage : ./eval_expr \" YOUR EVAL EXPRESS \"" << std::endl;

	return 0;
}
