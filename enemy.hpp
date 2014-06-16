#ifndef INC_ENEMY_H
#define INC_ENEMY_H

#include <ctime>
class Bullet;

class Enemy{
	private:
		float x,y;
		static float dx,dy;
		static constexpr float WIDTH = 0.2f;
		static constexpr float HEIGHT = 0.2f;
		static constexpr float SPEED = 30.f;
		static int dr;
		bool destroyed;
		//Bullet* bullet;
		int shot_offset;
		//std::clock_t start;
	public:
		Enemy(float ix, float iy);
		~Enemy();
		void act(double delta);
		void render();
		bool collide(Bullet& b);
};
#endif
