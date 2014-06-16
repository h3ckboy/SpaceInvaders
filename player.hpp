#ifndef INC_PLAYER_H
#define INC_PLAYER_H

#include "bullet.hpp"
#include "enemy.hpp"

class Player{
	float x;
	float y;
	float dx;
	float dy;
	Bullet* bullet;
	static constexpr float WIDTH = 0.2f;
	static constexpr float HEIGHT = 0.2f;
	static constexpr float SPEED = 60.f;
	public:
		Player(float x, float y);
		~Player();
		void render();
		void act(double delta);
		bool collide(Enemy& e);
};
#endif /*INC_PLAYER_H*/
