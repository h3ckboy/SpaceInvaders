#include "enemy.hpp"
#include "display.hpp"
#include "bullet.hpp"
#include "util.hpp"
#include <iostream>

float Enemy::dx = Enemy::SPEED;
int Enemy::dr = 0;


Enemy::Enemy(float ix, float iy)
{
	x = ix;
	y = iy;
	destroyed = false;
}

Enemy::~Enemy()
{
}

void Enemy::act(double delta)
{
	if(destroyed)
	{
	}else{
		float old_dx = dx;
		float* this_dx = &dx;
		if(x+WIDTH>1){this_dx= &old_dx;dx=-SPEED;dr++;}
		if(x<-1){dx=SPEED;dr++;}
		x += (*this_dx)*delta*100;
	}
}

void Enemy::render()
{
	disp::draw(x,y,WIDTH,HEIGHT,0);
	//(*bullet).render();
}

bool Enemy::collide(Bullet& b)
{
	if(b.getX() >= x && (b.getX() <= x + WIDTH)&& (b.getY() >= y+dr)&&(b.getY()<=y+dr+HEIGHT))
	{
		std::cout<<"asfasdf"<<std::endl;
		destroyed = true;
		return true;
	}
	return false;
}

