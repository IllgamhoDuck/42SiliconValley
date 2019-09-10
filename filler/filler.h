/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:04:26 by hypark            #+#    #+#             */
/*   Updated: 2019/09/09 23:01:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_filler
{
	uint8_t			player;
	uint8_t			x;
	uint8_t			y;
	int32_t			**map;
}					t_filler;

void				process_file(t_filler *filler);

t_filler			*init_filler(void);

void				free_str(char **str);

#endif
