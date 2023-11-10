#include <vector>
#include <iostream>
using namespace std;


void afficheGrille(const vector<vector<string>>& tab) {
    // Afficher la grille de jeu.
    cout << "-------" << endl;
    for (unsigned i = 0; i < 3; i++) {
        cout << "|";
        for (unsigned j = 0; j < 3; j++) {
            if (tab[i][j] == "O" || tab[i][j] == "X") {
                cout << tab[i][j] << "|";
            }
            else {
                cout << " |";
            }
        }
        cout << endl;
        cout << "-------" << endl;
    }
}


vector<vector<string>> placementPion(vector<vector<string>>& tab, const string pion) {
    unsigned i, j;

    cout << "Saisir les coordonnees de votre pion entre 0 et 2 :" << endl;
    cout << "Position x (ordonnees) : ";
    cin >> i;
    cout << "Position y (abscisses) : ";
    cin >> j;
    // Saisir les coordonnées de notre pion.

    while (true) {
        if (1 <= i <= 3 && 1 <= j <= 3) break;
        cout << "|!| Coordonnees incorrectes. Veuillez saisir de nouveau une reponse :"
             << endl;
        cout << "Position x : ";
        cin >> i;
        cout << "Position y : ";
        cin >> j;
    }
    // Vérifier si les coordonnées sont bonnes.

    while (true) {
        if (tab[i][j] == "") {
            tab[i][j] = pion;
            break;
        }
        else {
            cout << "|!| Coordonnees incorrectes. Veuillez saisir de nouveau une reponse :"
                 << endl;
            cout << "Position x : ";
            cin >> i;
            cout << "Position y : ";
            cin >> j;
        }
    }
    // Vérifier si l'emplacement est libre.
    // Si libre : le pion est placé.

    return tab;
}


bool rechercheLignePleine(const vector<vector<string>>& tab, const string& pion) {
    bool condition = false;
    if (tab[0][0] == pion && tab[0][1] == pion && tab[0][2] == pion) {
        condition = true;
    }
    else if (tab[1][0] == pion && tab[1][1] == pion && tab[1][2] == pion) {
        condition = true;
    }
    else if (tab[2][0] == pion && tab[2][1] == pion && tab[2][2] == pion) {
        condition = true;
    }
    else if (tab[0][0] == pion && tab[1][0] == pion && tab[2][0] == pion) {
        condition = true;
    }
    else if (tab[0][1] == pion && tab[1][1] == pion && tab[2][1] == pion) {
        condition = true;
    }
    else if (tab[0][2] == pion && tab[1][2] == pion && tab[2][2] == pion) {
        condition = true;
    }
    else if (tab[0][0] == pion && tab[1][1] == pion && tab[2][2] == pion) {
        condition = true;
    }
    else if (tab[0][2] == pion && tab[1][1] == pion && tab[2][0] == pion) {
        condition = true;
    }
    // Pour chaque ligne pouvant être complétée par le même motif, on teste
    // si les pions du joueur forment une ligne.

    return condition;
}


int main() {    // Programme principale du jeu.
    struct joueurUn {
        string nom;
        string prenom;
        unsigned numEquipe;
        string pion;
    };  // struct du Premier Joueur.

    joueurUn j1; // Nom de variable de la struct.

    struct joueurDeux {
        string nom;
        string prenom;
        unsigned numEquipe;
        string pion;
    };  // struct du Deuxième Joueur.

    joueurDeux j2; // Nom de variable de la struct.

    cout << "Veuillez renseignez les informations du joueur 1 :" << endl;
    cout << "Votre nom : ";
    cin >> j1.nom;
    cout << "Votre prenom : ";
    cin >> j1.prenom;
    cout << "Votre numero d'equipe : ";
    cin >> j1.numEquipe;
    j1.pion = "O";
    // Informations du premier joueur.

    cout << "Veuillez renseignez les informations du joueur 2 :" << endl;
    cout << "Votre nom : ";
    cin >> j2.nom;
    cout << "Votre prenom : ";
    cin >> j2.prenom;
    cout << "Votre numero d'equipe : ";
    cin >> j2.numEquipe;
    j2.pion = "X";
    // Informations du second joueur

    vector<vector<string>> tabMorpion;
    for (unsigned i = 0; i < 3; i++) {
        tabMorpion.push_back(vector<string>(3));
    }
    // Création d'une grille de morpion de 3 par 3.

    unsigned i = 0;
    bool condition = false;
    while (i <= 9) {


        cout << "Au tour de " << j1.prenom << " : "
             << endl;
        tabMorpion = placementPion(tabMorpion, j1.pion);
        condition = rechercheLignePleine(tabMorpion, j1.pion);
        afficheGrille(tabMorpion);
        if (condition == true) {
            cout << j1.prenom << " " << j1.nom << " de l'equipe "
                 << j1.numEquipe << " a gagne la partie ! " << endl;
            break;
        }
        i++;

        if (i == 9) {
            cout << "Partie finie, egalite." << endl;
            break;
        }
        // Si les neufs tours sont joués, alors l'égalité est déclarée
        // nous sortons de la boucle.

        cout << "Au tour de " << j2.prenom << " : "
             << endl;
        tabMorpion = placementPion(tabMorpion, j2.pion);
        condition = rechercheLignePleine(tabMorpion, j1.pion);
        afficheGrille(tabMorpion);
        if (condition == true) {
            cout << j2.prenom << " " << j2.nom << " de l'equipe "
                 << j2.numEquipe << " a gagne la partie ! " << endl;
            break;
        }
        i++;
    }
}
