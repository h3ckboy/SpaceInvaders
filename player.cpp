#include "player.hpp"
#include "display.hpp"
#include <iostream>

Player::Player(int ix, int iy)
{
	x = ix;
	y = iy;
	bullet = new Bullet();

}

void Player::key(int c)
{
	if(c==disp::LEFT)
		x-=3;
	else if(c==disp::RIGHT)
		x+=3;
	else if(c==' ')
		bullet = new Bullet(x,y-1,-0.05);
}

void Player::render()
{
	disp::render(x,y,"===");
	(*bullet).render();
}

void Player::act()
{
	(*bullet).act();
}

void Player::collide(Enemy e)
{
	if((*bullet).collide(e))bullet = new Bullet();
}

Player::~Player()
{
	delete bullet;
}

