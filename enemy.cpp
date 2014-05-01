#include "enemy.hpp"
#include "display.hpp"
#include "bullet.hpp"
#include "util.hpp"

float Enemy::dx = 0.02;
int Enemy::dr = 0;


Enemy::Enemy(int ix, int iy, std::string isprite)
{
	x = (float)ix;
	y = (float)iy;
	sprite = isprite;
	destroyed = false;
}

Enemy::~Enemy()
{
}

void Enemy::act()
{
	if(destroyed)
	{
	}else{
		x += dx;
		if(x > 70 || x< 0){dx *= -1;dr++;}
	}
}

void Enemy::render()
{
	disp::render((int)x,(int)y+dr,sprite.c_str());
	//(*bullet).render();
}

void Enemy::setString(std::string str)
{
	sprite = str;
}

bool Enemy::collide(Bullet& b)
{
	if(b.getX() >= x && b.getX() <= x + sprite.size()&& b.getY() == y+dr)
	{
		destroyed = true;
		setString("");
		return true;
	}
	return false;
}

