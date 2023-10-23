#include <iostream>
using namespace std;


void justePrixEtEquipe() {
    cout << "Essayer de trouver le juste prix." << endl;
    cout << "Le but est ausi d'essayer de faire le moins d'essaie." << endl;
    cout << "Bonne chance !" << endl;
    string Equipe1, Equipe2;
    int valeuratrouver = 0;
    cout << "Qui sont les 2 equipes qui s'affronte ?" << endl;
    cout << "1er equipe :" << endl;
    cin >> Equipe1;
    cout << "2nd equipe :" << endl;
    cin >> Equipe2;
    string Equipe0;
    cout << " Qui commence ?" << endl;
    cin >> Equipe0;
    int cpt1 = 0;
    int cpt2 = 0;
    bool continuer = true;
    while (continuer == true) {
        if (Equipe0 == Equipe1) {
            cout << Equipe2 << " veuillez taper le nombre a trouver pour l'equipe adverse" << endl;
            cout << "Entre 0 et 10000 svp" << endl;
            cin >> valeuratrouver;
            cout << "A vous de jouer " << Equipe1 << endl;
            int valeurtap;
            cout << "Taper le chiffre :" << endl;
            cin >> valeurtap;
            if (valeuratrouver < valeurtap) {
                cout << "C'est moins !" << endl;
                valeurtap = 0;
                cpt1 = cpt1 + 1;
            }
            else if (valeuratrouver > valeurtap) {
                cout << "C'est plus !" << endl;
                valeurtap = 0;
                cpt1 = cpt1 + 1;
            }
            else if (valeuratrouver == valeurtap) {
                cpt1 = cpt1 + 1;
                cout << "OUAIS OUAIS OUAIS, Bravo tu a trouver le prix correcte." << endl;
                cout << "Votre score d'essaie est de " << cpt1 << endl;
                cout << "Passer au tour de l'equipe suivante ? y/n" << endl;
                string equipesuivante;
                cin >> equipesuivante;
                if (equipesuivante == "n")
                {
                    continuer = false;
                }
            }
        }
        if (Equipe0 == Equipe2) {
            cout << Equipe1 << " veuillez taper le nombre a trouver pour l'equipe adverse" << endl;
            cout << "Entre 0 et 10000 svp" << endl;
            cin >> valeuratrouver;
            cout << "A vous de jouer " << Equipe2 << endl;
            int valeurtap;
            cout << "Taper le chiffre :" << endl;
            cin >> valeurtap;
            if (valeuratrouver < valeurtap) {
                cout << "C'est moins !" << endl;
                valeurtap = 0;
                cpt2 = cpt2 + 1;
            }
            else if (valeuratrouver > valeurtap) {
                cout << "C'est plus !" << endl;
                valeurtap = 0;
                cpt2 = cpt2 + 1;
            }
            else if (valeuratrouver == valeurtap) {
                cpt2 = cpt2 + 1;
                cout << "OUAIS OUAIS OUAIS, Bravo tu a trouver le prix correcte." << endl;
                cout << "Votre score d'essaie est de " << cpt2 << endl;
                cout << "Passer au tour de l'equipe suivante ? y/n" << endl;
                string equipesuivante;
                cin >> equipesuivante;
                if (equipesuivante == "n")
                {
                    continuer = false;
                }
            }
        }
    }
    if (cpt1 < cpt2) {
        cout << "C'est l'equipe " << Equipe2 << "qui a gagner avec " << cpt2 << "essaie !" << endl;
    }
    else if (cpt2 < cpt1) {
        cout << "C'est l'equipe " << Equipe1 << "qui a gagner avec " << cpt1 << "essaie !" << endl;
    }
}
