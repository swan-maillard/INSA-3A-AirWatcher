/*************************************************************************
    AirCleanerAnalysis
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AirCleanerAnalysis> (fichier AirCleanerAnalysis.h) ----------------
#if ! defined (AIR_CLEANER_ANALYSIS)
#define AIR_CLEANER_ANALYSIS

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <vector>
#include "AirCleaner.h"
#include "Sensor.h"
#include "Date.h"

class AirCleanerAnalysis {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    AirCleanerAnalysis();

    // Destructeur
    ~AirCleanerAnalysis();

    int checkEfficiency(AirCleaner & cleanerId, const vector<Sensor*> & sensors) const;

//----------------------------------------------------------------- PRIVE
  protected:
//----------------------------------------------------- Attributs protégés


};

#endif // AIR_CLEANER_ANALYSIS_H