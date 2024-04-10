#include "Loterie.h"

using namespace std;

void lottobelge();
void euromillions();
void menu();

int main() {
    srand(time(nullptr));
    menu();
    return 0;
}
void menu() {
    int choix;
    cout << "Veuillez choisir une option :" << endl;
    cout << "\n1. Loterie Nationale Belge" << endl;
    cout << "2. Euromillions" << endl;
    cout << "3. Quitter" << endl;
    cin >> choix;

    switch (choix)
    {
    case 1:
        lottobelge();
        break;
    case 2:
        euromillions();
        break;
    case 3:
        return;
    default:
        cout << "\nOption invalide" << endl;

    }
}
void lottobelge() {
    string choix;
    int chiffres[6];
    bool doublons;

    do {
        // Génération des chiffres aléatoires
        for (int i = 0; i < 6; i++) {
            chiffres[i] = (rand() % 45) + 1;
        }

        // Vérification des doublons
        doublons = false;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 6; j++) {
                if (chiffres[i] == chiffres[j]) {
                    doublons = true;
                    break;
                }
            }
            if (doublons) break;
        }
    } while (doublons);

    // Affichage des chiffres
    cout << "\nChiffres a cocher : ";
    for (int i = 0; i < 6; i++) {
        cout << chiffres[i];
        if (i < 5) {
            cout << " - ";
        }
    }
    cout << endl;

    cout << "\nVoulez-vous une autre serie ? (o/n)" << endl;
    cin >> choix;

    if (choix == "o")
        lottobelge();
    else
        menu();
}
void euromillions()
{
    string choix;
    int chiffres[5];
    int etoiles[2];
    bool doublons;

    // Génération des chiffres
    do {
        for (int i = 0; i < 5; i++) {
            chiffres[i] = (rand() % 49) + 1;
        }

        // Vérification des doublons pour les chiffres
        doublons = false;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (chiffres[i] == chiffres[j]) {
                    doublons = true;
                    break;
                }
            }
            if (doublons) break;
        }
    } while (doublons);

    // Génération des étoiles
    do {
        for (int i = 0; i < 2; i++) {
            etoiles[i] = (rand() % 12) + 1;
        }

        // Vérification des doublons pour les étoiles
        doublons = false;
        for (int i = 0; i < 1; i++) {
            for (int j = i + 1; j < 2; j++) {
                if (etoiles[i] == etoiles[j]) {
                    doublons = true;
                    break;
                }
            }
            if (doublons) break;
        }
    } while (doublons);

    // Affichage des résultats
    cout << "\nChiffres a cocher : ";
    for (int i = 0; i < 5; i++) {
        cout << chiffres[i];
        if (i < 4) { cout << " - "; }
    }
    cout << " ( ";
    for (int i = 0; i < 2; i++) {
        cout << etoiles[i];
        if (i < 1) { cout << " - "; }
    }
    cout << " ) " << endl;

    cout << "\nVoulez-vous une autre serie ? (o/n)" << endl;
    cin >> choix;

    if (choix == "o")
        euromillions();
    else
        menu();
}
