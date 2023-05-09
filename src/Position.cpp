/*************************************************************************
    Position
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Position> (fichier Position.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/Position.h"


//----------------------------------------------------------------- PUBLIC

Position::Position() {
  #ifdef MAP
      cout << "Construction de <Position>" << endl;
  #endif
}

Position::~Position() {
  #ifdef MAP
      cout << "Destruction de <Position>" << endl;
  #endif
}

