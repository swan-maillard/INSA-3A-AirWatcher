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

    // Constructeurs
    Position(double latitude, double longitude);
    Position(string lat = "0.0", string lon = "0.0");

    // Calcule la distance en km avec une autre position
    double calculateDistance(Position pos);

    // Renvoit true si la position se situe dans un périmètre définit par un centre et un rayon
    bool isIn(Position posCentre, double rayon);

    double getLongitude();

    double getLatitude();

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