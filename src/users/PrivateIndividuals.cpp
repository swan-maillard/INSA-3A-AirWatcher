/*************************************************************************
    PrivateIndividuals
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <PrivateIndividuals> (fichier PrivateIndividuals.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../../include/PrivateIndividuals.h"
#include "PrivateIndividuals.h"


//----------------------------------------------------------------- PUBLIC

PrivateIndividuals::PrivateIndividuals() {
  #ifdef MAP
      cout << "Construction de <PrivateIndividuals>" << endl;
  #endif
}

PrivateIndividuals::~PrivateIndividuals() {
  #ifdef MAP
      cout << "Destruction de <PrivateIndividuals>" << endl;
  #endif
}
int PrivateIndividuals::getBonReduction()
{
  if (points > 150){
    cout << "Bravo, vous avez gagné un bon de reduction !\n";
    points-=150;
  }
  cout << "Vous avez " << points << " points !";
}
