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
#include "Sensor.h"

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

Position Sensor::getPosition()
{
    return pos;
}

void Sensor::addValue(string &date, string &val, string &type)
{
    Date d(date);
    double valeur = strToDouble(val);
    if (type == "O3"){
        ValO3.insert(make_pair(d, valeur));
    } else if (type == "NO2"){
        ValNO2.insert(make_pair(d, valeur));
    } else if (type == "SO2"){
        ValSO2.insert(make_pair(d, valeur));
    } else if (type == "PM10"){
        ValPM10.insert(make_pair(d, valeur));
    }
}

ostream &operator<<(ostream &os, const Sensor &S)
{
    os << "SensorID : " << S.sensorID << "\tUserID : " << S.userID << "\n  A la position : " << S.pos;
    DicoMesure::const_iterator i1, i2, i3, i4;
    i1 = S.ValO3.cbegin();
    i2 = S.ValNO2.cbegin();
    i3 = S.ValSO2.cbegin();
    i4 = S.ValPM10.cbegin();
    while (i1 != S.ValO3.cend()){
        os << "\nA la date ";

        ++i1; ++i2; ++i3; ++i4;
    }

    return os;
}

int Sensor::strToInt(string &s){
  int nb = 0;
  long unsigned int i;
  for (i = 0 ; i < s.length() ; i++){
    nb*=10;
    nb += (s.at(i) - 48);
  }
  return nb;
}

double Sensor::strToDouble(string &str){
    double nb = 0;
    long unsigned int i = 0, p = 10;
    while (i < str.length() && str.at(i) != '.'){
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