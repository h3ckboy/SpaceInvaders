#ifndef INC_ENEMY_H
#define INC_ENEMY_H

#include <string> 
#include <ctime>
class Bullet;

class Enemy{
	private:
		float x,y;
		static float dx,dy;
		static int dr;
		bool destroyed;
		std::string sprite;
		//Bullet* bullet;
		int shot_offset;
		//std::clock_t start;
	public:
		Enemy(int ix, int iy, std::string isprite);
		~Enemy();
		void act();
		void render();
		bool collide(Bullet& b);
		void setString(std::string str);
};
#endif
