# build executable for histograph called run

output: main.o histograph.o
	g++ -Wall main.o histograph.o -o run

main.o: main.cpp
	g++ -c main.cpp

histograph.o: histograph.cpp histograph.h
	g++ -c histograph.cpp

clean:
	rm *.o run