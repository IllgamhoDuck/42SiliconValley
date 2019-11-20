/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:28:01 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/13 22:20:58 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static WINDOW			*init_screen(WINDOW *win, int max_xy[2], int xy[2])
{
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);
	win = newwin(max_xy[1], max_xy[0], xy[1], xy[0]);
	nodelay(win, true);
	init_pair(17, COLOR_WHITE, COLOR_WHITE);
	wattron(win, COLOR_PAIR(17));
	wattron(win, A_BOLD);
	box(win, 0, 0);
	wattroff(win, A_BOLD);
	wattroff(win, COLOR_PAIR(17));
	keypad(win, true);
	return (win);
}

static void				update_screen(t_cw *cw, t_gui *gui, WINDOW *win)
{
	int		key;

	clear();
	wrefresh(win);
	key = wgetch(win);
	if (key == ESC)
	{
		endwin();
		exit(0);
	}
	else if (key == KEY_LEFT)
		SPEED = (SPEED >= MIN_SPEED) ? MAX_SPEED : SPEED * 10;
	else if (key == KEY_RIGHT)
		SPEED = (SPEED <= MAX_SPEED) ? MIN_SPEED : SPEED / 10;
	else if (key == KEY_D)
		dump_memory(cw);
	else if (key == SPACE)
		pause_game(cw, gui, win);
	print_gui_info(cw, &cw->gui);
	usleep(SPEED);
}

void					info_print(t_cw *cw, t_gui *gui, char *winner)
{
	mvwprintw(INFO, 12, 1, "Current Cycle: %d", cw->cycle.cycle);
	mvwprintw(INFO, 14, 1, "Speed: %0.1lf", 6.0 - log10(gui->speed));
	mvwprintw(INFO, 16, 1, "CYCLE TO DIE: %d", cw->cycle.kill_cycle);
	mvwprintw(INFO, 18, 1, "CYCLE DELTA: %d", CYCLE_DELTA);
	mvwprintw(INFO, 20, 1, "                                          ");
	mvwprintw(INFO, 20, 1, "Current winner: %s", winner);
	mvwprintw(INFO, 22, 1, "Number of processes: %u", cw->process_index - 1);
	mvwprintw(INFO, 24, 1, "List of commands:");
	mvwprintw(INFO, 25, 4, "- Right Arrow: Increase speed.");
	mvwprintw(INFO, 26, 4, "- Left Arrow: Decrease speed.");
	mvwprintw(INFO, 27, 4, "- Space: Pause/play VM.");
	mvwprintw(INFO, 28, 4, "- Escape: Quit game.");
	mvwprintw(INFO, 29, 4, "- d key: Quit game and dump memory.");
}

void					gui_update(t_cw *cw)
{
	update_screen(cw, &cw->gui, cw->gui.win);
	update_screen(cw, &cw->gui, cw->gui.win_info);
	update_screen(cw, &cw->gui, cw->gui.win_title);
	print_gui_title(cw, &cw->gui);
	print_gui_info(cw, &cw->gui);
	memory_gui_update(cw, &cw->gui);
}

void					gui_init(t_cw *cw)
{
	int		max_xy[2];
	int		xy[2];

	max_xy[1] = MAX_Y + 2;
	max_xy[0] = MAX_X + 1;
	xy[0] = 1;
	xy[1] = 12;
	cw->gui.win = init_screen(cw->gui.win, max_xy, xy);
	max_xy[1] = 31;
	max_xy[0] = 45;
	xy[0] = MAX_X + 2;
	xy[1] = 1;
	cw->gui.win_info = init_screen(cw->gui.win_info, max_xy, xy);
	max_xy[1] = 11;
	max_xy[0] = MAX_X + 1;
	xy[0] = 1;
	xy[1] = 1;
	cw->gui.win_title = init_screen(cw->gui.win_title, max_xy, xy);
	wattron(cw->gui.win, A_BOLD);
	cw->gui.speed = MIN_SPEED / 10;
}
