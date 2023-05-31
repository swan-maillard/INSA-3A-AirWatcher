/*************************************************************************
    System
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <System> (fichier System.h) ----------------
#if ! defined (SYSTEM_H)
#define SYSTEM_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <vector>
#include "AirCleaner.h"
#include "Sensor.h"
#include "PrivateIndividuals.h"
#include "FileAccess.h"
#include "AirCleanerAnalysis.h"

class System {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    System();

    // Destructeur
    ~System();

    void listSensors() const;

    void infoSensor(const int id) const;

    bool getIsCorrupt() const;

    void listAirCleaners() const;

    void scanSensors(const int time) const;
    void statsAirCleaner(const int time) const;
    void oneSensor();


//----------------------------------------------------------------- PRIVE
  private:
//----------------------------------------------------------------- PROTECTED
  protected:
    FileAccess factory;
    vector<Sensor*> sensors;
    vector<AirCleaner*> airCleaners;
    vector<PrivateIndividuals> individuals;
    bool isCorrupt;
//----------------------------------------------------- Attributs protégés


};

#endif // SYSTEM_H