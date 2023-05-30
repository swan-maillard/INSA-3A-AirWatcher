/*************************************************************************
    AirCleanerAnalysis
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <AirCleanerAnalysis> (fichier AirCleanerAnalysis.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../../include/AirCleanerAnalysis.h"


//----------------------------------------------------------------- PUBLIC

AirCleanerAnalysis::AirCleanerAnalysis() {
  #ifdef MAP
      cout << "Construction de <AirCleanerAnalysis>" << endl;
  #endif
}

AirCleanerAnalysis::~AirCleanerAnalysis() {
  #ifdef MAP
      cout << "Destruction de <AirCleanerAnalysis>" << endl;
  #endif
}

int AirCleanerAnalysis::checkEfficiency(const AirCleaner & airCleaner, const vector<Sensor*> & sensors) const {
  int somme(0);

<<<<<<< Updated upstream
  //for(int )
=======
  bool efficace = true;

  int distance(100);

  while(efficace){
    
  }
>>>>>>> Stashed changes

  return somme;
}