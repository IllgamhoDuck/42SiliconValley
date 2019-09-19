/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:17:08 by hypark            #+#    #+#             */
/*   Updated: 2019/09/19 03:06:59 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <fcntl.h>

static int64_t g_step = 0;
static int32_t g_first_ant = 0;
static int32_t g_reached_ant = 0;

static t_queue		*get_path(t_ant *ant, int32_t path_i)
{
	t_queue			*q;

	q = ant->queue;
	while (--path_i >= 0)
		q = q->next;
	return (q);
}

static void			move_ants(t_ant *ant, t_deploy *deploy, int32_t path_i)
{
	int64_t			ant_i;
	int64_t			index;
	t_queue			*q;

	ant_i = -1;
	q = get_path(ant, path_i);
	while (++ant_i < deploy->ant_deploy[path_i])
	{
		index = g_step - ant_i;
		if (index >= 0 && index < q->len - 1)
		{
			index += 1;
			g_first_ant ? 0 : ft_putchar(' ');
			ft_printf("L%d-", ant_i + deploy->start_num[path_i]);
			ft_printf("%s", ant->adj_list[q->path[index]].room_name);
			g_first_ant = 0;
			if (q->path[index] == ant->end_room->i)
				g_reached_ant++;
		}
	}
}

static void			march_ants(t_ant *ant, t_deploy *deploy)
{
	int32_t			path_i;

	while (1)
	{
		g_first_ant = 1;
		path_i = -1;
		while (++path_i < ant->path_number)
			move_ants(ant, deploy, path_i);
		ft_putchar('\n');
		if (g_reached_ant == ant->ant_number)
		{
			ft_printf("total step : %d\n", g_step + 1);
			break ;
		}
		g_step++;
	}
}

int					main(void)
{
	t_ant			*ant;
	t_deploy		*deploy;

	ant = init_ant();
	read_file(ant);
	search_path(ant);
	deploy = deploy_ant(ant);
	compress_line(ant);
	print_line(ant->line);
	march_ants(ant, deploy);
	free_deploy(deploy);
	free_ant(ant);
	return (0);
}
