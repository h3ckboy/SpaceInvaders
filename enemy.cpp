#include "enemy.hpp"
#include "display.hpp"
#include "bullet.hpp"
#include <fstream>

float Enemy::dx = 0.05;

std::ofstream o("log");	


Enemy::Enemy(int ix, int iy)
{
	x = (float)ix;
	y = (float)iy;
	o << sprite << '\n';
	sprite = "[---]";
	o << sprite << '\n';
}

void Enemy::act()
{
	o << sprite << '\n';
	x += dx;
	if(x > 50 || x< 0)dx *= -1;
}

void Enemy::render()
{
	disp::render((int)x,(int)y,sprite.c_str());
}

bool Enemy::collide(Bullet b)
{
	o << sprite << '\n';
	if(b.getX() >= x && b.getX() <= x + sprite.size()&& b.getY() == y)
	{
		sprite = "broke";
		dx = 0;
		return true;
	}
	return false;
}

