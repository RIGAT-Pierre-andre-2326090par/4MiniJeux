#include <iostream>

using namespace std;

const int points = 3;

int main()
{

    //pavé qui explique les règles
    cout << "voici les règles du pierre-feuille-ciseaux :" << endl <<
            "la feuille emballe la pierre" << endl <<
            "la pierre casse les ciseaux" << endl <<
            "les ciseaux découpe la feuille" << endl <<
            "marquer " << points << " points avant votre adversaire" << endl;

    //initialisation des variables
    int scoreJoueur = 0;
    int scoreJoueur2 = 0;
    int jouer = 0;
    int jouer2 = 0;

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
                cout << "pierre contre feuille, le joueur gagne" << endl;
                ++scoreJoueur;}
            else{
                cout << "pierre contre ciseaux, le bot gagne" << endl;
                ++scoreJoueur2;}
        }
        else if (jouer == 1){
            if (jouer2 == 0){
                cout << "feuille contre pierre, le bot gagne" << endl;
                ++scoreJoueur2;}
            else if (jouer2 == 1){
                cout << "feuille contre feuille, égalité" << endl;
                }
            else{
                cout << "feuille contre ciseaux, le joueur gagne" << endl;
                ++scoreJoueur;}
       }
       else{
            if(jouer2 == 0){
                cout << "ciseaux contre pierre, le joueur gagne" << endl;
                ++scoreJoueur;}
            else if (jouer2 == 1){
                cout << "ciseaux contre feuille, le bot gagne" << endl;
                ++scoreJoueur2;}
            else{
                cout << "ciseaux contre ciseaux, égalité" << endl;
                }
       }
       cout << "Joueur 1 - Joueur 2" << endl
            << scoreJoueur << " - " << scoreJoueur2 << endl;
    }

    if (scoreJoueur == points){
        cout << "Joueur 1 a gagné" << endl;
    }
    else{
        cout << "Joueur 2 a gagné" << endl;
    }

    return 0;
}
