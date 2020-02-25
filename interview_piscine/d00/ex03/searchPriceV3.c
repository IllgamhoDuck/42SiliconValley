/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:38:41 by hypark            #+#    #+#             */
/*   Updated: 2020/02/24 23:37:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

//return hash result
size_t hash(char *input)
{
	int		c;
	size_t	hash = 5381;

	while ((c = *input++))
		hash = ((hash << 5) + hash) + c;
	return hash % 95000;
}

//initialize the dictionnary, given as parameter the capacity of the array.
struct s_dict *dictInit(int capacity)
{
	struct s_dict	*dict;
	int				i;

	dict = (struct s_dict *)malloc(sizeof(struct s_dict));
	dict->items = (struct s_item **)malloc(sizeof(struct s_item *)*capacity);
	dict->capacity = capacity;

	i = -1;
	while (++i < capacity)
		dict->items[i] = NULL;
	return dict;
}

//add one element in the dictionnary, if FAIL return 0, otherwise 1
int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item	*item;
	struct s_item	*node;
	size_t			hash_i;

	if ((item = (struct s_item *)malloc(sizeof(struct s_item))) == NULL)
		return 0;
	item->key = key;
	item->value = value;
	item->next = NULL;

	hash_i = hash(key);
	node = dict->items[hash_i];
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = item;
	}
	else
		dict->items[hash_i] = item;
	return 1;
}

//find one element in the dictionnary, if not found, return NULL
struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*item;
	size_t			hash_i;

	hash_i = hash(key);
	item = dict->items[hash_i];

	if (item == NULL)
		return NULL;
	if (strcmp(item->key, key) == 0)
		return item->value;
	while (item->next)
	{
		item = item->next;
		if (strcmp(item->key, key) == 0)
			return item->value;
	}
	return NULL;
}

// OTHER
int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*art;

	art = dictSearch(dict, name);
	if (art == NULL)
		return -1;
	return art->price;
}
