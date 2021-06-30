run_game: ant.o bee.o game.o childant.o run_game.o
	g++ ant.o bee.o game.o childant.o run_game.o -g -o run_game
ant.o: ant.cpp ant.h
	g++ -g -c ant.cpp
bee.o: bee.cpp bee.h
	g++ -g -c bee.cpp
game.o: game.cpp game.h
	g++ -g -c game.cpp
childant.o: childant.cpp childant.h
	g++ -g -c childant.cpp
run_game.o: run_game.cpp
	g++ -g -c run_game.cpp
clean:
	rm *.o run_game
