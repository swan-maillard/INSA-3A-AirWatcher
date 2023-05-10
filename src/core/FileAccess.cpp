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

vector<AirCleaner*> FileAccess::generateCleaners(string providersFN, string cleanerFN){
  cout << "on entre dans le dur\n";
  ifstream providersFile;
  providersFile.open(providersFN);
  if (!providersFile){
    cout << "erreur lors de l'ouverture du fichier providers";
    exit(-1);
  }
  ifstream cleanersFile;
  cleanersFile.open(cleanerFN);
  if (!cleanersFile){
    cout << "erreur lors de l'ouverture du fichier cleaner";
    exit(-1);
  }
  cout << "les fichiers sont cree correctement\n";

  vector<AirCleaner*> lesCleaners(0);
  string provider, cleaner, temp, lat, lon, deb, fin;
  getline(cleanersFile, temp, ';');
  while (getline(providersFile, provider, ';'), !providersFile.eof()){
    getline(providersFile, cleaner, ';');
    getline(cleanersFile, lat, ';');
    getline(cleanersFile, lon, ';');
    AirCleaner* ac = new AirCleaner(lat, lon, provider.at(provider.length()-1) - 48, cleaner.at(7) - 48);
    //cout << *ac << endl;
    lesCleaners.push_back(ac);
    while (temp == cleaner){

      getline(cleanersFile, deb, ';');
      getline(cleanersFile, fin, ';');
      ac->addWorkingHours(deb, fin);
      getline(cleanersFile, temp, ';');
      if (cleaner == temp) {
        getline(cleanersFile, lat, ';');
        getline(cleanersFile, lon, ';');
      }
    }
  }
  cout << "la liste des cleaners : \n";
  for (int i = 0; i < 2 ; i++){
    AirCleaner* c = lesCleaners.at(i);
    cout << *c;
  }
  return lesCleaners;
}

FileAccess::~FileAccess() {
  #ifdef MAP
      cout << "Destruction de <FileAccess>" << endl;
  #endif
}

