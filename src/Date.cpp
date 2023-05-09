/*************************************************************************
    Date
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/Date.h"


//----------------------------------------------------------------- PUBLIC

Date::Date() {
  #ifdef MAP
      cout << "Construction de <Date>" << endl;
  #endif
}

Date::~Date() {
  #ifdef MAP
      cout << "Destruction de <Date>" << endl;
  #endif
}

