/*************************************************************************
    Providers
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Providers> (fichier Providers.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/Providers.h"


//----------------------------------------------------------------- PUBLIC

Providers::Providers() {
  #ifdef MAP
      cout << "Construction de <Providers>" << endl;
  #endif
}

Providers::~Providers() {
  #ifdef MAP
      cout << "Destruction de <Providers>" << endl;
  #endif
}

