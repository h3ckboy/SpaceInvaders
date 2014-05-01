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

vector<Enemy> enemies;

int main()
{
	
	disp::init();
	int ch;
	long double acttime = time(0);
	
	for(int i = 1;i < 10; i++)
	{
		Enemy e = Enemy(7*i,5, "[---]");
		enemies.push_back(e);
		e = Enemy(7*i,3,"(...)");
		enemies.push_back(e);
	}
	int enemy_left = enemies.size();
	while((ch=disp::key())!='q')
	{
		player.key(ch);
		player.act();
		player.render();
		for_each(enemies.begin(),enemies.end(),[&](Enemy& e) {if(player.collide(e))enemy_left--;e.act();e.render();});
		if(!enemy_left)break;
		disp::show();
		nanosleep((const struct timespec[]){{0, 5000000}}, NULL);
	}
	disp::close();
}
