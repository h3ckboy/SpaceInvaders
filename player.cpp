#include "player.hpp"
#include "display.hpp"
#include <iostream>


Player::Player(float ix, float iy)
{
	x = ix;
	y = iy;
	bullet = new Bullet();
}


void Player::render()
{
	disp::draw(x,y,WIDTH,HEIGHT,0);
	(*bullet).render();
}

void Player::act(double delta)
{
	dx=0;
	dy=0;
        if(disp::keys['D'])dx=SPEED;
        if(disp::keys['A'])dx=-SPEED;
	if(disp::keys[32])bullet = new Bullet(x+WIDTH/2,y,80);
	x+=dx*delta*100;
	y+=dy*delta*100;
	(*bullet).act(delta);
}

bool Player::collide(Enemy& e)
{
	if((*bullet).collide(e)){bullet = new Bullet();return true;}
	return false;
}

Player::~Player()
{
	delete bullet;
}

