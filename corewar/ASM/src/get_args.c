/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:20:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/17 09:20:25 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>
#include "../include/assembler.h"
#include "../include/op.h"
#include "../../libft/includes/libft.h"

#define TYPE(x)			inst->args[x].type
#define VALUE(x)		inst->args[x].value

/*
** Extensive function of fill_args, gets the value of the parameters.
*/

static t_error			get_value(t_instruction *inst, char *elem, int n)
{
	int				len;

	if (TYPE(n) == REG_CODE)
		VALUE(n) = ft_stoi(elem + 1);
	else if (TYPE(n) == DIR_CODE || (TYPE(n) == IND_CODE && elem[0] == ':'))
	{
		if (TYPE(n) == DIR_CODE && elem[1] == ':')
			elem += 1;
		if (elem[0] == ':')
		{
			len = ft_strlen(elem + 1);
			if (len > LABEL_NAME_LENGTH)
				return (ft_strjoin("reference is invalid: ", elem + 1));
			ft_strncpy(inst->args[n].label, elem + 1, len);
			VALUE(n) = 0;
		}
		else if (ft_isdigit(elem[1]) || elem[1] == '-')
			VALUE(n) = ft_stoi(elem + 1);
	}
	else if (TYPE(n) == IND_CODE && elem[0] != ':')
		VALUE(n) = ft_stoi(elem);
	if (TYPE(n) == REG_CODE && VALUE(n) > REG_NUMBER)
		return (ft_strdup(RED"Reg number is too big."RESET));
	return (NULL);
}

/*
** Extensive function of fill_args, gets the type and size of the parameters.
*/

static t_error			get_type(t_instruction *inst, char *elem,\
						int count, int n)
{
	if (!elem)
		return (ft_strdup(RED"Invalid parameter"RESET));
	if (elem[0] == 'r')
	{
		TYPE(count) = REG_CODE;
		inst->args[count].size = 1;
	}
	else if (elem[0] == '%')
		TYPE(count) = DIR_CODE;
	else if (ft_isdigit(elem[0]) ||
	(elem[0] == ':' || (elem[0] == '-' && ft_isdigit(elem[1]))))
		TYPE(count) = IND_CODE;
	if (TYPE(count) == IND_CODE || (TYPE(count) ==
				DIR_CODE && g_op_tab[n].thefuck == 1))
		inst->args[count].size = 2;
	else if (TYPE(count) == DIR_CODE && g_op_tab[n].thefuck == 0)
		inst->args[count].size = 4;
	else if (TYPE(count) != REG_CODE && TYPE(count) != DIR_CODE
	&& TYPE(count) != IND_CODE)
		return (ft_strjoin(elem, "\x1b[91m is not a valid parameter.\x1b[0m"));
	return (error_arg_check(TYPE(count), elem));
}

/*
** Fill inst strcuture for this line, get the size, value and type of
** the parameters before writing them into the '.s' file.
*/

static t_error			fill_arg(t_instruction *inst, char **elem,\
						int current, int n)
{
	int			count;
	int			tmp;
	t_error		err;

	err = NULL;
	count = 0;
	tmp = current;
	if (count_arg(&elem[current]) > g_op_tab[n].n_param)
		return (ft_strdup(RED"Number of parameters invalid"RESET));
	while (current < (tmp + g_op_tab[n].n_param))
	{
		err = get_type(inst, elem[current], count, n);
		if (err)
			return (err);
		err = get_value(inst, elem[current], count);
		if (err)
			return (err);
		current++;
		count++;
	}
	return (NULL);
}

/*
** Dispatches the labels name and sends its id (1 - 17) to fill_arg.
*/

static t_error			dispatch_arg(t_instruction *inst,\
						char **elem, int current)
{
	t_error		err;
	int			i;

	i = -1;
	err = NULL;
	while (++i < 16)
	{
		if (!ft_strcmp(elem[current], g_op_tab[i].name))
		{
			inst->n_args = g_op_tab[i].n_param;
			err = fill_arg(inst, elem, ++current, i);
			if (err)
				return (err);
			break ;
		}
	}
	return (NULL);
}

/*
** Gets the arguments of the instruction. First checks how many arguments are
** expected for this opcode, then tries to extract them from elem and verifies
** the formating. For each argument, we need to create a corresponding
** t_argument struct, and feed the label reference if appropriate, the type, the
** compiled size by looking at 'thefuck' in t_op struct and assigning its value
** in case it is not a reference.
*/

t_error					get_args(t_instruction *instruction, char **elem)
{
	t_error	err;
	int		i;

	err = NULL;
	i = -1;
	while (elem[1] && elem[++i])
	{
		if (elem[i + 1] && i == 0 && elem[i][ft_strlen(elem[i]) - 1] == ':')
			i++;
		if (elem[i])
		{
			err = dispatch_arg(instruction, elem, i);
			if (err)
				return (err);
			break ;
		}
	}
	if (!(elem[0][ft_strlen(elem[0]) - 1] == ':') && !elem[1])
		return (ft_strjoin(elem[0], "\x1b[91m is invalid.\x1b[0m"));
	return (NULL);
}
