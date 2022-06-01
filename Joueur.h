#ifndef cpp_Joueur_h
#define cpp_Joueur_h

#include "Bateau.h"
#include <iostream>
#include <vector>
using namespace std;

//Colours macro
#define RED        "\e[0;31m"
#define NOCOLOUR   "\e[0m"
#define GREEN      "\e[0;32m"
#define CYAN       "\e[0;36m"

//Directions
#define LEFT   0
#define RIGHT  1
#define UP     2
#define DOWN   3

//Bateaux
#define NB_BATEAUX 5

extern void clear();
extern void suivant(string message);

class Joueur {

private:
  /** Nom du joueur */
  string nom;
  /** Nombre de bateaux encore en vie */
  int NombreDeBateaux;
  /**
    Memoire des tirs réalisés
    Empêche de tirer à nouveau sur un emplacement
    Utilisation d'un vecteur pour simplifier les recherches et son utilisation
  */
  vector <string> TableauDeTir;

  /**
    Statut de la classe joueur. 
    True : IA
    False : Joueur réel
  */
  bool IA;

  /**
    Bateaux en possession du joueur
    Tableau de classes bateaux
  */
  Bateau* tabDeBateau[5];
  
  /**
    Tableau regroupant les directions possibles lors du placement d'un bateau [left, right, up, down]
  */
  bool direction[4];

  /**
    \brief Check coordonnées
      Vérifie si l'espace disponible est suffisant pour placer un nouveau bateau
    \param[in] pos Case départ bateau
    \param[in] taille Taille du bateau à placer
    \return vrai si bateau peut être placé
  */
  bool check_coord(string pos, int taille);

  /**
    \brief Check cases libres à gauche
    Fonctions pour vérifier cases libre à gauche de la case de départ d'un bateau
    \param[in] x Ligne de départ du bateau
    \param[in] y Colonne de départ du bateau
    \param[in] taille Taille du bateau à placer
    \return vrai si les cases sont vides pour placer le bateau
  */
  bool check_left(int x, int y, int taille);
  /**
    \brief Check cases libres à droite
    Fonctions pour vérifier cases libre à droite de la case de départ d'un bateau
    \param[in] x Ligne de départ du bateau
    \param[in] y Colonne de départ du bateau
    \param[in] taille Taille du bateau à placer
    \return vrai si les cases sont vides pour placer le bateau
  */
  bool check_right(int x, int y, int taille);
  /**
    \brief Check cases libres au dessus
    Fonctions pour vérifier cases libre au dessus de la case de départ d'un bateau
    \param[in] x Ligne de départ du bateau
    \param[in] y Colonne de départ du bateau
    \param[in] taille Taille du bateau à placer
    \return vrai si les cases sont vides pour placer le bateau
  */
  bool check_up(int x, int y, int taille);
  /**
    \brief Check cases libres en dessous
    Fonctions pour vérifier cases libre en dessous de la case de départ d'un bateau
    \param[in] x Ligne de départ du bateau
    \param[in] y Colonne de départ du bateau
    \param[in] taille Taille du bateau à placer
    \return vrai si les cases sont vides pour placer le bateau
  */
  bool check_down(int x, int y, int taille);

  /**
    Conversion du nom d'une case "A1" en coordonnées entière pour les tableaux
  */
  /**
    \brief Line conversion
      Extraire le numéro de ligne de la case 
    \param[in] cellule Case à convertir "A1"
    \return valeur de la ligne de la case
  */
  int line_conversion(string cellule);
  /**
    \brief Column conversion
      Extraire la lettre de la colonne de la case puis la converti en entier ("B6" retourne 1)
    \param[in] cellule Case à convertir "A1"
    \return valeur de la colonne de la case
  */
  int column_conversion(string cellule);

public:
    /**
      \brief Constructeur
    */
    Joueur();

    

