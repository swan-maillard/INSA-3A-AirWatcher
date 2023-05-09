/*************************************************************************
    Sensor
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/Sensor.h"


//----------------------------------------------------------------- PUBLIC

Sensor::Sensor() {
  #ifdef MAP
      cout << "Construction de <Sensor>" << endl;
  #endif
}

Sensor::~Sensor() {
  #ifdef MAP
      cout << "Destruction de <Sensor>" << endl;
  #endif
}

