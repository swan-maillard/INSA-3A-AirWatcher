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

Position Sensor::getPosition()
{
    return pos;
}

void Sensor::addO3Val(string &date, string &val)
{
    Date d(date);
    ValO3.insert(make_pair(d, strToInt(val)));
}

void Sensor::addNO2Val(string &date, string &val)
{
    Date d(date);
    ValNO2.insert(make_pair(d, strToInt(val)));
}

void Sensor::addSO2Val(string &date, string &val)
{
    Date d(date);
    ValSO2.insert(make_pair(d, strToInt(val)));
}

void Sensor::addPH10Val(string &date, string &val)
{
    Date d(date);
    ValPH10.insert(make_pair(d, strToInt(val)));
}

ostream &operator<<(ostream &os, const Sensor &S)
{
    os << "SensorID : " << S.sensorID << "\tUserID : " << S.userID << "\n  A la position : " << S.pos;
    ///TODO afficher les valeurs des differents relevés
    return os;
}

int Sensor::strToInt(string s){
  int nb = 0;
  long unsigned int i;
  for (i = 0 ; i < s.length() ; i++){
    nb*=10;
    nb += (s.at(i) - 48);
  }
  return nb;
}
