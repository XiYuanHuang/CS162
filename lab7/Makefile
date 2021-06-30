run_shape: circle.o rectangle.o shape.o driver.o
	g++ circle.o rectangle.o shape.o driver.o -o run_shape
circle.o: circle.cpp circle.h
	g++ -c circle.cpp 
rectangle.o: rectangle.cpp rectangle.h
	g++ -c rectangle.cpp 
shape.o: shape.cpp shape.h
	g++ -c shape.cpp
driver.o: driver.cpp	
	g++ -c driver.cpp
clean:
	rm *.o run_shape
