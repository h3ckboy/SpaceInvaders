game: game.cpp display.cpp player.cpp bullet.cpp enemy.cpp util.cpp
	g++ -std=c++0x -c game.cpp util.cpp enemy.cpp display.cpp player.cpp bullet.cpp
	g++ -o game game.o display.o player.o enemy.o bullet.o util.o -lncurses
clean: 
	rm *.o game
