#include "enemy.hpp"
#include "display.hpp"

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
	disp::render((int)x,(int)y,"[--]");
}


