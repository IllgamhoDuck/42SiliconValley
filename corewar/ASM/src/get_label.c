/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:21:13 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/17 09:21:08 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Checks if the label is properly formated with only LABEL_CHARS.
*/

static int	is_invalid_label(char *label, int len)
{
	if (len > LABEL_NAME_LENGTH)
		return (1);
	while (*label)
	{
		if (!ft_strchr(LABEL_CHARS, *label))
			return (1);
		label++;
	}
	return (0);
}

/*
** Gets label from first item of elem by taking what comes before LABEL_CHAR.
** Verifies that label if properly formatted with LABEL_CHARS.
** Allocate label struct, fill it with name and offset and assign it
** to new_label. We get the offset by looking at global.
*/

t_error		get_label(t_label **new_label, char **elem)
{
	char	*label_char;
	size_t	len;
	t_label	*new;
	char	*name;

	label_char = ft_strchr(elem[0], LABEL_CHAR);
	if (!label_char)
	{
		*new_label = NULL;
		return (NULL);
	}
	new = malloc(sizeof(t_label));
	if (!new)
		return (ft_strdup(RED"could not allocate t_label"RESET));
	new->offset = g_offset;
	ft_bzero(new->name, LABEL_NAME_LENGTH + 1);
	*new_label = new;
	len = label_char - elem[0];
	ft_strncpy(new->name, elem[0], len);
	if (ft_isalpha(elem[0][len + 1]) || ft_isdigit(elem[0][len + 1]))
		return (ft_strjoin(elem[0], "\x1b[91m is invalid.\x1b[0m"));
	if (is_invalid_label(new->name, len))
		return (ft_strjoin(RED"label name is invalid: "RESET, name));
	return (NULL);
}
