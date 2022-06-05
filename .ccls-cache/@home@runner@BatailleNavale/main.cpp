#include "Bateau.h"
#include "Joueur.h"
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <time.h> 

using namespace std;



bool GrilleBateau[10][10] = {
    {false, false, false, false, true, true, true, false, false, false},
    {false, false, true, false, false, false, false, true, false, false},
    {false, false, false, false, false, false, false, false, true, false},
    {false, true, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, true, false, false, false, false},
    {false, false, false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, false, false, false, false},
    {true, false, false, true, true, false, false, true, false, false},
    {false, false, false, false, false, false, false, true, false, false},
    {false, true, false, false, false, false, false, false, false, false}};

int GrilleBateaud[10][10] = {
    {0, 0, 1, 1, 0, 0, 2, 0, 3, 0}, {0, 0, 1, 1, 0, 0, 2, 0, 3, 0},
    {0, 0, 1, 1, 0, 0, 2, 0, 3, 0}, {0, 0, 1, 1, 0, 0, 2, 0, 3, 0},
    {0, 0, 1, 1, 0, 0, 2, 0, 3, 0}, {0, 0, 1, 1, 0, 0, 2, 0, 3, 0},
    {0, 0, 1, 1, 0, 0, 2, 0, 3, 0}, {0, 0, 1, 1, 0, 0, 2, 0, 3, 0},
    {0, 0, 1, 1, 0, 0, 2, 0, 3, 0}, {0, 0, 1, 1, 0, 0, 2, 0, 3, 0}};

int main() {
  srand (time(NULL)); //initialisation de srand pour la valeur aleatoire
  
  Joueur *Joueur1 = new Joueur;
  Joueur *Joueur2 = new Joueur;

  
  string entree;
  bool fin = true;

  // Game
  clear();
  cout << GREEN << "          Bataille Navale" << NOCOLOUR<< endl;
  cout << "Appuyez sur un bouton pour commencer" << endl;
  
  getchar();
  cout << "Veuillez choisir un mode de jeu :\n" << "0 pour jouer à deux joueurs \n" << "1 pour jouer face à une IA" << endl;
  cin >> entree;
  if (entree == "1") Joueur2->setIA(1);

  if (Joueur2->getIA()) //Jeu avec l'IA
  {
    Joueur2->setName("IA");
    cout << "Joueur 1, veuillez inscrire votre nom : ";
    cin >> entree;
    Joueur1->setName(entree); 
    // Placement des bateaux
    clear();//efface contenu de la console
    Joueur1->creerBateau(Joueur2);
    clear();//efface contenu de la console
    Joueur2->creerBateau(Joueur1);
    clear();
    cout << "Placement des bateaux de l'IA en cours..." << endl;
    sleep(1);
    
    while (fin) {
      clear(); //effacer contenu de la console
      //J1
      cout << "Inserez un caractere et appuyez sur Entree pour commencer votre tour " << GREEN << Joueur1->getName() << NOCOLOUR << "...";
      cin >> entree;
      cout << endl;
      clear(); //effacer contenu de la console
      cout << "Placement des bateaux de " << Joueur1->getName() << endl;
      Joueur1->affichageBateau(Joueur2);
      cout << "Tirs effectues de " << Joueur1->getName() << endl;
      Joueur1->affichageTir();
      Joueur1->tir(Joueur2);
      
      if (Joueur2->lose()){
        fin=false;
        cout << "Victoire de " << Joueur1->getName() << " !" << endl;
        suivant("Inserez un caractere et appuyez sur Entree pour terminer la partie...");
      }
      else {
        suivant("Inserez un caractere et appuyez sur Entree pour terminer votre tour...");
      }
      clear(); //effacer contenu de la console
      if (fin){
        //J2
        cout <<"Tour de l'IA, veuillez patienter" << endl;
        Joueur2->tir(Joueur1);                        
        
        if (Joueur1->lose()){
          fin=false;
          cout << "Victoire de " << Joueur2->getName() << " !" << endl;
          suivant("Inserez un caractere et appuyez sur Entree pour terminer la partie...");
        }
        else{
          suivant("Inserez un caractere et appuyez sur Entree pour terminer votre tour...");
        }
      }
    
    }
  }
    
  else if (Joueur2->getIA() == false) // Jeu sans l'IA
  {
    // Init des joueurs
    cout << "Joueur 1, veuillez inscrire votre nom : ";
    cin >> entree;
    Joueur1->setName(entree);
    cout << endl << "Joueur 2, veuillez inscrire votre nom : ";
    cin >> entree;
    Joueur2->setName(entree);
    clear(); //effacer contenu de la console
    // Placement des bateaux
    Joueur1->creerBateau(Joueur2);
    clear();//efface contenu de la console
    suivant("Inserez un caractere et appuyez sur Entree pour positionner vos bateaux...");
    Joueur2->creerBateau(Joueur1);
    clear(); //efface contenu de la console
    
    suivant("Inserez un caractere et appuyez sur Entree pour commencer la partie...");
  
    // Début du jeu
    while (fin) {
      clear(); //effacer contenu de la console
      //J1
      cout << "Inserez un caractere et appuyez sur Entree pour commencer votre tour " << GREEN << Joueur1->getName() << NOCOLOUR << "...";
      cin >> entree;
      cout << endl;
      clear(); //effacer contenu de la console
      cout << "Placement des bateaux de " << Joueur1->getName() << endl;
      Joueur1->affichageBateau(Joueur2);
      cout << "Tirs effectues de " << Joueur1->getName() << endl;
      Joueur1->affichageTir();
      Joueur1->tir(Joueur2);
      cout << "Tirs effectues de " << Joueur1->getName() << endl;
      Joueur1->affichageTir();
      if (Joueur2->lose()){
        fin=false;
        cout << "Victoire de " << Joueur1->getName() << " !" << endl;
        suivant("Inserez un caractere et appuyez sur Entree pour terminer la partie...");
      }
      else {
        suivant("Inserez un caractere et appuyez sur Entree pour terminer votre tour...");
      }
      clear(); //effacer contenu de la console
      if (fin){
        //J2
        cout << "Inserez un caractere et appuyez sur Entree pour commencer votre tour " << GREEN << Joueur2->getName() << NOCOLOUR << "...";
        cin >> entree;
        cout << endl;
        cout << "Placement des bateaux de " << Joueur2->getName() << endl;
        Joueur2->affichageBateau(Joueur1);
        cout << "Tirs effectues de " << Joueur2->getName() << endl;
        Joueur2->affichageTir();
        Joueur2->tir(Joueur1);
        cout << "Tirs effectues de " << Joueur2->getName() << endl;
        Joueur2->affichageTir();
        if (Joueur1->lose()){
          fin=false;
          cout << "Victoire de " << Joueur2->getName() << " !" << endl;
          suivant("Inserez un caractere et appuyez sur Entree pour terminer la partie...");
        }
        else{
          suivant("Inserez un caractere et appuyez sur Entree pour terminer votre tour...");
        }
      }
    
    }
  }

  delete (Joueur1);
  delete (Joueur2);
}
