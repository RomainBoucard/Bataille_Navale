#include <iostream>
#include "Bateau.h"
#include "Joueur.h"

int main() {
  std::cout << "Hello World!\n";

  Bateau *Bateau1 = new Bateau("Bateau 1", 5, "A1", 1);
  Joueur *Joueur1 = new Joueur;
  Joueur *Joueur2 = new Joueur;

  cout << "Nom : " << Bateau1->get_name() << endl; //Nom Bateau
  cout << "Taille : " << Bateau1->get_taille() << endl; //Taille Bateau
  cout << "Lignes : " << endl; //Lignes cases Bateau
  Bateau1->get_Xs();
  cout << endl;
  cout << "Colonnes : " << endl; //Colonnes cases Bateau
  Bateau1->get_Ys() ;
  cout << endl;

  Joueur1->setName("Romain");
  cout << "Nom : " << Joueur1->getName() << endl; //Nom Joueur
  Joueur1->creerBateau(Joueur2);
  Joueur1->affichageBateau(Joueur2);

}