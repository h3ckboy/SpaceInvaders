//#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
#include "display.hpp"
#include "player.hpp"
#include "enemy.hpp"

using namespace std;

ofstream cout("log");

Player player(30,20);

int main()
{
	
	disp::init();
	int ch;
	long double acttime = time(0);
	vector<Enemy> enemies;
	for(int i = 1;i < 4; i++)
	{
		Enemy e(5*i,5);
		enemies.push_back(e);
	}
	while((ch=disp::key())!='q')
	{
		player.key(ch);
		player.render();
		for_each(enemies.begin(),enemies.end(),[&](Enemy& e) {e.act();e.render();});
		disp::show();
		nanosleep((struct timespec[]){{0, 5000000}}, NULL);
	}
	disp::close();
}
