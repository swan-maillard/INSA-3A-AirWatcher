/*************************************************************************
    User
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <User> (fichier User.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/User.h"


//----------------------------------------------------------------- PUBLIC

User::User() {
  #ifdef MAP
      cout << "Construction de <User>" << endl;
  #endif
}

User::~User() {
  #ifdef MAP
      cout << "Destruction de <User>" << endl;
  #endif
}

int User::checkPwd(const string & p) const
{
  int good = 0;
  if(p.compare(this->password) == 0)
    good = 1;
  return good;
}