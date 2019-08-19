/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:53:22 by hypark            #+#    #+#             */
/*   Updated: 2019/08/19 04:37:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

uint8_t				n_len(uint32_t n)
{
	uint8_t			len;

	len = 0;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

/*
** is_c_d distinguish what printing method should we take
** ======================= TOTAL LENGTH OF LINE ==========================
** =======================================================================
** is_c_d = 1 -> 10 + m_l + 1 + m_u + m_major + 1 + m_minor + date + file
** is_c_d = 0 -> 10 + m_l + 1 + m_u +		 max_group      + date + file
** =======================================================================
** m_l - max_link
** m_u - max_user
** m_g - max_group
** m_major - max_major
** m_minor - max_minor
*/

static void			c_d_max(t_file **f, t_p *p, uint32_t i)
{
	if (f[i]->mode == 'c' || f[i]->mode == 'b')
	{
		if (ft_strlen(f[i]->group) + n_len(f[i]->major) > p->m_major)
			p->m_major = ft_strlen(f[i]->group) + n_len(f[i]->major);
		if (n_len(f[i]->minor) > p->m_minor)
			p->m_minor = n_len(f[i]->minor);
	}
	else
	{
		if (n_len(f[i]->size) > p->m_minor)
			p->m_minor = n_len(f[i]->size);
	}
}

void				calculate_max(t_file **f, t_p *p, uint32_t len)
{
	uint32_t		i;

	i = 0;
	while (i < len)
	{
		if (n_len(f[i]->link) > p->m_l)
			p->m_l = n_len(f[i]->link);
		if (ft_strlen(f[i]->user) > p->m_u)
			p->m_u = ft_strlen(f[i]->user);
		if (p->is_c_d)
			c_d_max(f, p, i);
		else
			if (ft_strlen(f[i]->group) + n_len(f[i]->size) > p->m_g)
				p->m_g = ft_strlen(f[i]->group) + n_len(f[i]->size);
		i++;
	}
}

uint64_t			calculate_total(t_file **f, uint32_t len)
{
	uint32_t		i;
	uint64_t		total;

	i = 0;
	total = 0;
	while (i < len)
	{
		total += f[i]->block;
		i++;
	}
	return (total);
}
