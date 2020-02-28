/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:42:35 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 03:03:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int 			main()
{
	Logger logger = Logger("duck.log");

	// write in console
	logger.log("console", "I am doing c++ piscine");
	logger.log("console", "and calcc both");
	logger.log("console", "and udacity 2 courses");
	logger.log("console", "and also tensornetworks");
	logger.log("console", "HELPPPPPPPPPPPPPPP");

	// write in file
	logger.log("file", "I am doing c++ piscine");
	logger.log("file", "and calcc both");
	logger.log("file", "and udacity 2 courses");
	logger.log("file", "and also tensornetworks");
	logger.log("file", "HELPPPPPPPPPPPPPPP");
	return 0;
}
