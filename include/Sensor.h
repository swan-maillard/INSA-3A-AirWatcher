/*************************************************************************
    Sensor
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined (SENSOR_H)
#define SENSOR_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <vector>
#include <map>

#include "Position.h"
#include "Date.h"

typedef map<Date, double> DicoMesure;

class Sensor {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    Sensor(string &lat, string &lon, int aSensorID, int aUserID);
    //TODO Faire un constructeur de copie

    // Destructeur
    ~Sensor();

    void addValue(string &date, string &val, string &type);

    Position getPosition();

    friend std::ostream& operator << (std::ostream& os, const Sensor &S);

//----------------------------------------------------------------- PRIVE
  protected:
    Position pos;
    int sensorID;
    int userID;
    DicoMesure ValO3;
    DicoMesure ValNO2;
    DicoMesure ValSO2;
    DicoMesure ValPM10;

    int strToInt(string &s);
    double strToDouble(string &str);
};

#endif // SENSOR_H