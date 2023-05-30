/*************************************************************************
    SensorAnalysis
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SensorAnalysis> (fichier SensorAnalysis.h) ----------------
#if ! defined (SENSOR_ANALYSIS_H)
#define SENSOR_ANALYSIS_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>

#include "Sensor.h"


class SensorAnalysis {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    SensorAnalysis();

    // Destructeur
    ~SensorAnalysis();

    void scanSensors(const vector<Sensor*> & sensors);

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés


};

#endif // SENSOR_ANALYSIS_H