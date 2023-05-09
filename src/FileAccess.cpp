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
#include <string>

//------------------------------------------------------ Include personnel
#include "../include/FileAccess.h"


//----------------------------------------------------------------- PUBLIC

FileAccess::FileAccess() {
  #ifdef MAP
      cout << "Construction de <FileAccess>" << endl;
  #endif


}

void FileAccess::generateCleaners(string providersFN, string cleanerFN){
  ifstream providersFile;
  providersFile.open(providersFN);
  if (!providersFile){
    cout << "erreur lors de l'ouverture du fichier providers";
    return;
  }
  ifstream cleanersFiles;
  cleanersFiles.open(cleanerFN);
  if (!cleanersFiles){
    cout << "erreur lors de l'ouverture du fichier cleaner";
    return;
  }
  string provider, cleaner;
  getline(providersFile, provider, ';');
  getline(providersFile, cleaner, ';');


}

FileAccess::~FileAccess() {
  #ifdef MAP
      cout << "Destruction de <FileAccess>" << endl;
  #endif
}

