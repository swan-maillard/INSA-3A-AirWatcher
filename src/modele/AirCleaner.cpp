/*************************************************************************
    AirCleaner
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <AirCleaner> (fichier AirCleaner.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../../include/AirCleaner.h"


//----------------------------------------------------------------- PUBLIC

bool AirCleaner::addWorkingHours(string &start, string &end)
{
    Date startdate(start);
    Date enddate(end);
    workingHours.insert(make_pair(startdate, enddate));
}

AirCleaner::AirCleaner(double &uneLongitude, double &uneLatitude, int &unProviderId, int &unCleanerId) : position(Position(uneLongitude, uneLatitude))
{
  #ifdef MAP
      cout << "Construction de <AirCleaner>" << endl;
  #endif
    providerId = unProviderId;
    cleanerId = unCleanerId;
}

AirCleaner::~AirCleaner() 
{
  #ifdef MAP
      cout << "Destruction de <AirCleaner>" << endl;
  #endif
}

