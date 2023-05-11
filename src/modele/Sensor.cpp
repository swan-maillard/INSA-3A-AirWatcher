/*************************************************************************
    Sensor
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../../include/Sensor.h"

Sensor::Sensor(string &lat, string &lon, int aSensorID, int aUserID) : pos(Position(lat,lon)), sensorID(aSensorID), userID(aUserID)
{
#ifdef MAP
    cout << "Constructeur de <Sensor>" << endl;
#endif
}

Sensor::~Sensor()
{
#ifdef MAP
      cout << "Destruction de <Sensor>" << endl;
  #endif
}

ostream & operator << (ostream& os, const Sensor &S)
{
    os << "SensorID : " << S.sensorID << "\tUserID : " << S.userID << "\n  A la position : " << S.pos;
    /*
    map<Date*, Date*>::const_iterator it;
    for (it = AC.workingHours.cbegin() ; it != AC.workingHours.cend() ; ++it){
        os << "\nDe : " << *(it->first) << " -> " << *(it->second);
    }*/
    return os;
} 
