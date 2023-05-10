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


//----------------------------------------------------------------- PUBLIC

double Position::calculateDistance(Position otherPosition) {
    double lat1 = this->latitude;
    double lon1 = this->longitude;
    double lat2 = otherPosition.latitude;
    double lon2 = otherPosition.longitude;
    return(sqrt(pow(lat1 - lat2, 2) + pow(lon1 - lon2, 2)));
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

double Position::strToDouble(string str){
    double nb = 0;
    long unsigned int i = 0, p = 10;
    while (str.at(i) != '.'){
        nb *= 10;
        nb += str.at(i) - 48;
        i++;
    }
    i++;
    while (i < str.length()){
        nb += double(str.at(i) - 48 ) / p;
        p*=10;
        i++;
    }
    return nb;
}

ostream & operator << (ostream& os, const Position& unePos)
{
    os << "La position : latitude :" << unePos.latitude << "; longitude : " << unePos.longitude;
    return os;
} 