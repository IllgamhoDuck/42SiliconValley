/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:50:22 by hypark            #+#    #+#             */
/*   Updated: 2020/02/25 21:40:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

/*
** m : word length
** n : text length
** d : Number of characters in the alphabet
** q : A prime number
** h : d^(m-1)
**
** hash( txt[s+1 .. s+m] ) 
** = d( hash( txt[s .. s+m-1] ) - txt[s]*h ) + txt[s+m] ) % q
*/

int howManyJesus(char *bible, char *jesus)
{
	int		word_len = strlen(jesus);
	int		text_len = strlen(bible);
	int		i;
	int		j;
	int		word_hash = 0;
	int		text_hash = 0;
	int		h = 1;
	int		d = 256;
	int		q = 101;
	int		count = 0;
	
	if (word_len > text_len)
		return 0;
	i = -1;
	while (++i < word_len - 1)
		h = (h*d)%q;
	i = -1;
	while (++i < word_len)
	{
		word_hash = (d*word_hash + jesus[i])%q;
		text_hash = (d*text_hash + bible[i])%q;
	}
	i = -1;
	while (++i <= (text_len - word_len))
	{
		if (word_hash == text_hash)
		{
			j = -1;
			while (++j < word_len)
				if (jesus[j] != bible[i + j])
					break ;
			if (j == word_len)
				count++;
		}
		if (i < (text_len - word_len))
		{
			text_hash = (d*(text_hash - bible[i]*h) + bible[i + word_len])%q;
			if (text_hash < 0)
				text_hash += q;
		}
	}
	return count;
}
