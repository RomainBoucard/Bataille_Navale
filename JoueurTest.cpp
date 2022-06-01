#include "googletest/googletest/include/gtest/gtest.h"
#include <iostream>
#include "Joueur.h"

class JoueurTest:  public ::testing::Test {
public:
protected:
  Joueur *Joueur1 = new Joueur;
  Joueur *Adversaire = new Joueur;
};

TEST_F(JoueurTest, test_lose_J1Perds) {
  Joueur1->setNombreBateau(0);
  EXPECT_TRUE(Joueur1->lose());
}
TEST_F(JoueurTest, test_lose_J1EncoreEnJeu) {
  Joueur1->setNombreBateau(1);
  EXPECT_FALSE(Joueur1->lose());
}
TEST_F(JoueurTest, creationBateauJ1_AllOkInput){
    //Méthode problématique à tester à cause de ses accès nombreux à cin
    //Il est (très) ardu de créer un mock de iostream, les méthodes n'étant pas abstraites
}
TEST_F(JoueurTest,test_modifGrille_Ok){
  Joueur1->GrilleBateau[9][9] = {0};

  //Creation d'un bateau en C4 (Case [3,2] vers la droite de taille 2)
  //Les valeurs de direction et de taille sont considérées vraies car elle sont testées dans la methode "creerBateau"
  Joueur1->modifGrille("C4", 1, 2);

  EXPECT_EQ(Joueur1->GrilleBateau[3][2],1);
  EXPECT_EQ(Joueur1->GrilleBateau[3][3],1);
  
}

