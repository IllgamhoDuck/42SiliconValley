/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:10:09 by hypark            #+#    #+#             */
/*   Updated: 2020/02/28 22:58:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

/*
** divide and conquer approach
*/

struct s_node *init_node(int value)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void add_node(struct s_node **root, int value)
{
	struct s_node *node;

	if (*root == NULL)
	{
		*root = init_node(value);
		return ;
	}
	node = *root;
	while (1)
	{
		if (node->value >= value)
		{
			if (node->left)
				node = node->left;
			else
			{
				node->left = init_node(value);
				return ;
			}
		}
		else
		{
			if (node->right)
				node = node->right;
			else
			{
				node->right = init_node(value);
				return ;
			}
		}
	}
}

void divide_and_conquer(struct s_node **root, int *arr, int start, int end)
{
	int mid;

	if (start > end)
		return ;
	if (start == end)
	{
		add_node(root, arr[start]);
		return ;
	}
	mid = (start + end)/2;
	add_node(root, arr[mid]);
	divide_and_conquer(root, arr, start, mid - 1);
	divide_and_conquer(root, arr, mid + 1, end);
}

struct s_node *createBST(int *arr, int n)
{
	struct s_node *root;

	root = NULL;
	divide_and_conquer(&root, arr, 0, n - 1);
	return root;
}
