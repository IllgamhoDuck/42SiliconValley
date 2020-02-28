/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:43:39 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 02:17:39 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>

class Human
{
	private:
		void		meleeAttack(std::string const & target);
		void		rangedAttack(std::string const & target);
		void		intimidatingShout(std::string const & target);

	public:
		Human(void);
		~Human(void);

		void		action(std::string const & action_name, std::string const & target);
};

#endif
