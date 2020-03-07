/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:21:07 by hypark            #+#    #+#             */
/*   Updated: 2020/03/07 00:12:51 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void swap(struct s_art **art1, struct s_art **art2)
{
	struct s_art *temp;

	temp = *art1;
	*art1 = *art2;
	*art2 = temp;
}

void maxHeapify(struct s_maxHeap *heap, int i)
{
	int max = i;
	int left = (i << 1) + 1;
	int right = (i + 1) << 1;

	if (left < heap->size)
		if (strcmp(heap->arr[left]->name, heap->arr[max]->name) > 0)
			max = left;
	if (right < heap->size)
		if (strcmp(heap->arr[right]->name, heap->arr[max]->name) > 0)
			max = right;
	if (max != i)
	{
		swap(&(heap->arr[max]), &(heap->arr[i]));
		maxHeapify(heap, max);
	}
}

struct s_maxHeap *createHeap(struct s_art **masterpiece, int size)
{
	struct s_maxHeap *heap;

	heap = (struct s_maxHeap *)malloc(sizeof(struct s_maxHeap));
	heap->arr = masterpiece;
	heap->size = size;

	for (int i = (heap->size - 2) / 2; i >= 0; --i)
		maxHeapify(heap, i);
	return heap;
}

void heapSort(struct s_art **masterpiece, int n)
{
	struct s_maxHeap *heap;

	heap = createHeap(masterpiece, n);
	while (heap->size > 1)
	{
		swap(&(heap->arr[0]), &(heap->arr[heap->size - 1]));
		heap->size--;
		maxHeapify(heap, 0);
	}
}
