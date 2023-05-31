/*************************************************************************
    System
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <System> (fichier System.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

//------------------------------------------------------ Include personnel
#include "../../include/System.h"
#include "../../include/SensorAnalysis.h"

//----------------------------------------------------------------- PUBLIC

System::System()
{
#ifdef MAP
  cout << "Construction de <System>" << endl;
#endif
  isCorrupt = false;
  if (!factory.generateCleaners(airCleaners))
  {
    cerr << "Erreur lors de la génération des airCleaners" << endl;
    isCorrupt = true;
  }
  else if (!factory.generateSensors(sensors))
  {
    cerr << "Erreur lors de la génération des airSensors" << endl;
    isCorrupt = true;
  }
}

System::~System()
{
  vector<AirCleaner *>::iterator it;
  for (it = airCleaners.begin(); it != airCleaners.end(); ++it)
  {
    delete *it;
  }
  vector<Sensor *>::iterator it2;
  for (it2 = sensors.begin(); it2 != sensors.end(); ++it2)
  {
    delete *it2;
  }
#ifdef MAP
  cout << "Destruction de <System>" << endl;
#endif
}

bool System::getIsCorrupt() const
{
  return isCorrupt;
}

void System::infoSensor(const int id) const
{
  cout << &(sensors.at(id)) << endl;
}

void System::listAirCleaners() const
{
  vector<AirCleaner *>::const_iterator it;
  for (it = airCleaners.cbegin(); it != airCleaners.cend(); ++it)
  {
    cout << **it << endl;
  }
  cout << endl;
}

void System::statsAirCleaner() const
{
  vector<AirCleaner *>::const_iterator it;
  int choix;
  for (it = airCleaners.cbegin(); it != airCleaners.cend(); ++it)
  {
    cout << **it << endl;
  }
  cout << "Quel airCleaners voulez-vous tester ?\nVotre choix : ";
  cin >> choix;
  while (choix < 0 || choix > (int)airCleaners.size()-1){
    cout << "Veuillez entrer une valeur entre 0 et " << airCleaners.size() - 1 << " :" << endl;
    cin >> choix;
  }
  AirCleanerAnalysis airCleanerAnalysis;
  AirCleaner airCleaner;
  for (it = airCleaners.cbegin() ; it != airCleaners.cend(); ++it){
    if((**it).getCleanerId() == choix)
      airCleaner = **it;
  }

  // it = airCleaners.cbegin();
  // double pos = (*it)->getPosition().calculateDistance((*(++it))->getPosition());
  // cout << "distance entre les 2 air cleaners : " << pos << endl;
  clock_t t = clock();
  double distanceEfficace = airCleanerAnalysis.checkEfficiency(airCleaner, sensors);
  printf("Temps d'execution pour efficacité d'un airCleaner : %.3fs\n", ((double) (clock() - t)) / CLOCKS_PER_SEC);
  cout << "La distance efficace de l'air Cleaner est d'environ : " << distanceEfficace << endl;

}

void System::oneSensor()
{
  cout << "Choisis ton capteur entre 0 et " << sensors.size() - 1;
  cout << "\nVotre choix : ";
  int choix;
  cin >> choix;
  while (choix > (int)sensors.size() - 1 || choix < 0){
    cout << "Reesayez : ";
    cin >> choix;
  }
  sensors.at(choix)->affichageComplet();
  cout << endl;
}

void System::listSensors() const
{
    vector<Sensor*>::const_iterator it;
    for (it = sensors.begin() ; it < sensors.end() ; ++it){
      cout << **it;
    }
    cout << endl;
}

void System::scanSensors() const {
  clock_t t = clock();
  SensorAnalysis sensorAnalysis;
  sensorAnalysis.scanSensors(sensors);
}