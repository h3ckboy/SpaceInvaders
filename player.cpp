#include "player.hpp"
#include "display.hpp"

Player::Player(int ix, int iy)
{
	x = ix;
	y = iy;
}

void Player::key(int c)
{
	if(c==disp::LEFT)
		x--;
	else if(c==disp::RIGHT)
		x++;
}

void Player::render()
{
	disp::render(x,y,"===");
	
}

