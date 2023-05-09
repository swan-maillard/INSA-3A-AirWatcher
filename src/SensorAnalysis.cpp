/*************************************************************************
    SensorAnalysis
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <SensorAnalysis> (fichier SensorAnalysis.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/SensorAnalysis.h"


//----------------------------------------------------------------- PUBLIC

SensorAnalysis::SensorAnalysis() {
  #ifdef MAP
      cout << "Construction de <SensorAnalysis>" << endl;
  #endif
}

SensorAnalysis::~SensorAnalysis() {
  #ifdef MAP
      cout << "Destruction de <SensorAnalysis>" << endl;
  #endif
}

