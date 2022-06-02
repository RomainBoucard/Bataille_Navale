/**
* @file Bateau.h
* @brief Contient la déclaration de la classe Bateau
* @author Romain BOUCARD Maxime REY Mathis TALON
* @version 1.0
* @date 2022
* @copyright Centrale Nantes
*/

#ifndef cpp_Bateau_h
#define cpp_Bateau_h

#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

/**
* @class Bateau "Bateau.h"
* @brief La déclaration de la classe Bateau
* @details La classe \c Bateau permet d'utiliser les bateaux d'un joueur
* @author Romain BOUCARD Maxime REY Mathis TALON
* @version 1.0
* @date 2022
*/
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
    /**
      \brief Constructeur
      \param[in] nom Nom du bateau créé
      \param[in] taille Taille du bateau créé
      \param[in] debut Case du début du bateau
      \param[in] direction Sens du placement du bateau depuis la case "debut"
    */
    Bateau(string nom, int taille, string debut, int direction);

  
    /** Fonction get et set */
    /**
      \brief Nom du Bateau
      \return string : nom du bateau
    */
    string get_name();
    /**
      \brief Récupérer coordonnées X
        Renvoie le numéro de ligne de la case spécifiée en paramètre
      \param[in] x Numéro de la case
      \return int : numéro de ligne de la case demandée
    */
    int get_X(int x);
    /**
      \brief Récupérer coordonnées Y
        Renvoie le numéro de colonne de la case spécifiée en paramètre
      \param[in] x Numéro de la case
      \return int : numéro de colonne de la case demandée
    */
    int get_Y(int y);
    /**
      \brief Taille du bateau
      \return int : taille du bateau
    */
    int get_taille();
    /**
      \brief Coordonnées X
        Affiche l'ensemble des numéros des lignes du bateau
    */
    void get_Xs();
    /**
      \brief Coordonnées Y
        Affiche l'ensemble des numéros des colonnes du bateau
    */
    void get_Ys();
  
  
  /* Méthodes */
    
    /**
      \brief Vérifie si le bateau est touché
      \param[in] x Numéro de la ligne de la case ciblée
      \param[in] y Numéro de la colonne de la case ciblée
      \return bool : vrai si le bateau est touché sinon faux
    */
    bool checkTouche (int x, int y);

    /**
      \brief Enlève un point de vie au bateau
        Enlève un point de vie et vérifie si le bateau est coulé
      \return bool : faux si le bateau est coulé sinon vrai
    */
    bool perte_pdv();

};

#endif