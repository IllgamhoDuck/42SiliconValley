/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:37:33 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 03:13:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Logger.hpp"

Logger::Logger(std::string fileName) : _fileName(fileName)
{
	return ;
}
Logger::~Logger(void) {

	return ;
}

void		Logger::logToConsole(std::string const & message)
{
	std::cout << message;
}

void		Logger::logToFile(std::string const & message)
{
	std::ofstream ofs(this->_fileName, std::ios::app);
	ofs << message;	
	ofs.close();
}

std::string	Logger::makeLogEntry(std::string const & message)
{
	std::stringstream sstream;
	std::string new_log = "";
	std::time_t now = time(0);
	tm *ltm = localtime(&now);

	sstream << "[";
	sstream << 1900 + ltm->tm_year;
	sstream << "/";
	sstream << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
	sstream << "/";
	sstream << std::setw(2) << std::setfill('0') << ltm->tm_mday;
	sstream << "-";
	sstream << std::setw(2) << std::setfill('0') << 1 + ltm->tm_hour;
	sstream << ":";
	sstream << std::setw(2) << std::setfill('0') << 1 + ltm->tm_min;
	sstream << ":";
	sstream << std::setw(2) << std::setfill('0') << 1 + ltm->tm_sec;
	sstream << "] ";
	sstream << message << std::endl;
	return (sstream.str());
}

void		Logger::log(std::string const & dest, std::string const & message)
{
	typedef void (Logger::*logFunc)(std::string const & message);
	 
	logFunc f[2] = {&Logger::logToConsole, &Logger::logToFile};
	std::string	type[2] = {"console", "file"};
	int			i = -1;

	while (++i < 2)
	{
		if (type[i].compare(dest) == 0)
		{
			(this->*(f[i]))(this->makeLogEntry(message));
			break ;
		}
		if (i == 1)
			std::cout << "Invalid dest : " << dest << std::endl;

	}
}
