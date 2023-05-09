/*************************************************************************
    Gouvernement
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Gouvernement> (fichier Gouvernement.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../../include/Gouvernement.h"


//----------------------------------------------------------------- PUBLIC

Gouvernement::Gouvernement() {
  #ifdef MAP
      cout << "Construction de <Gouvernement>" << endl;
  #endif
}

Gouvernement::~Gouvernement() {
  #ifdef MAP
      cout << "Destruction de <Gouvernement>" << endl;
  #endif
}

