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

System::System()
{
#ifdef MAP
  cout << "Construction de <System>" << endl;
#endif
  if (!factory.generateCleaners(airCleaners))
  {
    cerr << "Erreur lors de la génération des airCleaners" << endl;
    vector<AirCleaner *>::iterator it;
    for (it = airCleaners.begin(); it != airCleaners.end(); ++it)
    {
      delete *it;
    }
    exit(1);
  }
  factory.generateSensors(sensors);
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
  vector<AirCleaner*>::const_iterator it;
  int ind = 1, choix;
  for (it = airCleaners.cbegin() ; it != airCleaners.cend(); ++it){
      cout << ind << ": " << **it << endl;
      ind++;
  }
  cout << "Quel airCleaners voulez-vous tester ?\nVotre choix : ";
  cin >> choix;
  while (choix > 2 && choix < 1){
    cout << "Essayez a nouveau : ";
    cin >> choix;
  }

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