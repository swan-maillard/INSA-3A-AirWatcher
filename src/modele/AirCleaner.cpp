/*************************************************************************
    AirCleaner
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <AirCleaner> (fichier AirCleaner.cpp) ------------


//---------------------------------------------------------------- INCLUDE
#include <iostream>
#include <string>

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "../../include/AirCleaner.h"


//----------------------------------------------------------------- PUBLIC

bool AirCleaner::addWorkingHours(string &start, string &end)
{
    Date startdate(start);
    Date enddate(end);
    //workingHours.insert(make_pair(startdate, enddate));
    return true;
}

AirCleaner::AirCleaner(string &aLatitude, string &aLongitude, int aProviderId, int aCleanerId) : position(Position(aLatitude, aLongitude))
{
  #ifdef MAP
      cout << "Construction de <AirCleaner>" << endl;
  #endif
    providerId = aProviderId;
    cleanerId = aCleanerId;
}

AirCleaner::~AirCleaner() 
{
  #ifdef MAP
      cout << "Destruction de <AirCleaner>" << endl;
  #endif
}

ostream & operator << (ostream& os, const AirCleaner& AC)
{
    os << "Le AirCleaner :\nID : " << AC.cleanerId << "\tproviderID : " << AC.providerId << "\n A " << AC.position;
    ///TODO ajouter les heures de travail
    return os;
} 