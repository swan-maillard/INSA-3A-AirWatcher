/*************************************************************************
    AirWatcher
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <AirWatcher> (fichier AirWatcher.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/AirWatcher.h"


//----------------------------------------------------------------- PUBLIC

AirWatcher::AirWatcher() {
  #ifdef MAP
      cout << "Construction de <AirWatcher>" << endl;
  #endif
}

AirWatcher::~AirWatcher() {
  #ifdef MAP
      cout << "Destruction de <AirWatcher>" << endl;
  #endif
}

