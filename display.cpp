#include "display.hpp"
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <iostream>



namespace disp{

	int WIDTH;
	int HEIGHT;
	int keys[256];


	GLFWwindow* window;
	GLuint texture[1];
	void draw(float x, float y, float width, float height,int texture)
	{
		glLoadIdentity();
		glTranslatef(x,y,0);
		glBindTexture(GL_TEXTURE_2D,disp::texture[texture]);
		glBegin(GL_TRIANGLES);
			glTexCoord2f(0,1);glVertex2f(0,height);
			glTexCoord2f(0,0);glVertex2f(0,0);
			glTexCoord2f(1,0);glVertex2f(width,0);
			//second half of square
			glTexCoord2f(1,1);glVertex2f(width,height);
			glTexCoord2f(1,0);glVertex2f(width,0);
			glTexCoord2f(0,1);glVertex2f(0,height);
		glEnd();
	}

	void render()
	{
		glfwSwapBuffers(window);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void key_event (GLFWwindow* window, int key, int scancode,int action,int mods)
	{
		if(key==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window,GL_TRUE);
		keys[key] = action != GLFW_RELEASE;
	}

	bool LoadGLTextures()
	{
		const char* const files[] = {"ship.png"};
		int file_count = 1;
		for(int i =0;i<file_count;i++)
		{
			texture[i] = SOIL_load_OGL_texture
				(
				 files[i],
				 SOIL_LOAD_AUTO,
				 SOIL_CREATE_NEW_ID,
				 SOIL_FLAG_INVERT_Y
				);
			if(texture[i]==0)return false;
			glBindTexture(GL_TEXTURE_2D,texture[i]);
		}
		return true;
	}
		

	
	bool init()
	{
		if(!glfwInit())
			return false;
		window  = glfwCreateWindow(640,480,"Space Invaders",glfwGetPrimaryMonitor(),NULL);
		if(!window)
		{
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, key_event);
		glEnable(GL_TEXTURE_2D);

		if(!LoadGLTextures())
		{
			close();
			return false;
		}

		return true;

	}

	bool loop()
	{
		render();
		glfwPollEvents();

		return !glfwWindowShouldClose(window);
	}
	
	void close()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	double time()
	{
		return glfwGetTime();
	}
	
}
