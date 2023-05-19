/*************************************************************************
    FileAccess
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr, alexandre.biaud@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <FileAccess> (fichier FileAccess.h) ----------------
#if ! defined (FILEACCESS_H)
#define FILEACCESS_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <vector>
#include <fstream>

#include "AirCleaner.h"
#include "Sensor.h"

class FileAccess {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    FileAccess();

    bool generateCleaners(vector<AirCleaner*> &lesCleaners, string providers = "data/providers.csv", string cleaners = "data/cleaners.csv");
    bool generateSensors(vector<Sensor*> &lesSensors);

    // Destructeur
    ~FileAccess();

//----------------------------------------------------------------- PRIVE
  protected:
  
    bool mapUsers(map<string, string> &users);
//----------------------------------------------------- Attributs protégés


};

#endif // FILEACCESS_H