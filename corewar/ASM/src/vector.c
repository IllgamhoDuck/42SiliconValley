/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:22:27 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/15 21:28:01 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <assembler.h>

static void				vector_resize(t_vector *v, int capacity)
{
	void		**items;

	items = realloc(v->items, sizeof(void *) * capacity);
	if (items)
	{
		v->items = items;
		v->capacity = capacity;
	}
}

void					vector_add(t_vector *v, void *item)
{
	if (v->capacity <= v->size)
		vector_resize(v, v->capacity * 2);
	v->items[v->size++] = item;
}

void					vector_delete(t_vector *v, int index)
{
	int			i;

	if (index < 0 || index >= v->size)
		return ;
	v->items[index] = NULL;
	i = index;
	while (i < v->size - 1)
	{
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
		i++;
	}
	v->size--;
	if (v->size > 0 && v->size == v->capacity / 4)
		vector_resize(v, v->capacity / 2);
}

void					vector_free(t_vector *v)
{
	int	i;

	i = -1;
	while (++i < v->size)
	{
		free(v->items[i]);
	}
	free(v->items);
}
