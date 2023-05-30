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

double AirCleanerAnalysis::checkEfficiency(AirCleaner & airCleaner, const vector<Sensor*> & sensors) const {
  bool efficace = true;

  double distance = 0.3;

  while(efficace){
    cout << "efficace : " << efficace << " / distance : " << distance << endl;
    vector<Sensor*>::const_iterator it;
    double bestDistance = -1;
    Sensor * s;

    for (it = sensors.begin() ; it != sensors.end(); ++it){
      Sensor * s1 = *it;
      //cout << "Pour le capteur " << s->getSensorID() << " situé en " << s->getPosition() << endl;

      multimap<double,Sensor*> distanceMapSensors;
      double currentDistance = airCleaner.getPosition().calculateDistance(s1->getPosition());
      //cout << "current distance : " << currentDistance << endl;
      if(currentDistance < distance && currentDistance > bestDistance){
        bestDistance = currentDistance;
        s = *it;
      }
      //cout << "best distance : " << bestDistance << endl;
    }
    
    Date avant("2019-01-31 12:00:00");
    Date apres("2019-03-02 12:00:00");
    cout << "best distance : " << bestDistance << " / pour le capteur : " << s->getSensorID() << endl;
    cout << "valeur en N02 : " << s->getValNO2().find(avant)->second << " / valeur en N02 après : " << s->getValNO2().find(apres)->second << endl;
    cout << "valeur en O3 : " << s->getValO3().find(avant)->second << " / valeur en O3 après : " << s->getValO3().find(apres)->second << endl;
    cout << "valeur en SO2 : " << s->getValSO2().find(avant)->second << " / valeur en SO2 après : " << s->getValSO2().find(apres)->second << endl;
    cout << "valeur en PM10 : " << s->getValPM10().find(avant)->second << " / valeur en PM10 après : " << s->getValPM10().find(apres)->second << endl;
    cout << endl;
    if(s->getValNO2().find(avant)->second*1.05 > s->getValNO2().find(apres)->second && s->getValO3().find(avant)->second*1.05 > s->getValO3().find(apres)->second && s->getValPM10().find(avant)->second*1.05 > s->getValPM10().find(apres)->second && s->getValSO2().find(avant)->second*1.05 > s->getValSO2().find(apres)->second && distance < 7)
      distance += 0.1;
    else
      efficace = false;
  }

  return distance;
}