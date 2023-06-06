/*************************************************************************
    PrivateIndividuals
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <PrivateIndividuals> (fichier PrivateIndividuals.h) ----------------
#if ! defined (PRIVATE_INDIVIDUALS_H)
#define PRIVATE_INDIVIDUALS_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <vector>
#include "Sensor.h"

class PrivateIndividuals {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    PrivateIndividuals();

    // Destructeur
    ~PrivateIndividuals();

    int getBonReduction();

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés
  int points;
  int id;
  bool isExcluded;
  vector<Sensor*> sensorsProvided;

};

#endif // AIR_WATCHER_H