#include <iostream>

using namespace std;

const int points = 3;

void pfc(/* */unsigned seed){
    srand(seed);

    //pavé qui explique les règles
    cout << "voici les règles du pierre-feuille-ciseaux :" << endl <<
        "la feuille emballe la pierre" << endl <<
            "la pierre casse les ciseaux" << endl <<
            "les ciseaux découpe la feuille" << endl <<
        "marquer " << points << " points avant votre adversaire" << endl;

    //initialisation des variables
    unsigned scoreJoueur = 0;
    unsigned scoreJoueur2 = 0;
    unsigned jouer = 0;
    unsigned jouer2 = 0;

    //la partie commence
    while (scoreJoueur < points & scoreJoueur2 < points){
        cout << "joueur 1 : pierre, feuille ou ciseaux ?(0/1/2)" << endl;
        cin >> jouer;
        cout << "joueur 2 : pierre, feuille ou ciseaux ?(0/1/2)" << endl;
        cin >> jouer2;
        if (jouer == 0){
            if (jouer2 == 0){
                cout << "pierre contre pierre, égalité" << endl;
            }
            else if (jouer2 == 1){
                cout << "pierre contre feuille, le joueur 1 gagne" << endl;
                ++scoreJoueur;}
            else{
                cout << "pierre contre ciseaux, le joueur 2 gagne" << endl;
                ++scoreJoueur2;}
        }
        else if (jouer == 1){
            if (jouer2 == 0){
                cout << "feuille contre pierre, le joueur 2 gagne" << endl;
                ++scoreJoueur2;}
            else if (jouer2 == 1){
                cout << "feuille contre feuille, égalité" << endl;
            }
            else{
                cout << "feuille contre ciseaux, le joueur 1 gagne" << endl;
                ++scoreJoueur;}
        }
        else{
            if(jouer2 == 0){
                cout << "ciseaux contre pierre, le joueur 1 gagne" << endl;
                ++scoreJoueur;}
            else if (jouer2 == 1){
                cout << "ciseaux contre feuille, le joueur 2 gagne" << endl;
                ++scoreJoueur2;}
            else{
                cout << "ciseaux contre ciseaux, égalité" << endl;
            }
        }
        cout << "Joueur 1 - Joueur 2" << endl
             << scoreJoueur << " - " << scoreJoueur2 << endl;
    }

    //détermine le gagnant
    if (scoreJoueur == points){
        cout << "Joueur 1 a gagné" << endl;
    }
    else{
        cout << "Joueur 2 a gagné" << endl;
    }
}

int main()
{
    unsigned round = 0;
    pfc(round);
    return 0;
}
