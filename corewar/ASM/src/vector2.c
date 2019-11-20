/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:24:52 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/14 09:24:53 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void					vector_init(t_vector *v)
{
	v->capacity = VECTOR_INIT_CAPACITY;
	v->size = 0;
	v->items = malloc(sizeof(void *) * v->capacity);
}

int						vector_size(t_vector *v)
{
	return (v->size);
}

void					vector_set(t_vector *v, int index, void *item)
{
	if (index >= 0 && index < v->size)
		v->items[index] = item;
}

void					*vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->size)
		return (v->items[index]);
	return (NULL);
}
