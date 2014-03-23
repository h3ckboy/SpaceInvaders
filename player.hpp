#ifndef INC_PLAYER_H
#define INC_PLAYER_H

#include "bullet.hpp"
#include "enemy.hpp"

class Player{
	int x;
	int y;
	Bullet* bullet;
	public:
		Player(int x, int y);
		~Player();
		void key(int c);
		void render();
		void act();
		bool collide(Enemy& e);
};
#endif /*INC_PLAYER_H*/
