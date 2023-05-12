/*************************************************************************
    Date
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined (DATE_H)
#define DATE_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>

class Date {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    Date(string uneDate = "2000-00-00 00:00:00");

    // Destructeur
    ~Date();

    bool operator < (const Date & uneDate) const;
    bool operator == (const Date & uneDate) const;
    friend std::ostream& operator << (std::ostream& os, const Date & uneDate);

//----------------------------------------------------------------- PRIVE
  protected:

    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;

    int strToInt(string s);
//----------------------------------------------------- Attributs protégés


};

#endif // DATE_H