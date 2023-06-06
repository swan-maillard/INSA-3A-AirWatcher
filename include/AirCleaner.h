/*************************************************************************
    AirCleaner
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
*************************************************************************/

//---------- Interface de la classe <AirCleaner> (fichier AirCleaner.h) ----------------
#if ! defined (AIRCLEANER_H)
#define AIRCLEANER_H

//---------------------------------------------------------------- INCLUDE
#include "Position.h"
#include "Date.h"
//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <map>

class AirCleaner {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeurs
    AirCleaner();
    AirCleaner(const string &aLatitude, const string &aLongitude, const int providerId, const int cleanerId);

    Position getPosition();

    int getCleanerId();

    // Renvoie les périodes de fonctionnement de l'AirCleaner <début, fin>
    map<Date, Date> getWorkingHours();

    // Ajoute une période de fonctionnement pour l'AirCleaner
    bool addWorkingHours(const string &start, const string &end);

    // Destructeur
    ~AirCleaner();

    friend std::ostream& operator << (std::ostream& os, const AirCleaner & AC);

//----------------------------------------------------------------- PRIVE
  protected:
    Position position;
    int providerId;
    int cleanerId;
    map<Date, Date> workingHours;

//----------------------------------------------------- Attributs protégés


};

#endif // AIRCLEANER_H
