#include "Joueur.h"
#include "stdlib.h"
#include <vector>
#include <algorithm>
using namespace std;

//Constante des tailles des différents bateaux
int taille_bateaux[5] = {5, 4, 3, 3, 2};    

void clear(){
  std::cout << "\033[2J\033[1;1H";
}

void suivant(string message){
  string entree;
  cout << message;
  cin >> entree;
  cout << endl;
}

Joueur::Joueur(){
  this->nom = "x";
	this->NombreDeBateaux = 0;
  this->tabDeBateau[4] ={NULL};
  this->IA=false;
}

string Joueur::getName(){
  return nom;
}

void Joueur::setNombreBateau(int x){
  this->NombreDeBateaux = x;
}

void Joueur::setName(string name){
  this->nom = name;
}

void Joueur::setIA(bool val){
  this->IA = val;
}

bool Joueur::lose(){
  bool retVal = (this->NombreDeBateaux == 0) ? true : false;   
  return retVal;
}

bool Joueur::creerBateau(Joueur *adversaire){
  bool retVal = true;
  string Bateaux[5] = {
    "PorteAvion (ligne de 5)",
    "Croiseur (ligne de 4)",
    "ContreTorpilleur1 (ligne de 3)",
    "ContreTorpilleur2 (ligne de 3)",
    "Torpilleur (ligne de 2)",
  };
  string input;
  string choix_direction;
  int direction_bateau;
  if(this->IA==0)
  {
    for(int i = 0; i<NB_BATEAUX; i++)
    {
      clear();
      cout << this->nom << " positionnez vos bateaux sur la grille" << endl;
      do
      {
        this->affichageBateau(adversaire);
        cout << "Veuillez choisir une position de depart pour le bateau " << Bateaux[i] << endl;
        cout << "Format attendu 'D5'" << endl;
        cin >> input;
        retVal=check_coord(input, taille_bateaux[i]);   //check coordonnées correctes +case libre + cases autour libre
        if (!retVal){
          cout << "Coordonnees incorrectes ou espace insufisant" << endl << "Veuillez entrer une nouvelle case" << endl;
          suivant("Inserez un caractere et appuyez sur Entree pour continuer...");
        }
      }while (!retVal) ;
    
      //Nombre de cases suffisant pour nouveau bateaux
      //Choix de la direction
      do
      {
        cout << "Veuillez choisir la direction de votre bateau " << Bateaux[i] << " depuis la case " << input << " :" << endl;
        (this->direction[0]) ? cout << "  - Gauche : 0" << endl : cout << "";
        (this->direction[1]) ? cout << "  - Droite : 1" << endl : cout << "";
        (this->direction[2]) ? cout << "  - Haut : 2" << endl : cout << "";
        (this->direction[3]) ? cout << "  - Bas : 3" << endl : cout << "";
        cin >> choix_direction;
        //Boucle tant que la direction choisi n'est pas possible ou la valeur inscrite est différente des valeurs possibles
      } while (!this->direction[stoi(choix_direction)] | stoi(choix_direction)>3 | stoi(choix_direction)<0 );
      direction_bateau =stoi(choix_direction);
      //Création du bateau : appel constructeur + modif de la grilleBateau
      Bateau *Bateau1 = new Bateau(Bateaux[i], taille_bateaux[i], input, direction_bateau);
      tabDeBateau[i] = Bateau1;
      retVal&=modifGrille(input, direction_bateau, taille_bateaux[i]);
      this->NombreDeBateaux+=1;
    }
  }
  else if (this->IA==1)
  {
    do
    {
      int X = (rand()%10)+65;
      char s = (char) X;
      int Y = rand()%10+1;
      
    }
    while(true);
  }
  return retVal;
}

bool Joueur::modifGrille(string StartBateau, int direction, int taille_bateau){
  bool retVal = false;
  int x = line_conversion(StartBateau);
  int y = column_conversion(StartBateau);
  int i=0;
  switch (direction){
    case LEFT: //gauche
      for (i=0; i<taille_bateau; i++){
        this->GrilleBateau[x][y-i]=true;
      }
      break;
    case RIGHT: //droite
      for (i=0; i<taille_bateau; i++){
        this->GrilleBateau[x][y+i]=true;
      }
      break;
    case UP: //haut
      for (i=0; i<taille_bateau; i++){
        this->GrilleBateau[x-i][y]=true;
      }
      break;
    case DOWN: //bas
      for (i=0; i<taille_bateau; i++){
        this->GrilleBateau[x+i][y]=true;
      }
      break;
    default: cout << "Erreur direction" << endl;
      break;
  }
  return retVal;
}

