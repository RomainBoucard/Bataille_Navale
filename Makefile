main: main.o Bateau.o Joueur.o
	g++ -o main main.o Bateau.o Joueur.o
main.o: main.cpp
	g++ -c main.cpp
Bateau.o: Bateau.cpp
	g++ -c Bateau.cpp
Joueur.o: Joueur.cpp
	g++ -c Joueur.cpp