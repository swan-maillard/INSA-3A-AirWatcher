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
    Sensor(const string &lat, const string &lon, const int aSensorID, const int aUserID);
    //TODO Faire un constructeur de copie

    // Destructeur
    ~Sensor();

    void addValue(const string &date, const string &val, const string &type);
    double* valeurAvantEtApres(Date &d, Date &f);
    Date limiteDate(Date &debRecherche, double* values);

    Position    getPosition() const { return pos;      }
    int         getSensorID() const { return sensorID; }
    int         getUserID()   const { return userID;   }
    DicoMesure  getValO3()    const { return ValO3;    }
    DicoMesure  getValNO2()   const { return ValNO2;   }
    DicoMesure  getValSO2()   const { return ValSO2;   }
    DicoMesure  getValPM10()  const { return ValPM10;  }

    void affichageComplet() const; 

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
};

#endif // SENSOR_H