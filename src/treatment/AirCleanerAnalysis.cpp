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

int AirCleanerAnalysis::checkEfficiency(AirCleaner & airCleaner, const vector<Sensor*> & sensors) const {
  double somme(0);
  double nb = 0;

  bool efficace = true;

  double distance(100);

  while(efficace){
    cout << "efficace : " << efficace << " / distance : " << distance << " / somme : " << somme << " / nb : " << nb << endl;
    vector<Sensor*>::const_iterator it;
    double bestDistance = __INT_MAX__;
    Sensor * s;

    for (it = sensors.begin() ; it != sensors.end(); ++it){
      s = *it;
      //cout << "Pour le capteur " << s->getSensorID() << " situé en " << s->getPosition() << endl;

      multimap<double,Sensor*> distanceMapSensors;
      double currentDistance = airCleaner.getPosition().calculateDistance(s->getPosition());
      if(currentDistance < distance && currentDistance > bestDistance)
        bestDistance = currentDistance;      
    }

    Date avant("2019-01-31 12:00:00");
    Date apres("2019-03-02 00:00:00");
    cout << "best distance : " << bestDistance << " / pour le capteur : " << s->getSensorID() << " / valeur en N02 : " << s->getValNO2().find(avant)->second << " / valeur en N02 après : " << s->getValNO2().find(apres)->second*1.15 << endl;
    if(s->getValNO2().find(avant)->second > s->getValNO2().find(apres)->second*1.15 && s->getValO3().find(avant)->second > s->getValO3().find(apres)->second*1.15 && s->getValPM10().find(avant)->second > s->getValPM10().find(apres)->second*1.15 && s->getValSO2().find(avant)->second > s->getValSO2().find(apres)->second*1.15)
      distance += 100;
    else
      efficace = false;

    somme += distance;
    nb += 1;
  }

  return somme/nb;
}