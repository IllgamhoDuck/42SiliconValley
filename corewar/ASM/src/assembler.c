/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:19:57 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/15 10:53:42 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Translates assembly source file into a binary file for Corewar virtual
** machine.
*/

t_error		assembler(char *filename)
{
	t_error		err;
	t_champ		champ;
	t_vector	instructions;

	err = NULL;
	ft_memset(&champ, 0, sizeof(t_champ));
	VECTOR_INIT(&instructions);
	err = parser(&champ, filename);
	if (!err)
		err = lexer(&instructions, &champ);
	if (!err)
		err = write_file(&champ, &instructions);
	free(champ.fname);
	free(champ.name);
	free(champ.comment);
	free(champ.content);
	VECTOR_FREE(&instructions);
	if (err)
		return (err);
	return (NULL);
}
