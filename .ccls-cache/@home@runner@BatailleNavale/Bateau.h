#ifndef cpp_Bateau_h
#define cpp_Bateau_h

#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

class Bateau {
  private :

    /** Nom du bateau */
    string nom;
    /** Taille du bateau */
    int taille;
    /** Nombre de points de vie restants */
    int pdv;
    /** Numéros des lignes des cases du bateau */
    vector <int> coordX;
    /** Numéros des colonnes des cases du bateau */
    vector <int> coordY;
    bool vivant;

    /*
      Conversion du nom d'une case "A1" en coordonnées entière pour les tableaux
    */
    int line_conversion(string cellule);
    int column_conversion(string cellule);
  
  public :
    Bateau();
    Bateau(string nom, int taille, string debut, int direction);

  
    //get set
    string get_name();
    int get_X(int x);
    int get_Y(int y);
    int get_taille();
    void get_Xs();
    void get_Ys();
  
  
  //Méthodes
    bool checkTouche (int x, int y);
    //lorsque la fonction est appelée, compare les coordonnées données avec les   coordonnées de chaque segment de de chaque bateau non coulé

    //Enlever pdv + dire si encore en vie
    bool perte_pdv();

};

#endif