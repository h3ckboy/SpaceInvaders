#include "display.hpp"
#include <ncurses.h>



namespace disp{

const int LEFT = KEY_LEFT;
const int RIGHT = KEY_RIGHT;
int WIDTH;
int HEIGHT;

void render(int x, int y, std::string str)
{
	mvaddstr(y,x,str.c_str());
}

void init()
{
	initscr();
	noecho();
	printw("Press Enter to Start!");
	getch();
	clear();
	refresh();
	cbreak();
	nodelay(stdscr,TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr,HEIGHT,WIDTH);
}

void close()
{
	endwin();
}

void show()
{
	refresh();
	clear();
}

int key()
{
	return getch();
}
}
