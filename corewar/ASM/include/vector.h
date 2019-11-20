/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:14:03 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/14 16:57:39 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

# define VECTOR_INIT_CAPACITY		4

# define VECTOR_INIT(v)				vector_init(v)
# define VECTOR_ADD(v, item)		vector_add(v, (void *) item)
# define VECTOR_FREE(v)				vector_free(v)

typedef struct						s_vector
{
	void							**items;
	int								size;
	int								capacity;
}									t_vector;

int									vector_size(t_vector *v);
void								vector_init(t_vector *v);
void								vector_set(t_vector *v,
									int index, void *item);
void								*vector_get(t_vector *v, int index);
void								vector_add(t_vector *v, void *item);
void								vector_delete(t_vector *v, int index);
void								vector_free(t_vector *v);

#endif
