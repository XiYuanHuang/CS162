netflix: run_netflix.o netflix.o
	g++ run_netflix.o netflix.o -o netflix
run_netflix.o: run_netflix.cpp
	g++ -g -c run_netflix.cpp
netflix.o: netflix.cpp netflix.h
	g++ -g -c netflix.cpp 
clean:
	rm *.o netflix
