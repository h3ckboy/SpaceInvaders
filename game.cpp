//#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
#include "display.hpp"
#include "player.hpp"
#include "enemy.hpp"

using namespace std;


Player player(0,-0.8f);

vector<Enemy> enemies;

int main()
{
	
	if(!disp::init())return -1;
	int ch;
	long double acttime = time(0);
	
	for(int i = 1;i < 10; i++)
	{
		Enemy e = Enemy(-1 + 0.2*i,0);
		enemies.push_back(e);
	}
	int enemy_left = enemies.size();
	double last_time = disp::time();
	bool close = false;
	while(!close){
		double current = disp::time();
		double delta = current-last_time;

		player.act(delta);
		player.render();
		for_each(enemies.begin(),enemies.end(),[&](Enemy& e) {if(player.collide(e))enemy_left--;e.act(delta);e.render();});
		close = !disp::loop();
		last_time = disp::time();

	}
	disp::close();
}
