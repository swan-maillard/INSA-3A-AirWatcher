using namespace std;
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../../include/System.h"
#include <time.h>

int main (int argc, char * argv[]) {
    clock_t t = clock();
    System sys;
    printf("Temps d'execution pour le chargement des fichier : %.3fs\n", ((double) (clock() - t)) / CLOCKS_PER_SEC);
    if (sys.getIsCorrupt()) {
        return 1;
    }
    int choice, user;
    cout << "Bienvenue sur AirWatcher." << endl;

    cout << "Voulez vous :\n\t1 - Consulter des données sans se connecter.\n";
    cout << "\t2 - Vous connecter comme utilisateur\n";
    cout << "\t3 - Vous connecter comme gouvernement\nVotre choix : ";
    cin >> user;
    while (user > 3 || user < 1){
        cout << "Essayez a nouveau : ";
        cin >> user;
    }

    do {
        cout << "Que souhaitez-vous faire ?" << endl;
        cout << "\t1 - Obtenir la liste des capteurs" << endl;
        cout << "\t2 - Obtenir les infos d'un capteur" << endl;
        cout << "\t3 - Obtenir statistiques dans un périmètre géographique" << endl;
        cout << "\t4 - Obtenir statistiques à une position géographique" << endl;
        if (user == 3){
            cout << "\t5 - Détecter un capteur disfonctionnel" << endl;
            cout << "\t6 - Obtenir la liste des airCleaners" << endl;
            cout << "\t7 - Obtenir les statistiques sur un airCleaner" << endl;
        }
        cout << "\t8 - Quitter l'application" << endl;
        cin >> choice;

        if (!cin || !cin.good()) {
            choice = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                cout << "-- LISTE DES CAPTEURS --" << endl << endl;
                sys.listSensors();
                break;
            case 2 :
                cout << "-- DETAILS D'UN CAPTEUR --" << endl << endl;
                sys.oneSensor();
                break;
            case 3 :
                cout << "-- STATISTIQUE DANS UN PERIMETRE --" << endl << endl;
                break;
            case 4 :
                cout << "-- STATISTIQUE A UNE POSITION --" << endl << endl;
                break;
            case 5 :
                if (user == 3){
                    cout << "-- SCAN DES CAPTEURS --" << endl << endl;
                    t = clock();
                    sys.scanSensors();
                    printf("Temps d'execution pour le scan des capteurs : %.3fs\n", ((double) (clock() - t)) / CLOCKS_PER_SEC);
                }
                break;
            case 6 :
                if (user == 3){
                    cout << "-- LISTE DES AIRCLEANER --" << endl << endl;
                    sys.listAirCleaners();
                }
                break;
            case 7 :
                if (user == 3){
                    cout << "-- STATISTIQUE D'UN AIRCLEANER --" << endl << endl;
                    sys.statsAirCleaner();
                }
                break;

            case 8:
                cout << "À bientôt sur AirWatcher !" << endl << endl;
                break;
            default:
                cout << "Veuillez choisir une option valide" << endl << endl;
        }

        cout << endl;

    } while (choice != 8);


    return 0;
}