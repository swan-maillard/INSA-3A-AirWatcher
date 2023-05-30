/*************************************************************************
    FileAccess
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par WARIN Hugo, BIAUD Alexandre, MAILLARD Swan, GIRAUDON Clément
    e-mail               : hugo.warin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <FileAccess> (fichier FileAccess.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cassert>
#include <stdexcept>

//------------------------------------------------------ Include personnel
#include "../../include/FileAccess.h"
#include "../../include/Util.h"

//----------------------------------------------------------------- PUBLIC

FileAccess::FileAccess()
{
#ifdef MAP
  cout << "Construction de <FileAccess>" << endl;
#endif
}

bool FileAccess::generateCleaners(vector<AirCleaner *> &lesCleaners, string providersFN, string cleanerFN)
{
  ifstream providersFile;
  providersFile.open(providersFN.c_str());
  if (!providersFile)
  {
    cout << "erreur lors de l'ouverture du fichier providers";
    return false;
  }
  ifstream cleanersFile;
  cleanersFile.open(cleanerFN.c_str());
  if (!cleanersFile)
  {
    cout << "erreur lors de l'ouverture du fichier cleaner";
    return false;
  }

  string provider, cleaner, temp, lat, lon, deb, fin;
  getline(cleanersFile, temp, ';');
  while (getline(providersFile, provider, ';'), !providersFile.eof())
  {

    getline(providersFile, cleaner, ';');
    getline(cleanersFile, lat, ';');
    getline(cleanersFile, lon, ';');
    AirCleaner *ac;
    try
    {
      ac = new AirCleaner(lat, lon, provider.at(provider.length() - 1) - 48, cleaner.at(7) - 48);

      while (temp == cleaner)
      {
        getline(cleanersFile, deb, ';');
        getline(cleanersFile, fin, ';');
        ac->addWorkingHours(deb, fin);

        getline(cleanersFile, temp, '\n');
        getline(cleanersFile, temp, ';');
        if (cleaner == temp)
        {
          getline(cleanersFile, lat, ';');
          getline(cleanersFile, lon, ';');
        }
      }
      lesCleaners.push_back(ac);
    }
    catch (exception e)
    {
      if(ac != nullptr)
        delete ac;
      cerr << "erreur lors de la lecture des fichiers" << endl;
      return false; // Il serait plus propre de gérer l'erreur en libérant la mémoire
    }
  }

  cleanersFile.close();
  providersFile.close();
  return true;
}

bool FileAccess::generateSensors(vector<Sensor *> &lesSensors)
{
  map<string, string> users;
  if (mapUsers(users) == false)
  {
    return false;
  }
  /*
  map<string, string>::iterator it;
  for (it = users.begin(); it != users.end() ; ++it){
    cout << it->first << " : " << it->second << endl;
  }*/

  ifstream sensorFile;
  sensorFile.open("data/sensors.csv");
  if (!sensorFile)
  {
    cout << "erreur lors de l'ouverture du fichier sensor";
    return false;
  }
  int userID = 0, sensorID = 0;
  string sid, lat, lon, uid;
  while (getline(sensorFile, sid, ';'), !sensorFile.eof())
  {
    getline(sensorFile, lat, ';');
    getline(sensorFile, lon, ';');

    map<string, string>::iterator it;
    it = users.find(sid);
    if (it == users.end())
    {
      userID = -1; // il s'agit du gouvernement
    }
    else
    {
      uid = it->second;
      userID = strToInt(uid.substr(4, uid.length() - 4));
    }
    sensorID = strToInt(sid.substr(6, sid.length() - 6));
    Sensor *sens = new Sensor(lat, lon, sensorID++, userID);
    lesSensors.push_back(sens);
    getline(sensorFile, sid);
  }
  sensorFile.close();

  ifstream measureFile;
  measureFile.open("data/measurements.csv");
  if (!measureFile)
  {
    cerr << "erreur lors de l'ouverture du fichier measurements";
    return false;
  }

  string date, type, val;
  while (getline(measureFile, date, ';'), !measureFile.eof())
  {
    getline(measureFile, sid, ';');
    getline(measureFile, type, ';');
    getline(measureFile, val, ';');
    sensorID = strToInt(sid.substr(6, sid.length() - 6));
    lesSensors.at(sensorID)->addValue(date, val, type);

    getline(measureFile, date);
  }

  return true;
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
  userFile.open("data/users.csv");
  if (!userFile)
  {
    cout << "erreur lors de l'ouverture du fichier cleaner";
    return false;
  }
  string userID, sensorID, temp;
  while (!userFile.eof())
  {
    getline(userFile, userID, ';');
    getline(userFile, sensorID, ';');
    getline(userFile, temp);
    users.insert(make_pair(sensorID, userID));
  }
  userFile.close();
  return true;
}