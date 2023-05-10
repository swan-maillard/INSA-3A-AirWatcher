/*************************************************************************
    Position
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Position> (fichier Position.h) ----------------
#if ! defined (POSITION_H)
#define POSITION_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>

class Position {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    bool isIn(Position posCentre, double rayon);

    double calculateDistance(Position pos);

    double getLongitude();

    double getLatitude();

    double strToDouble(string str);

    void setLongitude(double longitude);

    void setLatitude(double latitude);
    // Constructeur
    Position(double latitude, double longitude);

    Position(string lat = "0.0", string lon = "0.0");

    friend std::ostream& operator << (std::ostream& os, const Position & unePos);

    // Destructeur
    ~Position();

//----------------------------------------------------------------- PRIVE
  protected:
    double latitude;
    double longitude;
//----------------------------------------------------- Attributs protégés


};

#endif // POSITION_H