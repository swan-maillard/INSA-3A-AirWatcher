using namespace std;
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../../include/AirCleaner.h"
#include "../../include/Sensor.h"
#include "../../include/FileAccess.h"
#include "../../include/Date.h"

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

void testerGenerationSensors() {
    FileAccess fa;
    vector<Sensor*> lesSensors(0);
    fa.generateSensors(lesSensors);
    vector<Sensor*>::iterator it;
    for (it = lesSensors.begin() ; it != lesSensors.end(); ++it){
        cout << **it << endl;
    }
    cout << endl;
}

void testerDate() {
    Date d1("2000:12:11 11:03:45");
    Date d2("2000:12:11 11:03:45");
    Date d3("2003:12:11 11:03:45");
    Date d4("2000:12:11 11:03:44");
    cout << (d1 == d2) << " " << (d1 < d3) << " " << (d1 < d4) << endl;
}

int main (int argc, char * argv[]) {
    //testerGenerationCleaner();
    //testerGenerationSensors();
    //testerDate();
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
                cout << "À bientôt sur AirWatcher !" << endl;
                break;
            default:
                cout << "Veuillez choisir une option valide (nombre compris entre 1 et 2)" << endl;
        }

        cout << endl;

    } while (choice != 2);


    return EXIT_SUCCESS;
}