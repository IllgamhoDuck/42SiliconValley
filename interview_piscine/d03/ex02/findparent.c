/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findparent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:11:53 by hypark            #+#    #+#             */
/*   Updated: 2020/02/28 23:34:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

static int search_parent(struct s_node **ancestor, struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	int species_score = 0;
	int i = -1;

	while (root->children[++i])
		species_score += search_parent(ancestor, root->children[i], firstSpecies, secondSpecies);
	if (species_score == 3)
	{
		*ancestor = root;
		return -1;
	}
	if (strcmp(root->name, firstSpecies) == 0)
		return 1 + species_score;
	if (strcmp(root->name, secondSpecies) == 0)
		return 2 + species_score;
	return 0 + species_score;
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *ancestor = NULL;

	if (root == NULL)
		return NULL;
	search_parent(&ancestor, root, firstSpecies, secondSpecies);
	return ancestor;
}
