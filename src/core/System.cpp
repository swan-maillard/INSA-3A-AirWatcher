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
  cout << "## Liste des AirCleaners ##\n";
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
  int ind = 1, choix;
  for (it = airCleaners.cbegin(); it != airCleaners.cend(); ++it)
  {
    cout << ind << ": " << **it << endl;
    ind++;
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

  int somme = airCleanerAnalysis.checkEfficiency(airCleaner, sensors);
  cout << somme << endl;

}

void System::listSensors() const
{
    /*vector<Sensor*>::const_iterator it;
    vector<Sensor*> prive;
    for (it = sensors.cbegin() ; it != sensors.cend(); ++it){
      Sensor s = **it;
      if (s.userID < 0)
        cout << "generateur du gov" << endl;
      else 
        cout << "generateur de particulier" << endl;
    }*/
    cout << endl;
}

void System::scanSensors() const {
  SensorAnalysis sensorAnalysis;
  sensorAnalysis.scanSensors(sensors);
}