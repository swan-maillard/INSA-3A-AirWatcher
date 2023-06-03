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

AirCleanerAnalysis::AirCleanerAnalysis()
{
#ifdef MAP
  cout << "Construction de <AirCleanerAnalysis>" << endl;
#endif
}

AirCleanerAnalysis::~AirCleanerAnalysis()
{
#ifdef MAP
  cout << "Destruction de <AirCleanerAnalysis>" << endl;
#endif
}

double *AirCleanerAnalysis::checkEfficiency(AirCleaner &airCleaner, const vector<Sensor *> &sensors) const
{
  bool efficace = true;
  bool efficaceNO2 = true;
  bool efficaceO3 = true;
  bool efficaceSO2 = true;
  bool efficacePM10 = true;
  double distance = 0.3;
  double distanceNO2 = 0.3;
  double distanceO3 = 0.3;
  double distanceSO2 = 0.3;
  double distancePM10 = 0.3;
  bool maxDist = false;
  while (efficace && !maxDist)
  {
    
    //cout << "efficace : " << efficace << " / distance : " << distance << endl;
    vector<Sensor *>::const_iterator it;
    double bestDistance = -1;
    Sensor *s;

    for (it = sensors.begin(); it != sensors.end(); ++it)
    {
      Sensor *s1 = *it;
      // cout << "Pour le capteur " << s->getSensorID() << " situé en " << s->getPosition() << endl;

      multimap<double, Sensor *> distanceMapSensors;
      double currentDistance = airCleaner.getPosition().calculateDistance(s1->getPosition());
      // cout << "current distance : " << currentDistance << endl;
      if (currentDistance < distance && currentDistance < 7 && currentDistance/distance > 0.7 && currentDistance/distance > 1.2)
      {
        bestDistance = currentDistance;
        s = *it;
      }
      // cout << "best distance : " << bestDistance << endl;
    }

    Date avant("2019-01-31 12:00:00");
    Date apres("2019-03-02 12:00:00");
    if (bestDistance != -1 && distance < 7)
    {
      //cout << "best distance : " << bestDistance << " / pour le capteur : " << s->getSensorID() << endl;
      //cout << "valeur en N02 : " << s->getValNO2().find(avant)->second << " / valeur en N02 après : " << s->getValNO2().find(apres)->second << endl;
      //cout << "valeur en O3 : " << s->getValO3().find(avant)->second << " / valeur en O3 après : " << s->getValO3().find(apres)->second << endl;
      //cout << "valeur en SO2 : " << s->getValSO2().find(avant)->second << " / valeur en SO2 après : " << s->getValSO2().find(apres)->second << endl;
      //cout << "valeur en PM10 : " << s->getValPM10().find(avant)->second << " / valeur en PM10 après : " << s->getValPM10().find(apres)->second << endl;
      //cout << endl;
      if (s->getValNO2().find(avant)->second > s->getValNO2().find(apres)->second)
        efficaceNO2 = false;
      else if (efficaceNO2 && bestDistance > distanceNO2)
        distanceNO2 = bestDistance;
      if (s->getValO3().find(avant)->second > s->getValO3().find(apres)->second)
        efficaceO3 = false;
      else if (efficaceO3 && bestDistance > distanceO3)
        distanceO3 = bestDistance;
      if (s->getValSO2().find(avant)->second > s->getValSO2().find(apres)->second)
        efficaceSO2 = false;
      else if (efficaceSO2 && bestDistance > distanceSO2)
        distanceSO2 = bestDistance;
      if (s->getValPM10().find(avant)->second > s->getValPM10().find(apres)->second)
        efficacePM10 = false;
      else if (efficacePM10 && bestDistance > distancePM10)
        distancePM10 = bestDistance;

      distance = distance + 0.1;
      if (!efficaceNO2 && !efficaceO3 && !efficaceSO2 && !efficacePM10)
        efficace = false;
    }
    else
    {
      maxDist = true;
    }
  }
  double *distances = new double[4];
  distances[0] = distanceNO2;
  distances[1] = distanceO3;
  distances[2] = distanceSO2;
  distances[3] = distancePM10;
  return distances;
}