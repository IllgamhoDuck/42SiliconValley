/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 02:38:36 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 02:44:34 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


// case 1 print out ls -l symbolic as just a file, but if not a -l just do it
// case 2 print out the file names at the first. 
// -> split the ls to the file ones and directory ones
// -> and print out the files as normal and sent the folder to normal
// -> and case 1 will be treated at there