void Joueur::AfficheTest(){
  cout << "valeur de tableau de tir :" << TableauDeTir[8] << endl;
}
    
bool Joueur::affichageTir() {
  int i;
  int j;
  cout << "  | A  | B  | C  | D  | E  | F  | G  | H  | I  | J  |" << endl;
  cout << "  |----|----|----|----|----|----|----|----|----|----|" << endl;
  for (i=0; i<sizeof(GrilleTir)/sizeof(GrilleTir[0]); i++)
  {
    cout << i+1;
    string result = (i+1 == 10) ? "|" : " |";
    cout << result;
    
    for (j=0; j<sizeof(GrilleTir[0])/sizeof(GrilleTir[0][0]); j++)
    {
      cout << " ";
      switch (GrilleTir[i][j]){
        case 0: //aucun tir
          cout << " ";
          break;
        case 1: //tir dans l'eau
          cout << "O";
          break;
        case 2: //touché
          cout << "X";
          break;
        case 3: //coulé
          cout << "V";
          break;
        default:
          cout << " ";
          break;
      }
      cout << "  |";
    }
    cout << endl;
    cout << "  |----|----|----|----|----|----|----|----|----|----|" << endl;
  } 
  return true;
} 

bool Joueur::affichageBateau(Joueur* adv) {
  int i;
  int j;
  cout << "  | A  | B  | C  | D  | E  | F  | G  | H  | I  | J  |" << endl;
  cout << "  |----|----|----|----|----|----|----|----|----|----|" << endl;
  for (i=0; i<sizeof(GrilleBateau)/sizeof(GrilleBateau[0]); i++)
  {
    cout << i+1;
    string result = (i+1 == 10) ? "|" : " |";
    cout << result;
    
    for (j=0; j<sizeof(GrilleBateau[0])/sizeof(GrilleBateau[0][0]); j++)
    {
      if (GrilleBateau[i][j]==true){
        cout << "B";
      }
      else
      {
        cout << " ";
      }
      cout << "  ";
      switch (adv->GrilleTir[i][j]){
        case 0: //aucun tir
          cout << " ";
          break;
        case 1: //tir dans l'eau
          cout << "O";
          break;
        case 2: //touché
          cout << "X";
          break;
        case 3: //coulé
          cout << "V";
          break;
        default:
          cout << " ";
          break;
      }
      cout << "|";
    }
    cout << endl;
    cout << "  |----|----|----|----|----|----|----|----|----|----|" << endl;
  } 
  return true;
} 

int Joueur::column_conversion (string cellule){
  switch (cellule[0]){
    case 65 : return 0;// A
      break;
    case 66 : return 1;// B
      break;
    case 67 : return 2;// C
      break;
    case 68 : return 3;// D
      break;
    case 69 : return 4;// E
      break;
    case 70 : return 5;// F
      break;
    case 71 : return 6;// G
      break;
    case 72 : return 7;// H
      break;
    case 73 : return 8;// I
      break;
    case 74 : return 9;// J
      break;
    default: return -1;
      break; 
  }
}

int Joueur::line_conversion (string cellule){
  cellule.erase(0,1);
  int ascii;
  int line;
  ascii = (int) cellule[0];
  if (ascii>47 && ascii<58){
    (cellule!="") ? line = stoi(cellule, nullptr)-1 : line=-1;
  }
  else{
    line = -1;
  }
  return line;
}

bool Joueur::check_coord(string pos, int taille){
  bool retVal = false;
  int x = line_conversion(pos);
  int y = column_conversion(pos);
  //reset des directions pour nouveau bateau
  this->direction[LEFT]=false;
  this->direction[RIGHT]=false;
  this->direction[UP]=false;
  this->direction[DOWN]=false;

  if (y==-1 | x<0 | x>9) return false; //coordonées incorrectes
  if (GrilleBateau[x][y]) return false; //case occupée par un bateau
  retVal|=this->direction[LEFT]=check_left(x, y, taille);
  retVal|=this->direction[RIGHT]=check_right(x, y, taille);
  retVal|=this->direction[UP]=check_up(x, y, taille);
  retVal|=this->direction[DOWN]=check_down(x, y, taille);


  return retVal;
}

bool Joueur::check_left(int x, int y, int taille){
  if ((y+1)<taille) return false; //Pas assez de cases à gauche
  int i;
  for (i=0; i<taille; i++){
    if (GrilleBateau[x][y-i]) return false; //case occupée
  }
  return true;
}

