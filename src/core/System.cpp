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


//----------------------------------------------------------------- PUBLIC

System::System() {
  #ifdef MAP
      cout << "Construction de <System>" << endl;
  #endif
  factory.generateCleaners(airCleaners);
  factory.generateSensors(sensors);
}

System::~System() {
  vector<AirCleaner*>::iterator it;
  for (it = airCleaners.begin() ; it != airCleaners.end() ; ++it){
    delete *it;
  }
  vector<Sensor*>::iterator it2;
  for (it2 = sensors.begin() ; it2 != sensors.end() ; ++it2){
    delete *it2;
  }
  #ifdef MAP
      cout << "Destruction de <System>" << endl;
  #endif
}

void System::infoSensor(const int id) const
{
  cout << &(sensors.at(id)) << endl;
}

void System::listAirCleaners() const
{
  cout << "## Liste des AirCleaners ##\n";
  vector<AirCleaner*>::const_iterator it;
  for (it = airCleaners.cbegin() ; it != airCleaners.cend(); ++it){
      cout << **it << endl;
  }
  cout << endl;
}

void System::listSensors() const
{
    cout << "## Liste des Sensors ##\n";
    vector<Sensor*>::const_iterator it;
    for (it = sensors.cbegin() ; it != sensors.cend(); ++it){
        cout << **it << endl;
    }
    cout << endl;
}