#include "enemy.hpp"
#include "display.hpp"
#include "bullet.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

float Enemy::dx = 0.05;


Enemy::Enemy(int ix, int iy)
{
	x = (float)ix;
	y = (float)iy;
	sprite = "[---]";
	destroyed = false;
}

void Enemy::act()
{
	if(destroyed)
	{
	}else{
		x += dx;
		if(x > 50 || x< 0)dx *= -1;
	}
}

void Enemy::render()
{
	disp::render((int)x,(int)y,sprite.c_str());
}

void Enemy::setString(std::string str)
{
	sprite = str;
}

bool Enemy::collide(Bullet& b)
{
	if(b.getX() >= x && b.getX() <= x + sprite.size()&& b.getY() == y)
	{
		destroyed = true;
		setString("");
		return true;
	}
	return false;
}

