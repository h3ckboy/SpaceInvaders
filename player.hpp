#ifndef INC_PLAYER_H
#define INC_PLAYER_H

class Player{
	int x, y;
	public:
		Player(int x, int y);
		void key(int c);
		void render();
};
#endif /*INC_PLAYER_H*/
