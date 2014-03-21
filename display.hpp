#ifndef INC_DISPLAY_H
#define INC_DISPLAY_H

#include <string>

namespace disp{
	void render(int x, int y, std::string str);
	void init();
	void show();
	void close();
	int key();
	extern const int LEFT;
	extern const int RIGHT;

}

#endif
