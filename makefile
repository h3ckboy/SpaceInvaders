game: game.cpp display.cpp player.cpp bullet.cpp enemy.cpp util.cpp display.hpp player.hpp bullet.hpp enemy.hpp util.hpp
	g++ -std=c++0x -c game.cpp 
	g++ -std=c++0x -c util.cpp 
	g++ -std=c++0x -c enemy.cpp 
	g++ -std=c++0x -c display.cpp 
	g++ -std=c++0x -c player.cpp 
	g++ -std=c++0x -c bullet.cpp
	g++ -o game game.o display.o player.o enemy.o bullet.o util.o -lncurses -lGL -lglfw -lSOIL
clean: 
	rm *.o game
