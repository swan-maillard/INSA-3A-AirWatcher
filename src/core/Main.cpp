using namespace std;
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../../include/System.h"

int main (int argc, char * argv[]) {
    System sys;
    int choice;
    cout << "Bienvenue sur AirWatcher." << endl;

    do {
        cout << "Que souhaitez-vous faire ?" << endl;
        cout << "\t1 - Obtenir la liste des capteurs" << endl;
        cout << "\t2 - Obtenir les infos d'un capteur" << endl;
        cout << "\t3 - Obtenir statistiques dans un périmètre géographique" << endl;
        cout << "\t4 - Obtenir statistiques à une position géographique" << endl;
        cout << "\t5 - Détecter un capteur disfonctionnel" << endl;
        cout << "\t6 - Obtenir la liste des airCleaners" << endl;
        cout << "\t7 - Obtenir les statistiques sur un airCleaner" << endl;
        cout << "\t8 - Quitter l'application" << endl;
        cin >> choice;

        if (!cin || !cin.good()) {
            choice = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                cout << "-- LISTE DES CAPTEURS --" << endl;
                sys.listSensors();
                break;
            case 2 :
                cout << "-- DETAILS D'UN CAPTEUR --" << endl;
                break;
            case 3 :
                cout << "-- STATISTIQUE DANS UN PERIMETRE --" << endl;
                break;
            case 4 :
                cout << "-- STATISTIQUE A UNE POSITION --" << endl;
                break;
            case 5 :
                cout << "-- SCAN DES CAPTEURS --" << endl;
                break;
            case 6 :
                cout << "-- LISTE DES AIRCLEANER --" << endl;
                break;
            case 7 :
                cout << "-- STATISTIQUE D'UN AIRCLEANER --" << endl;
                break;

            case 8:
                cout << "À bientôt sur AirWatcher !" << endl;
                break;
            default:
                cout << "Veuillez choisir une option valide (nombre compris entre 1 et 2)" << endl;
        }

        cout << endl;

    } while (choice != 8);


    return 0;
}