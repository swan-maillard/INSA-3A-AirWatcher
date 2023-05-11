/*************************************************************************
    FileAccess
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD, Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <FileAccess> (fichier FileAccess.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../../include/FileAccess.h"

//----------------------------------------------------------------- PUBLIC

FileAccess::FileAccess() {
  #ifdef MAP
      cout << "Construction de <FileAccess>" << endl;
  #endif


}

 bool FileAccess::generateCleaners(vector<AirCleaner*> &lesCleaners, string providersFN, string cleanerFN){
  ifstream providersFile;
  providersFile.open(providersFN);
  if (!providersFile){
    cout << "erreur lors de l'ouverture du fichier providers";
    return false;
  }
  ifstream cleanersFile;
  cleanersFile.open(cleanerFN);
  if (!cleanersFile){
    cout << "erreur lors de l'ouverture du fichier cleaner";
    return false;
  }

  string provider, cleaner, temp, lat, lon, deb, fin;
  getline(cleanersFile, temp, ';');
  while (getline(providersFile, provider, ';'), !providersFile.eof()){
    getline(providersFile, cleaner, ';');
    getline(cleanersFile, lat, ';');
    getline(cleanersFile, lon, ';');
    AirCleaner* ac = new AirCleaner(lat, lon, provider.at(provider.length()-1) - 48, cleaner.at(7) - 48);
    lesCleaners.push_back(ac);
    while (temp == cleaner){
      getline(cleanersFile, deb, ';');
      getline(cleanersFile, fin, ';');
      ac->addWorkingHours(deb, fin);
      getline(cleanersFile, temp, '\n');
      getline(cleanersFile, temp, ';');
      if (cleaner == temp) {
        getline(cleanersFile, lat, ';');
        getline(cleanersFile, lon, ';');
      }
    }
  }
  return true;
}

bool FileAccess::generateSensors(vector<Sensor *> &lesSensors)
{
  map<string, string> users;
  if (mapUsers(users) == false){
    return false;
  }

  return false;
}

FileAccess::~FileAccess()
{
#ifdef MAP
  cout << "Destruction de <FileAccess>" << endl;
#endif
}

bool FileAccess::mapUsers(map<string, string> &users)
{
  ifstream userFile;
  if (!userFile){
    cout << "erreur lors de l'ouverture du fichier cleaner";
    return false;
  }
  string userID, sensorID, temp;
  userFile.open("data/users.csv");
  while (!userFile.eof()){
    getline(userFile, userID, ';');
    getline(userFile, sensorID, ';');
    getline(userFile, temp);
    users.insert(make_pair(sensorID, userID));
  }
  return true;
}