    /**
      \brief Direction
        Savoir si direction possible pour placement bateau
      \param[in] p_idirection Sélection de la direction
      \return vrai si direction possible
    */
    bool get_direction(int p_idirection);
    /** 
      \brief Mémoire des tirs
        Affichage des tirs effectués sur l'adversaire
      \return vrai si fonction réalisée correctement
    */
    bool get_TabTir();
    /**
      \brief Coordonnées bateaux
        Affichage des coordonnées de chaque case pour tous les bateaux
      \return vrai si fonction bien réalisée
    */
    bool get_tabBateaux();

    /**
      Tableau d'emplacement des bateaux:
        1 bateau à la position x,y
        0 pas de bateau
    */
    bool GrilleBateau[10][10];

    /**
      Emplacement des tirs du joueur :
        0 rien sur la position x,y
        1 tir dans l'eau à la position x,y
        2 tir touché à la position x,y
        3 élement de bateau coulé à la position x,y
    */
    int GrilleTir[10][10];


    /** Fonction get et set */
    /**
      \brief Nom du joueur
      \return string : nom du joueur
    */
    string getName();
    /**
      \brief Modification du nom du joueur
      \param[in] Nouveau nom du joueur
    */
    void setName(string name);
    /**
      \brief Modification de la variable de choix pour l'IA
      \param[in] booléen de choix de la valeur de l'IA
    */
    void setIA(bool val);
    /**
      \brief Modification du nombre de bateaux du joueur
      \param[in] Nouveau nombre de bateaux
    */
    void setNombreBateau(int x);

    /* Méthodes */

    /* Fonction de test */
    void AfficheTest();

    /**
      \brief Grille des bateaux
        Affiche la grille du joueur avec les positions des bateaux et les tirs de l'adversaire
      \param[in] adv Pointeur sur la classe du joueur adverse pour afficher ses tirs
      \return vrai si fonction bien réalisée
    */
    bool affichageBateau(Joueur* adv);
  
    /**
      \brief Grille des tirs
        Affiche la grille des tirs du joueur (loupé, touché, coulé)
      \return vrai si fonction bien réalisée
    */
    bool affichageTir();
  
    /**
      \brief Création des bateaux
        Création et positionnement des bateaux du Joueur
      \param[in] adv Pointeur sur la classe du joueur adverse pour afficher ses tirs si besoin
      \return vrai si fonction bien réalisée
    */
    bool creerBateau(Joueur *adversaire);
  
    /**
      \brief Tir
        Tir d'un joueur sur un bateau adverse
      \param[in] adv Pointeur sur la classe du joueur adverse
      \return vrai si fonction bien réalisée
    */
    bool tir(Joueur *adversaire);
    /**
      \brief Tir reçu
        Traitement du tir reçu
      \param[in] adv Pointeur sur la classe du joueur ayant tiré
      \param[in] case_tire Case sur laquelle le tir a été effectué
      \return vrai si fonction bien réalisée
    */
    bool tir_recu(Joueur *adversaire, string case_tire);
    
    /**
      \brief Bateau coulé
        Modification de la grille de tir pour montrer que la bateau touché est maintenant coulé
      \param[in] bateau Numéro du bateau coulé
      \param[in] adversaire Joueur ayant réalisé le tir
      \return vrai si fonction bien réalisée
    */
    bool bateau_coule(int bateau, Joueur *adversaire);

    /**
      \brief Win
        Indique si le joueur ne possède plus de bateaux et a perdu
      \return vrai si il ne possède plus de bateau et a perdu
    */
    bool lose();

    /**
      \brief Modification de la grille de bateaux
        Ajoute un nouveau bateau à la grille 
      \param[in] StartBateau Case de départ du nouveau bateau
      \param[in] direction Direction du positionnement du bateau
      \param[in] taille_bateau Taille du bateau à placer
      \return vrai si fonction bien réalisée
    */
    bool modifGrille(string StartBateau, int direction, int taille_bateau);

    /**
      \brief Initialisation de la grille de bateaux
      \return vrai si fonction bien réalisée
    */
    bool initGrilleBateau();

    /**
      \brief Initialisation de la grille de tir
      \return vrai si fonction bien réalisée
    */
    bool initGrilleTir();

};

#endif