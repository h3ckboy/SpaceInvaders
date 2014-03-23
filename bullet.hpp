#ifndef INC_BULLET_HPP
#define INC_BULLET_HPP

#include "enemy.hpp"

class Bullet{
	float x, y,dx,dy;
	public:
		Bullet();
		Bullet(int x, int y, float dy);
		void render();
		void act();
		bool collide(Enemy& e);
		int getX();
		int getY();
};

#endif
