/*************************************************************************
    AirCleaner
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
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

    bool addWorkingHours(string &start, string &end);
    // Constructeur
    AirCleaner(string &aLatitude, string &aLongitude, int providerId, int cleanerId);

    Position getPosition();
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
