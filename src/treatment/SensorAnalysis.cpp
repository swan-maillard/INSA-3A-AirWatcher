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
  vector<Sensor*>::const_iterator itSensor1;
  for (itSensor1 = sensors.begin() ; itSensor1 != sensors.end(); ++itSensor1){
    Sensor * sensor = *itSensor1;
    cout << "Pour le capteur " << sensor->getSensorID() << " situé en " << sensor->getPosition() << endl;

    multimap<double, Sensor*> distanceMapSensors;
    vector<Sensor*>::const_iterator itSensor2;
    for (itSensor2 = sensors.begin() ; itSensor2 != sensors.end(); ++itSensor2) {
      Sensor * sensor2 = *itSensor2;
      if (sensor2->getSensorID() != sensor->getSensorID()) {
        double distance = sensor->getPosition().calculateDistance(sensor2->getPosition());
        distanceMapSensors.insert(pair<double, Sensor*>(distance, sensor2));
      }
    }

    cout << "5 capteurs plus proches : " << endl;
    multimap<double, Sensor*>::iterator itMapDistance;
    int i;
    for (itMapDistance = distanceMapSensors.begin(), i = 0; itMapDistance != distanceMapSensors.end() && i < 5; ++itMapDistance, ++i) {
      double distance = itMapDistance->first;
      Sensor* nearSensor = itMapDistance->second;
      cout << "- " << nearSensor->getSensorID() << " => " << distance << endl;

      DicoMesure valO3 = nearSensor->getValO3();
      DicoMesure valNO2 = nearSensor->getValNO2();
      DicoMesure valSO2 = nearSensor->getValSO2();
      DicoMesure valPM10 = nearSensor->getValPM10();

      cout << valO3.begin()->first << endl;
      cout << valNO2.begin()->first << endl;
      cout << valSO2.begin()->first << endl;
      cout << valPM10.begin()->first << endl;

    }
  }
}