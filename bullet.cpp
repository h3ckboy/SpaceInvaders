#include "bullet.hpp"
#include "display.hpp"
#include <iostream>

Bullet::Bullet(float ix, float iy,float idy)
{
	x = ix;
	y = iy;
	dy = idy;
}

Bullet::Bullet()
{
	x = 0;
	y = -1;
	dy = 0;
}

void Bullet::render()
{
	if(dy!=0)disp::draw(x,y,0.1,0.1,0);
}

void Bullet::act(double delta)
{
	y+= dy*delta*100;

	if(y>1)dy = 0;
}

bool Bullet::collide(Enemy& e)
{
	return e.collide(*this);
}

float Bullet::getX(){return x;}
float Bullet::getY(){return y;}
