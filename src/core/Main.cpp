using namespace std;
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../../include/AirCleaner.h"
#include "../../include/FileAccess.h"

void testerGenerationCleaner() {
    FileAccess fa;
    vector<AirCleaner*> lesCleaners(0);
    fa.generateCleaners(lesCleaners);
    cout << "Liste des cleaners : \n";
    vector<AirCleaner*>::iterator it;
    for (it = lesCleaners.begin() ; it != lesCleaners.end(); ++it){
        cout << **it << endl;
    }
    cout << endl;
}

int main (int argc, char * argv[]) {
    testerGenerationCleaner();
    int choice;
    cout << "Bienvenue sur AirWatcher." << endl;

    do {
        cout << "Que souhaitez-vous faire ?" << endl;
        cout << "\t 1 - Scanner les capteurs" << endl;
        cout << "\t 2 - Quitter l'application" << endl;
        cin >> choice;

        if (!cin || !cin.good()) {
            choice = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                cout << "-- SCAN --" << endl;
                break;
            case 2:
                cout << "À bientôt sur AitWatcher !" << endl;
                break;
            default:
                cout << "Veuillez choisir une option valide (nombre compris entre 1 et 2)" << endl;
        }

        cout << endl;

    } while (choice != 2);


    return EXIT_SUCCESS;
}