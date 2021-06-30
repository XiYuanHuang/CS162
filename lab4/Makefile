run_pizza: run_pizza.o menu.o restaurant.o pizza.o
	g++ run_pizza.o menu.o restaurant.o pizza.o -o run_pizza
run_pizza.o: run_pizza.cpp
	g++ -c run_pizza.cpp 
menu.o: menu.cpp menu.h
	g++ -c menu.cpp
restaurant.o: restaurant.cpp restaurant.h
	g++ -c restaurant.cpp
pizza.o: pizza.cpp pizza.h
	g++ -c pizza.cpp
clean:
	rm *.o run_pizza
