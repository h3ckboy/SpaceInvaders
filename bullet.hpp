#ifndef INC_BULLET_HPP
#define INC_BULLET_HPP

#include "enemy.hpp"

class Bullet{
	float x, y,dx,dy;
	public:
		Bullet();
		Bullet(float x, float y, float dy);
		void render();
		void act(double delta);
		bool collide(Enemy& e);
		float getX();
		float getY();
};

#endif
