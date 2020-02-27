/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:59:42 by hypark            #+#    #+#             */
/*   Updated: 2020/02/26 19:42:04 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <ctype.h> //isalnum

#include "header.h"

//return hash result
size_t hash(char *input)
{
	int		c;
	size_t	hash = 5381;

	while ((c = *input++))
		hash = ((hash << 5) + hash) + c;
	return hash % 230;
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
int	dictInsert(struct s_dict *dict, char *key, int value)
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
int dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*item;
	size_t			hash_i;

	hash_i = hash(key);
	item = dict->items[hash_i];

	if (item == NULL)
		return -1;
	if (strcmp(item->key, key) == 0)
		return item->value;
	while (item->next)
	{
		item = item->next;
		if (strcmp(item->key, key) == 0)
			return item->value;
	}
	return -1;
}

char **processWords(struct s_dict *dict, int *header_len)
{
	char	*word;
	struct s_item *item;
	char	**word_list;
	int		i;

	word_list = (char **)malloc(sizeof(char *) * (dict->capacity + 1));
	i = -1;
	while (++i < dict->capacity)
	{
		item = dict->items[i];
		if (item == NULL)
			continue ;
		while (item)
		{
			word = item->key;
			word_list[item->value] = strdup(word);
			*header_len += strlen(word) + 1;
			item = item->next;
		}
	}
	(*header_len)++;
	return word_list;
}

void add_header(char *cbook, char **word_list, int list_len)
{
	int		i;
	int		j;
	int		word_len;
	char	*word;

	i = 0;
	cbook[i++] = '<';
	j = -1;
	while (++j < list_len)
	{
		word = word_list[j];
		word_len = strlen(word);
		strncpy(cbook + i, word, word_len);
		i += word_len;
		if (j != list_len - 1)
			cbook[i++] = ',';
		else
			cbook[i++] = '>';
	}
}

char *compress(char *book, struct s_dict *dict)
{
	int		header_len = 0;
	int		book_len;
	int		cbook_len;
	char	*cbook;
	char	**word_list;
	int		i;
	int		j;
	int		word_len;
	char	*word;
	char	value;

	word_list = processWords(dict, &header_len);
	book_len = strlen(book);
	cbook_len = book_len + header_len;
	cbook = (char *)malloc(sizeof(char) * (cbook_len + 1));

	add_header(cbook, word_list, dict->capacity);
	i = header_len;
	j = -1;
	while (++j < book_len)
	{
		if (isalnum(book[j]))
		{
			word_len = 0;
			while (isalnum(book[j + word_len]))
				word_len++;
			word = strndup(book + j, word_len);
			value = dictSearch(dict, word);
			if (value == -1)
			{
				strncpy(cbook + i, book + j, word_len);
				j = j + word_len - 1;
				i = i + word_len;
			}
			else
			{
				cbook[i++] = '@';
				cbook[i++] = (char)(value + 1);
				j = j + word_len - 1;
			}
		}
		else
			cbook[i++] = book[j];
	}
	cbook[i] = '\0';
	cbook = (char *)realloc(cbook, i + 1);
	return cbook;
}


