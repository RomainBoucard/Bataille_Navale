main: main.o Bateau.o
	g++ -o main main.o Bateau.o
main.o: main.cpp
	g++ -c main.cpp
Bateau.o: Bateau.cpp
	g++ -c Bateau.cpp