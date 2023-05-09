/*************************************************************************
    FileAccess
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <FileAccess> (fichier FileAccess.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/FileAccess.h"


//----------------------------------------------------------------- PUBLIC

FileAccess::FileAccess() {
  #ifdef MAP
      cout << "Construction de <FileAccess>" << endl;
  #endif
}

FileAccess::~FileAccess() {
  #ifdef MAP
      cout << "Destruction de <FileAccess>" << endl;
  #endif
}

