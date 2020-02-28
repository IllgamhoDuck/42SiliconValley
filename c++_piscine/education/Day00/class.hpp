/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:22:07 by hypark            #+#    #+#             */
/*   Updated: 2020/01/13 22:50:10 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

class Sample {

	public:

		int		foo;

		Sample( void );
		~Sample( void );

		void	bar( void ) const;

		//static int		getNbInst( void );

//	private:
//
//		static int		_nbInst;
//
};

#endif
