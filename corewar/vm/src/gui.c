#include "vm.h"

static void     fill_map(WINDOW *win)
{
	int x;
	int y;

	x = -2;
	y = 1;

	while (y != MAX_Y)
	{
	   if (x == MAX_X - 2)
		{
			x = -2;
			y++;
		}
		else {
		x += 3;
		mvwprintw(win, y, x, "00");
		}
	}
}

static WINDOW            *init_screen(WINDOW *win, int max_x, int y, int x)
{
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);
	win = newwin(MAX_Y + 1, max_x, y, x);
	nodelay(win, true);
	box(win, 0, 0);
	keypad(win, true);
	if (x == 1)
		fill_map(win);
	return (win);
}

char                    update_screen(WINDOW *win)
{
	char	key;
	
	usleep(2500);
	clear();
	wrefresh(win);
	key = wgetch(win);
	if (key == ESC)
	{
		endwin();
		exit(0);
	}
	return (key);
}

static void            print_info(t_cw *cw, t_gui *gui)
{
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	wattron(gui->win, COLOR_PAIR(9));
	mvwprintw(gui->win_info, 1, 1, "Cycle: %d", cw->cycle.cycle);
	mvwprintw(gui->win_info, 2, 1, "Speed: x%u", gui->speed);
	mvwprintw(gui->win_info, 3, 1, "Kill cycle: %d", cw->cycle.kill_cycle);
	wattroff(gui->win, COLOR_PAIR(9));
}

static void    memory_gui_update(t_cw *cw, t_gui *gui)
{
	int                 i;
	int                 x;
	int                 y;

	i = 0;
	x = -2;
	y = 1;
	int color[4] = {COLOR_YELLOW, COLOR_GREEN, COLOR_RED, COLOR_MAGENTA};
	while (i < MEM_SIZE)
	{
		if (x == MAX_X - 2)
		{
			x = -2;
			++y;
		}
		x += 3;
		if (cw->owner[i] != -1)
		{
			init_pair(cw->owner[i] + 2, color[cw->owner[i]], COLOR_BLACK);
			wattron(gui->win, COLOR_PAIR(cw->owner[i] + 2));
			mvwprintw(gui->win, y, x, "%02x", cw->memory[i]);
			wattroff(gui->win, COLOR_PAIR(cw->owner[i] + 2));
		}
		++i;
	}
}

void                   gui_update(t_cw *cw)
{
	char key1;
	char key2;

	key1 = update_screen(cw->gui.win);
	key2 = update_screen(cw->gui.win_info);
	(void)key1;
	(void)key2;
	print_info(cw, &cw->gui);
    memory_gui_update(cw, &cw->gui);
}

void            gui_init(t_cw *cw)
{
	cw->gui.win = init_screen(cw->gui.win, MAX_X + 1, 1, 1);
	cw->gui.win_info = init_screen(cw->gui.win_info, 30, 1, MAX_X + 2);
	cw->gui.speed = 1;
}