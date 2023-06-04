/*************************************************************************
    Position
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Position> (fichier Position.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <cmath>

//------------------------------------------------------ Include personnel
#include "../../include/Position.h"
#include "../../include/Util.h"


//----------------------------------------------------------------- PUBLIC

double Position::calculateDistance(Position otherPosition) {
    double lat1 = this->latitude * M_PI / 180.;
    double lon1 = this->longitude * M_PI / 180.;
    double lat2 = otherPosition.latitude * M_PI / 180.;
    double lon2 = otherPosition.longitude * M_PI / 180.;
    return(acos(sin(lon1)*sin(lon2)+cos(lon1)*cos(lon2)*cos(lat1-lat2))*6371);
}

bool Position::isIn(Position otherPosition, double radius) {
    return(this->calculateDistance(otherPosition) <= radius);
}

double Position::getLatitude() {
    return(this->latitude);
}

double Position::getLongitude() {
    return(this->longitude);
}

Position::Position(double latitude, double longitude) {
  #ifdef MAP
      cout << "Construction de <Position> avec this = " << this << endl;
  #endif
    this->latitude = latitude;
    this->longitude = longitude;
}

Position::Position(string lat, string lon) {
  #ifdef MAP
      cout << "Construction de <Position> avec this = " << this << endl;
  #endif
    this->latitude = strToDouble(lat);
    this->longitude = strToDouble(lon);
}

Position::~Position() {
  #ifdef MAP
      cout << "Destruction de <Position> avec this = " << this << endl;
  #endif
}

ostream & operator << (ostream& os, const Position& unePos)
{
    os << "latitude :" << unePos.latitude << "; longitude : " << unePos.longitude;
    return os;
} 