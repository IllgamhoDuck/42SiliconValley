/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:22:28 by hypark            #+#    #+#             */
/*   Updated: 2019/11/13 22:07:37 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ----------------------------------------------------------------------------
** Print in one block of hexadecimal.
**
** {unsigned char} c - Number to print in base 16.
** ----------------------------------------------------------------------------
*/

void					h_puthex(unsigned char c)
{
	static char	*base = "0123456789abcdef";

	ft_printf("%c", base[c / 16]);
	ft_printf("%c", base[c % 16]);
}

/*
** ----------------------------------------------------------------------------
** Print current state of memory to stdout.
**
** {t_cw *} cw - Main structure of the vm.
** ----------------------------------------------------------------------------
*/

void					print_memory(t_cw *cw)
{
	int			i;
	unsigned	siz;

	i = 0;
	siz = (unsigned)sqrt(MEM_SIZE);
	while (i < MEM_SIZE)
	{
		if (i % siz == 0)
		{
			if (i)
				ft_printf("\n");
			if (i == 0)
				ft_printf("0x0000 : ");
			else
				ft_printf("%#06x : ", i);
		}
		h_puthex(cw->memory[i]);
		ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

void					print_gui_title(t_cw *cw, t_gui *gui)
{
	(void)cw;
	wattron(TITLE, A_BOLD);
	mvwprintw(TITLE, 1, 60, "  /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$ /\
$$      /$$  /$$$$$$  /$$$$$$$ ");
	mvwprintw(TITLE, 2, 60, " /$$__  $$ /$$__  $$| $$__  $$| $$_____/| \
$$  /$ | $$ /$$__  $$| $$__  $$");
	mvwprintw(TITLE, 3, 60, "| $$  \\__/| $$  \\ $$| $$  \\ $$| $$      \
| $$ /$$$| $$| $$  \\ $$| $$  \\ $$");
	mvwprintw(TITLE, 4, 60, "| $$      | $$  | $$| $$$$$$$/| $$$$$   \
| $$/$$ $$ $$| $$$$$$$$| $$$$$$$/");
	mvwprintw(TITLE, 5, 60, "| $$      | $$  | $$| $$__  $$| $$__/   \
| $$$$_  $$$$| $$__  $$| $$__  $$");
	mvwprintw(TITLE, 6, 60, "| $$    $$| $$  | $$| $$  \\ $$| $$      \
| $$$/ \\  $$$| $$  | $$| $$  \\ $$");
	mvwprintw(TITLE, 7, 60, "|  $$$$$$/|  $$$$$$/| $$  | $$| $$$$$$$$| \
$$/   \\  $$| $$  | $$| $$  | $$");
	mvwprintw(TITLE, 8, 60, " \\______/  \\______/ |__/  |__/|________/\
|__/     \\__/|__/  |__/|__/  |__/");
	wattroff(TITLE, A_BOLD);
}

void					print_gui_info(t_cw *cw, t_gui *gui)
{
	char	*winner;

	winner = (ft_strlen(WINNER->name) > 25) ?
	ft_strsub(cw->winner->name, 0, 25) : ft_strdup(cw->winner->name);
	wrefresh(INFO);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	wattron(INFO, A_BOLD);
	wattron(INFO, COLOR_PAIR(9));
	mvwprintw(INFO, 1, 3, " /$$$$$$ /$$   /$$ /$$$$$$$$ /$$$$$$ ");
	mvwprintw(INFO, 2, 3, "|_  $$_/| $$$ | $$| $$_____//$$__  $$");
	mvwprintw(INFO, 3, 3, "  | $$  | $$$$| $$| $$     | $$  \\ $$");
	mvwprintw(INFO, 4, 3, "  | $$  | $$ $$ $$| $$$$$  | $$  | $$");
	mvwprintw(INFO, 5, 3, "  | $$  | $$  $$$$| $$__/  | $$  | $$");
	mvwprintw(INFO, 6, 3, "  | $$  | $$\\  $$$| $$     | $$  | $$");
	mvwprintw(INFO, 7, 3, " /$$$$$$| $$ \\  $$| $$     |  $$$$$$/");
	mvwprintw(INFO, 8, 3, "|______/|__/  \\__/|__/      \\______/ ");
	wattron(INFO, COLOR_PAIR(17));
	mvwprintw(INFO, 10, 1, "-------------------------------------------");
	mvwprintw(INFO, 11, 1, "-------------------------------------------");
	wattroff(INFO, COLOR_PAIR(17));
	info_print(cw, gui, winner);
	wattroff(INFO, COLOR_PAIR(9));
	free(winner);
}
