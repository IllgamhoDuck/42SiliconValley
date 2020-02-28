/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:37:53 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 02:56:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>

class Logger
{
	private:
		std::string		_fileName;

		void			logToConsole(std::string const & message);
		void			logToFile(std::string const & message);
		std::string		makeLogEntry(std::string const & message);

	public:
		Logger(std::string fileName);
		~Logger(void);

		void			log(std::string const & dest, std::string const & message);
};

#endif
