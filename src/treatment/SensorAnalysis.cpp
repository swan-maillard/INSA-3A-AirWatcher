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
#include <vector>
#include <map>

//------------------------------------------------------ Include personnel
#include "../../include/SensorAnalysis.h"
#include "../../include/Sensor.h"

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

void SensorAnalysis::scanSensors(const vector<Sensor*> & sensors) {
  vector<Sensor*>::const_iterator it;
  for (it = sensors.begin() ; it != sensors.end(); ++it){
    Sensor * s = *it;
    cout << "Pour le capteur " << s->getSensorID() << " situé en " << s->getPosition() << endl;

    multimap<double,Sensor*, greater<double>> distanceMapSensors;
    vector<Sensor*>::const_iterator it2;
    for (it2 = sensors.begin() ; it2 != sensors.end(); ++it2) {
      Sensor * s2 = *it2;
      if (s2->getSensorID() != s->getSensorID()) {
        double distance = s->getPosition().calculateDistance(s2->getPosition());
        distanceMapSensors.insert(pair<double, Sensor*>(distance, s2));
      }
    }

    cout << "5 capteurs plus proches : " << endl;
    multimap<double, Sensor*>::iterator itMap;
    int i;
    for (itMap = distanceMapSensors.begin(), i = 0; itMap != distanceMapSensors.end() && i < 5; ++itMap, ++i) {
      cout << "- " << itMap->second->getSensorID() << " => " << itMap->first << endl;
    }
  }
}