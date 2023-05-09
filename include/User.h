/*************************************************************************
    User
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined (USER_H)
#define USER_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>

class User {

//----------------------------------------------------------------- PUBLIC
  public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    User();

    // Destructeur
    ~User();

    int checkPwd(const string & p) const;

//----------------------------------------------------------------- PRIVE
  private:
    string login;
    string password;
  protected:
//----------------------------------------------------- Attributs protégés


};

#endif // USER_H