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
#include "../../include/Util.h"

Sensor::Sensor(const string &lat, const string &lon, const int aSensorID, const int aUserID) : pos(Position(lat,lon)), sensorID(aSensorID), userID(aUserID)
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

void Sensor::addValue(const string &date, const string &val,const string &type)
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
    os << "SensorID : " << S.sensorID << "\tUserID : ";
    if (S.getUserID() == -1)
        os << "Gouv";
    else 
        os << "User" << S.getUserID();
    os  << "  position : " << S.pos << endl;

    return os;
}

void Sensor::affichageComplet() const {
    cout << "SensorID : " << sensorID << "\tUserID : " << userID << "\n  A la position : " << pos;
    DicoMesure::const_iterator i1, i2, i3, i4;
    i1 = ValO3.cbegin();
    i2 = ValNO2.cbegin();
    i3 = ValSO2.cbegin();
    i4 = ValPM10.cbegin();
    while (i1 != ValO3.cend()){
        cout << "\nA la date " << i1->first << "\t03 : " << i1->second << "\tNO2 : " << i2->second << "\tSO2 : " << i3->second << "\tPM10 : " << i4->second;
        ++i1; ++i2; ++i3; ++i4;
    }
}