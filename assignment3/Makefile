run_tycoon: run_tycoon.o property.o house.o tenant.o apartment.o business.o game.o
	g++ run_tycoon.o property.o house.o tenant.o apartment.o business.o game.o -g -o run_tycoon
property.o: property.cpp property.h
	g++ -g -c property.cpp
house.o: house.cpp house.h
	g++ -g -c house.cpp
tenant.o: tenant.cpp tenant.h
	g++ -g -c tenant.cpp
apartment.o: apartment.cpp apartment.h
	g++ -g -c apartment.cpp
business.o: business.cpp business.h
	g++ -g -c business.cpp
game.o:	game.cpp game.h
	g++ -g -c game.cpp
run_tycoon.o: run_tycoon.cpp
	g++ -g -c run_tycoon.cpp
clean:
	rm *.o run_tycoon

