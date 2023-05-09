/*************************************************************************
    Date
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "../../include/Date.h"


//----------------------------------------------------------------- PUBLIC

Date::Date(string uneDate) {
  #ifdef MAP
      cout << "Construction de <Date>" << endl;
  #endif
  string temp = uneDate.substr(0,4);
  year = strToInt(temp);
  temp = uneDate.substr(5,2);
  month = strToInt(temp);
  temp = uneDate.substr(8,2);
  day = strToInt(temp);
  temp = uneDate.substr(11,2);
  hour = strToInt(temp);
  temp = uneDate.substr(14,2);
  min = strToInt(temp);
  temp = uneDate.substr(17,2);
  sec = strToInt(temp);
}

Date::~Date() {
  #ifdef MAP
      cout << "Destruction de <Date>" << endl;
  #endif
}

int Date::strToInt(string s){
  int nb = 0;
  long unsigned int i;
  for (i = 0 ; i < s.length() ; i++){
    nb*=10;
    nb += (s.at(i) - 48);
  }
  return nb;
}

ostream & operator << (ostream& os, const Date& uneDate)
{
    os << "La date : " << uneDate.year << "-" << uneDate.month << "-" << uneDate.day << (uneDate.hour < 10 ? " 0" : " " )<< uneDate.hour << (uneDate.min < 10 ? "h0" : "h" ) << uneDate.min << (uneDate.sec < 10 ? "m0" : "m" ) << uneDate.sec;
    return os;
} 