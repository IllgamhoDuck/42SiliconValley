/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:44:41 by hypark            #+#    #+#             */
/*   Updated: 2019/09/19 01:30:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void			fill_spare_room(t_ant *ant, t_deploy *deploy)
{
	int32_t			max_path_len;
	int32_t			i;
	t_queue			*q;

	max_path_len = -1;
	q = ant->queue;
	while (q)
	{
		if (q->len > max_path_len)
			max_path_len = q->len;
		q = q->next;
	}
	q = ant->queue;
	i = -1;
	while (q)
	{
		deploy->spare_room[++i] = max_path_len - q->len;
		q = q->next;
	}
}

static void			deploy_rest(t_ant *ant, t_deploy *deploy, uint64_t total)
{
	int32_t			i;
	int32_t			add_ant;

	add_ant = total / ant->path_number;
	i = -1;
	while (++i < ant->path_number)
	{
		deploy->ant_deploy[i] += add_ant;
		total -= add_ant;
	}
	i = -1;
	while (++i < ant->path_number && total)
	{
		deploy->ant_deploy[i] += 1;
		total -= 1;
	}
}

static void			fill_deploy_ant(t_ant *ant, t_deploy *deploy)
{
	int32_t			i;
	int64_t			total;

	total = ant->ant_number;
	i = -1;
	while (++i < ant->path_number)
	{
		if (deploy->spare_room[i] >= total)
		{
			deploy->ant_deploy[i] = total;
			return ;
		}
		deploy->ant_deploy[i] = deploy->spare_room[i];
		total -= deploy->spare_room[i];
	}
	if (total)
		deploy_rest(ant, deploy, total);
}

static void			fill_start_num(t_ant *ant, t_deploy *deploy)
{
	int32_t			i;
	int32_t			j;

	i = -1;
	while (++i < ant->path_number)
	{
		if (deploy->ant_deploy[i])
		{
			j = i;
			while (--j >= 0)
				deploy->start_num[i] += deploy->ant_deploy[j];
			deploy->start_num[i] += 1;
		}
	}
}

t_deploy			*deploy_ant(t_ant *ant)
{
	t_deploy		*deploy;

	deploy = init_deploy(ant->path_number);
	fill_spare_room(ant, deploy);
	fill_deploy_ant(ant, deploy);
	fill_start_num(ant, deploy);
	return (deploy);
}