bool Joueur::check_right(int x, int y, int taille){
  if ((10-y)<taille) return false; //Pas assez de cases à droite
  int i;
  for (i=0; i<taille; i++){
    if (GrilleBateau[x][y+i]) return false; //case occupée
  }
  return true;
}

bool Joueur::check_up(int x, int y, int taille){
  if ((x+1)<taille) return false; //Pas assez de cases en haut
  int i;
  for (i=0; i<taille; i++){
    if (GrilleBateau[x-i][y]) return false; //case occupée
    // cout << "Case x:" << x-1 << " y:" << y << " Val:" << GrilleBateau[x-1][y] << endl;
  }
  return true;
}

bool Joueur::check_down(int x, int y, int taille){
  if ((10-x)<taille) return false; //Pas assez de cases en bas
  int i;
  for (i=0; i<taille; i++){
    if (GrilleBateau[x+i][y]) return false; //case occupée
  }
  return true;
}

bool Joueur::get_direction(int p_idirection){
  return direction[p_idirection];
}

bool Joueur::tir(Joueur *adversaire){
  bool retVal = false;
  string case_tire;

  bool check_coordonnees =true;
  // check si coordonnées sont valables + si case pas déjà tirée
  do
  {
    check_coordonnees=true;
    cout << "Veuillez choisir la case sur laquelle vous voulez tirer " << endl;
    cin >> case_tire;
    int x = line_conversion(case_tire);
    int y = column_conversion(case_tire);
    if (y==-1 | x<0 | x>9){//coordonées incorrectes
      check_coordonnees=false;
      cout << "Coordonnees incorrectes ou espace insufisant" << endl << "Veuillez entrer une nouvelle case" << endl;
    }
    if (check_coordonnees==true){
      auto it = find(TableauDeTir.begin(), TableauDeTir.end(), case_tire);
      if (it != TableauDeTir.end()){
        check_coordonnees=false;
        cout << "Case deja tiree" << endl << "Veuillez entrer une nouvelle case" << endl;
      }
      else{
        TableauDeTir.push_back(case_tire);
        cout << "Tire en cours..." << endl;
      }
    }
  } while (!check_coordonnees);
  adversaire->tir_recu(this, case_tire);
  return true;
}

bool Joueur::get_TabTir(){
  for (string& x : TableauDeTir) {
    cout << x << endl; 
  }
  return true;
}

bool Joueur::initGrilleBateau(){
  int i;
  int j;
  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      GrilleBateau[i][j]=false;
    }
  }
  return true;
}

bool Joueur::initGrilleTir(){
  int i;
  int j;
  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      GrilleTir[i][j]=0;
    }
  }
  return true;
}

bool Joueur::tir_recu(Joueur *adversaire, string case_tire){
  int x = line_conversion(case_tire);
  int y = column_conversion(case_tire);
  int i;
  bool bateau_touche=false;
  bool bateau_TC=false;
  if(this->GrilleBateau[x][y]==true){ //vérif si présence d'un bateau
    cout << "Presence d'un bateau" << endl;
    for(i=0; i<NB_BATEAUX; i++){
      bateau_touche=this->tabDeBateau[i]->checkTouche(x, y);
      if(bateau_touche==true) break;
    }
    bateau_TC=tabDeBateau[i]->perte_pdv(); //perte point de vie d'un bateau
    if(bateau_TC==true){ //touché
      cout << "Bateau touche" << endl;
      adversaire->GrilleTir[x][y]=2;
      return true;
    }else{ //coulé
      cout << "Bateau coule" << endl;
      this->bateau_coule(i, adversaire);
      return true;
    }
  }
  else{
    cout << "Aucun bateau touche" << endl;
    adversaire->GrilleTir[x][y]=1;
    return true;
  }
}

bool Joueur::get_tabBateaux(){
  int i;
  for(i=0; i<5; i++){
    cout << tabDeBateau[i]->get_name() << endl;
    cout << "x :" << endl;
    tabDeBateau[i]->get_Xs();
    cout << endl;
    cout << "y :" << endl;
    tabDeBateau[i]->get_Ys();
    cout << endl;
  }
  return true;
}

bool Joueur::bateau_coule(int bateau, Joueur *adversaire){
  int taille;
  taille=taille_bateaux[bateau];
  int i, x, y;
  for(i=0; i<taille; i++){
    x=this->tabDeBateau[bateau]->get_X(i);
    y=this->tabDeBateau[bateau]->get_Y(i);
    adversaire->GrilleTir[x][y]=3;
  }
  this->NombreDeBateaux-=1;
  cout << "Bateau detruit" << endl;
  return true;
}