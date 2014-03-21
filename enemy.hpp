#ifndef INC_ENEMY_H
#define INC_ENEMY_H

class Enemy{
	float x,y;
	static float dx,dy;

	public:
		Enemy(int ix, int iy);
		void act();
		void render();
};
#endif
