/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:44:49 by hypark            #+#    #+#             */
/*   Updated: 2019/09/09 22:47:02 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void				free_str(char **str)
{
	int				i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}
