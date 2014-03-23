#include "bullet.hpp"
#include "display.hpp"

Bullet::Bullet(int ix, int iy,float idy)
{
	x = (float)ix;
	y = (float)iy;
	dy = idy;
}

Bullet::Bullet()
{
	x = 0;
	y = 0;
	dy = 0;
}

void Bullet::render()
{
	if(dy!=0)disp::render((int)x,(int)y,"|");
}

void Bullet::act()
{
	y+= dy;
	if(y<0)dy = 0;
}

bool Bullet::collide(Enemy& e)
{
	return e.collide(*this);
}

int Bullet::getX(){return (int)x;}
int Bullet::getY(){return (int)y;}
