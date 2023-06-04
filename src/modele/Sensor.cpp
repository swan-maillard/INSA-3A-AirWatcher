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

double *Sensor::valeurAvAp(Date &d)
{
    double *lesValeurs = new double[8];
    lesValeurs[0] = (--(ValO3.lower_bound(d)))->second;
    lesValeurs[1] = (--(ValNO2.lower_bound(d)))->second;
    lesValeurs[2] = (--(ValSO2.lower_bound(d)))->second;
    lesValeurs[3] = (--(ValPM10.lower_bound(d)))->second;
    lesValeurs[4] = ValO3.lower_bound(d)->second;
    lesValeurs[5] = ValNO2.lower_bound(d)->second;
    lesValeurs[6] = ValSO2.lower_bound(d)->second;
    lesValeurs[7] = ValPM10.lower_bound(d)->second;
    return lesValeurs;
}

Date Sensor::limiteDate(Date &debRecherche, double *values)
{
    DicoMesure::iterator itO3 = ValO3.lower_bound(debRecherche);
    DicoMesure::iterator itNO2 = ValNO2.lower_bound(debRecherche);
    DicoMesure::iterator itSO2 = ValSO2.lower_bound(debRecherche);
    DicoMesure::iterator itPM10 = ValPM10.lower_bound(debRecherche);
    bool finir = false;
    while (itO3 != ValO3.end() && finir == false){
        if (itO3->second > values[0] || itNO2->second > values[1] || itSO2->second > values[2] || itPM10->second > values[3]){
            finir = true;
        }
        else {
            cout << itO3->first << endl;
            itO3++;
            itNO2++;
            itSO2++;
            itPM10++;
        }
    }
    return itO3->first;
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