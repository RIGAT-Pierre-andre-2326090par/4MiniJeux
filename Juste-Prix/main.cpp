// JustePrix.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
using namespace std;
#include <iostream>

void justePrixEtEquipe(const unsigned& seed) {
	cout << "Essayer de trouver le juste prix." << endl;
	cout << "Le but est ausi d'essayer de faire le moins d'essaie." << endl;
	cout << "Bonne chance !" << endl;
	int Equipe1, Equipe2;
	int valeuratrouver;
	srand(seed);
	valeuratrouver = rand() % 50;
	cout << "Qui sont les 2 equipes qui s'affronte ?" << endl;
	cout << "1er equipe :" << endl;
	cin >> Equipe1;
	cout << "2nd equipe :" << endl;
	cin >> Equipe2;
	int cpt1 = 0;
	int cpt2 = 0;
	bool continuer1 = true, continuer2 = true;
	while (continuer1 == true) {
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
			cout << "OUAIS OUAIS OUAIS, Bravo tu a trouver le prix correcte." << endl;
			cpt1 = cpt1 + 1;
			cout << "Votre score d'essaie est de " << cpt1 << endl;
			continuer1 = false;
		}
	}
	while (continuer2 == true){
		int valeurtap;
		cout << "L'equipe a jouer est la " << Equipe2 << endl;
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
			continuer2 = false;
		}
	}

	if (cpt1 < cpt2) {
		cout << "C'est l'equipe " << Equipe1 << " qui a gagner avec " << cpt1 << " essaie comparer a " << cpt2 <<" essaie pour l'equipe " << Equipe2 << endl;
	}
	else if (cpt2 < cpt1) {
		cout << "C'est l'equipe " << Equipe2 << " qui a gagner avec " << cpt2 << " essaie comparer a " << cpt1 <<" esaaie pour l'equipe " << Equipe1 << endl;
	}
}
int main()
{
	justePrixEtEquipe(1);
}
