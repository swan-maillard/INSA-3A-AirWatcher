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
#include <cmath>

//------------------------------------------------------ Include personnel
#include "../../include/SensorAnalysis.h"
#include "../../include/Sensor.h"

//----------------------------------------------------------------- PUBLIC

struct SensorStats {
      double O3;
      double SO2;
      double NO2;
      double PM10;
    };

    struct NearSensorStats {
      double meanO3 = 0;
      double meanSO2 = 0;
      double meanNO2 = 0;
      double meanPM10 = 0;
      double varianceO3 = 0;
      double varianceSO2 = 0;
      double varianceNO2 = 0;
      double variancePM10 = 0;
    };

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
  SensorStats sensorStats;
  for (itSensor1 = sensors.begin() ; itSensor1 != sensors.end(); ++itSensor1) {
    Sensor * sensor = *itSensor1;

    sensorStats.O3 = (--sensor->getValO3().end())->second;
    sensorStats.NO2 = (--sensor->getValNO2().end())->second;
    sensorStats.SO2 = (--sensor->getValSO2().end())->second;
    sensorStats.PM10 = (--sensor->getValPM10().end())->second;

    multimap<double, Sensor*> distanceMapSensors;
    vector<Sensor*>::const_iterator itSensor2;
    for (itSensor2 = sensors.begin() ; itSensor2 != sensors.end(); ++itSensor2) {
      Sensor * sensor2 = *itSensor2;
      if (sensor2->getSensorID() != sensor->getSensorID()) {
        double distance = sensor->getPosition().calculateDistance(sensor2->getPosition());
        distanceMapSensors.insert(pair<double, Sensor*>(distance, sensor2));
      }
    }

    NearSensorStats nearSensorStats;
    multimap<double, Sensor*>::iterator itMapDistance;
    int i;
    for (itMapDistance = distanceMapSensors.begin(), i = 0; itMapDistance != distanceMapSensors.end() && i < 5; ++itMapDistance, ++i) {
      Sensor* nearSensor = itMapDistance->second;

      nearSensorStats.meanO3 += (--nearSensor->getValO3().end())->second / 5.;
      nearSensorStats.meanSO2 += (--nearSensor->getValSO2().end())->second / 5.;
      nearSensorStats.meanNO2 += (--nearSensor->getValNO2().end())->second / 5.;
      nearSensorStats.meanPM10 += (--nearSensor->getValPM10().end())->second / 5.;
    }
    for (itMapDistance = distanceMapSensors.begin(), i = 0; itMapDistance != distanceMapSensors.end() && i < 5; ++itMapDistance, ++i) {
      Sensor* nearSensor = itMapDistance->second;

      nearSensorStats.varianceO3 += pow((--nearSensor->getValO3().end())->second - nearSensorStats.meanO3, 2) / 4.;
      nearSensorStats.varianceSO2 += pow((--nearSensor->getValSO2().end())->second - nearSensorStats.meanSO2, 2) / 4.;
      nearSensorStats.varianceNO2 += pow((--nearSensor->getValNO2().end())->second - nearSensorStats.meanNO2, 2) / 4.;
      nearSensorStats.variancePM10 += pow((--nearSensor->getValPM10().end())->second - nearSensorStats.meanPM10, 2) / 4.;
    }

    if (abs(nearSensorStats.meanO3 - sensorStats.O3) > nearSensorStats.varianceO3 
      || abs(nearSensorStats.meanSO2 - sensorStats.SO2) > nearSensorStats.varianceSO2
      || abs(nearSensorStats.meanSO2 - sensorStats.NO2) > nearSensorStats.varianceNO2
      || abs(nearSensorStats.meanPM10 - sensorStats.PM10) > nearSensorStats.variancePM10) {
        cout << "ATTENTION, le capteur " << sensor->getSensorID() << " semble défectueux." << endl;
      }
  }
}