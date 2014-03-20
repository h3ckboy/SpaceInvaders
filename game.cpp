#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ofstream cout("log");

class Player{
	int x, y;
	public:
		Player(int x, int y);
		void key(int c);
		void render();
} player(30,20);



Player::Player(int ix, int iy)
{
	x = ix;
	y = iy;
}

void Player::key(int c)
{
	switch(c)
	{
		case KEY_LEFT:
			x--;
		break;
		case KEY_RIGHT:
			x++;
		break;
	}
}

void Player::render()
{
	mvaddstr(y,x,"===");
	
}

class Enemy{
	float x,y;
	static float dx,dy;

	public:
		Enemy(int ix, int iy);
		void act();
		void render();
};

float Enemy::dx = 0.05;

Enemy::Enemy(int ix, int iy)
{
	x = (float)ix;
	y = (float)iy;
}

void Enemy::act()
{
	x += dx;
	if(x > 50 || x< 0)dx *= -1;
}

void Enemy::render()
{
	mvaddstr((int)y,(int)x,"[--]");
}

void init_curses()
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
}
int main()
{
	
	init_curses();
	int ch;
	long double acttime = time(0);
	vector<Enemy> enemies;
	for(int i = 1;i < 4; i++)
	{
		Enemy e(5*i,5);
		enemies.push_back(e);
	}
	while((ch=getch())!='q')
	{
		clear();
		player.key(ch);
		player.render();
		for_each(enemies.begin(),enemies.end(),[&](Enemy& e) {e.act();e.render();});
		refresh();
		nanosleep((struct timespec[]){{0, 5000000}}, NULL);
	}
	endwin();
}
