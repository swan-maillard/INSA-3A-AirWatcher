/*************************************************************************
    System
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <System> (fichier System.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../../include/System.h"


//----------------------------------------------------------------- PUBLIC

System::System() {
  #ifdef MAP
      cout << "Construction de <System>" << endl;
  #endif
}

System::~System() {
  #ifdef MAP
      cout << "Destruction de <System>" << endl;
  #endif
}

Sensor System::infoSensor(const int & id) const
{
  vector<Sensor>::iterator i;
  //i = sensors.begin();
  //while(i != end
}


