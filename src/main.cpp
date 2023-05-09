using namespace std;
#include <iostream>
#include <string>

int main (int argc, char * argv[]) {
    int choice;
    cout << "Bienvenue sur AirWatcher." << endl;

    do {
        cout << "Que souhaitez-vous faire ?" << endl;
        cout << "\t 1 - Scanner les capteurs" << endl;
        cout << "\t 2 - Quitter l'application" << endl;
        cin >> choice;

        if (!cin) {
            choice = -1;
            cin.clear();
            cin.ignore();
        }

        switch (choice) {
            case 1:
                cout << "-- SCAN --" << endl;
                break;
            case 2:
                cout << "À bientôt sur AitWatcher !" << endl;
                break;
            default:
                cout << "Veuillez choisir une option valide (entre 1 à 2)" << endl;
        }

        cout << endl;

    } while (choice != 2);


    return EXIT_SUCCESS;
}