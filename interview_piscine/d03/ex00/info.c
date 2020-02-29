/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:16:07 by hypark            #+#    #+#             */
/*   Updated: 2020/02/28 19:56:24 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void tree_min_max(struct s_node *root, struct s_info *info)
{
	if (root == NULL)
		return ;
	if (root->value < info->min)
		info->min = root->value;
	if (root->value > info->max)
		info->max = root->value;
	if (root->left)
		tree_min_max(root->left, info);
	if (root->right)
		tree_min_max(root->right, info);
}

int tree_elements(struct s_node *root)
{
	int left = 0;
	int right = 0;

	if (root == NULL)
		return 0;
	if (root->left)
		left = tree_elements(root->left);
	if (root->right)
		right = tree_elements(root->right);
	return 1 + left + right;
}

int tree_height(struct s_node *root, int n)
{
	int left = 0;
	int right = 0;

	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return n;
	if (root->left)
		left = tree_height(root->left, n + 1);
	if (root->right)
		right = tree_height(root->right, n + 1);
	if (left >= right)
		return left;
	else
		return right;
}

int is_bst(struct s_node *root)
{
	int left = 1;
	int right = 1;

	if (root == NULL)
		return 1;
	if (root->left)
	{
		if (root->left->value > root->value)
			return 0;
		left = is_bst(root->left);
	}
	if (root->right)
	{
		if (root->right->value <= root->value)
			return 0;
		right = is_bst(root->right);
	}
	return left * right;
}

int is_balance(struct s_node *root)
{
	int left = 0;
	int right = 0;

	if (root == NULL)
		return 1;
	left = tree_height(root->left, 1);
	right = tree_height(root->right, 1);
	if (abs(left - right) <= 1 && is_balance(root->left) && is_balance(root->right))
		return 1;
	return 0;
}

struct s_info getInfo(struct s_node *root)
{
	struct s_info info;

	info.min = 2147483647;
	info.max = -2147483648;
	tree_min_max(root, &info);
	info.elements = tree_elements(root);
	info.height = tree_height(root, 1);
	info.isBST = is_bst(root);
	info.isBalanced = is_balance(root);
	return info;
}
