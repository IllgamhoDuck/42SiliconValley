/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:27:52 by hypark            #+#    #+#             */
/*   Updated: 2019/08/20 18:35:14 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void				fill_mtime(t_file *file, char *time)
{
	ft_strncpy(file->mmonth, time + 4, 3);
	ft_strncpy(file->mday, time + 8, 2);
	ft_strncpy(file->myear, time + 20, 4);
	ft_strncpy(file->mmtime, time + 11, 5);
	file->mmonth[3] = '\0';
	file->mday[2] = '\0';
	file->myear[4] = '\0';
	file->mmtime[5] = '\0';
}

void				fill_atime(t_file *file, char *time)
{
	ft_strncpy(file->amonth, time + 4, 3);
	ft_strncpy(file->aday, time + 8, 2);
	ft_strncpy(file->ayear, time + 20, 4);
	ft_strncpy(file->aatime, time + 11, 5);
	file->amonth[3] = '\0';
	file->aday[2] = '\0';
	file->ayear[4] = '\0';
	file->aatime[5] = '\0';
}
