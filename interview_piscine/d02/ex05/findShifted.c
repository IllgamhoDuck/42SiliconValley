/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:06:11 by hypark            #+#    #+#             */
/*   Updated: 2020/02/28 00:14:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

//static int findPivot(int *rocks, int start, int end)
//{
//	int mid;
//
//	if (start > end)
//		return -1;
//	if (start == end)
//		return start;
//	mid = (start + end)/2;
//	if (mid < end && rocks[mid] > rocks[mid + 1])
//		return mid;
//	if (mid > start && rocks[mid - 1] > rocks[mid])
//		return mid - 1;
//	if (rocks[start] > rocks[mid])
//		return findPivot(rocks, start, mid - 1);
//	if (rocks[mid] > rocks[end])
//		return findPivot(rocks, mid + 1, end);
//}
//
//int	searchShifted(int *rocks, int length, int value)
//{
//	
//}
