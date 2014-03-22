#ifndef INC_ENEMY_H
#define INC_ENEMY_H

#include <string> 

class Bullet;

class Enemy{
	private:
		float x,y;
		static float dx,dy;
		std::string sprite;
	public:
		Enemy(int ix, int iy);
		void act();
		void render();
		bool collide(Bullet b);
};
#endif
