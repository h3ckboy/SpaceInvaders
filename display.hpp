#ifndef INC_DISPLAY_H
#define INC_DISPLAY_H

#include <string>

namespace disp{
	void draw(float x, float y,float width, float height, int texture);
	bool loop();
	bool init();
	void close();
	double time();
	extern int keys[256];
	extern int WIDTH;
	extern int HEIGHT;

}

#endif
