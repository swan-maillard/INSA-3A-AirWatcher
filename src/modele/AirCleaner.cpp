/*************************************************************************
    AirCleaner
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD Alexandre, MAILLARD Swan, GIRAUDON Clément
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

bool AirCleaner::addWorkingHours(const string &start, const string &end)
{
    Date startdate(start);
    Date enddate(end);
    workingHours.insert(make_pair(startdate, enddate));
    return true;
}

AirCleaner::AirCleaner(const string &aLatitude, const string &aLongitude, const int aProviderId, const int aCleanerId) : position(Position(aLatitude, aLongitude))
{
  #ifdef MAP
      cout << "Construction de <AirCleaner>" << endl;
  #endif
  providerId = aProviderId;
  cleanerId = aCleanerId;
}

Position AirCleaner::getPosition()
{
  return position;
}

AirCleaner::~AirCleaner()
{
  #ifdef MAP
      cout << "Destruction de <AirCleaner>" << endl;
  #endif
}

ostream & operator << (ostream& os, const AirCleaner& AC)
{
    os << "CleanerID : " << AC.cleanerId << "\tproviderID : " << AC.providerId << "\nA la position : " << AC.position;
    map<Date, Date>::const_iterator it;
    for (it = AC.workingHours.cbegin() ; it != AC.workingHours.cend() ; ++it){
        os << "\nDe : " << (it->first) << " -> " << (it->second);
    }
    return os;
} 