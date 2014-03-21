game: game.cpp display.cpp player.cpp
	g++ -std=c++0x -c game.cpp
	g++ -c display.cpp
	g++ -c player.cpp
	g++ -c enemy.cpp
	g++ -o game game.o display.o player.o enemy.o -lncurses
