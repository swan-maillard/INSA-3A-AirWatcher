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

void AirCleanerAnalysis::checkEfficiency(AirCleaner &airCleaner, const vector<Sensor *> &sensors) const
{
  multimap<double, Sensor*> distanceMapSensors;
  vector<Sensor*>::const_iterator itSensor;
  for (itSensor = sensors.begin() ; itSensor != sensors.end(); ++itSensor) {
    Sensor *sensor = *itSensor;
    double distance = airCleaner.getPosition().calculateDistance(sensor->getPosition());
    distanceMapSensors.insert(pair<double, Sensor*>(distance, sensor));
  }
  Date debut = airCleaner.getWorkingHours().begin()->first;
  Date fin = airCleaner.getWorkingHours().begin()->second;
  double efficacite[4], borne[4];
  bool finir = false;

  multimap<double, Sensor*>::iterator it = distanceMapSensors.begin();
  double *val;
  val = it->second->valeurAvantEtApres(debut, fin);
  for (int i = 0 ; i < 4 ; i++){
    efficacite[i] = (val[i] - val[4+i]) / val[i];
  }
  delete[] val;
  if (efficacite[0] < 0.05 && efficacite[1] < 0.05 && efficacite[2] < 0.05 && efficacite[3] < 0.05){
    cout << endl << "Ce air Cleaner n'a eu aucun effet sur l'air environnant, il faudrait le réviser ou le déplacer !\n";
    return;
  }

  cout << endl << "L'efficacite de l'air Cleaner pour NO2 est de : " << (int)(100*efficacite[0]) << "%" << endl;
  cout << "L'efficacite de l'air Cleaner pour O3 est de : " << (int)(100*efficacite[1]) << "%" << endl;
  cout << "L'efficacite de l'air Cleaner pour SO2 est de : " << (int)(100*efficacite[2])  << "%" << endl;
  cout << "L'efficacite de l'air Cleaner pour PM10 est de : " << (int)(100*efficacite[3]) << "%" << endl;

  it++;
  while (it != distanceMapSensors.end() && finir == false) {
    val = it->second->valeurAvantEtApres(debut, fin);
    for (int i = 0 ; i < 4 ; i++){
      efficacite[i] = (val[i] - val[4+i]) / val[i];
    }
    if (efficacite[0] < 0.05 && efficacite[1] < 0.05 && efficacite[2] < 0.05 && efficacite[3] < 0.05)
      finir = true;
    else
      ++it;
    delete[] val;
  }
  --it;

  double rayon = airCleaner.getPosition().calculateDistance(it->second->getPosition());
  cout << endl << "Le rayon de fonctionnement est de " << rayon << " km" << endl;
}