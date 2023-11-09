#include <iostream>
#include <vector>

using namespace std;

const int points = 3;

int main(int seed){

    //pavé qui explique les règles
    cout << "voici les règles du pierre-feuille-ciseaux :" << endl <<
            "la feuille emballe la pierre" << endl <<
            "la pierre casse les ciseaux" << endl <<
            "les ciseaux découpe la feuille" << endl <<
            "marquer " << points << " points avant votre adversaire" << endl;

    vector <vector <int>> seeds = {{1, 1, 2, 1, 2, 0, 0, 2, 2, 2},
                                   {2, 2, 1, 0, 2, 0, 0, 0, 2, 1},
                                   {2, 0, 1, 0, 2, 2, 2, 0, 2, 2},
                                   {2, 0, 1, 2, 1, 0, 2, 1, 1, 0},
                                   {2, 0, 2, 0, 2, 0, 2, 0, 1, 1},
                                   {2, 1, 0, 2, 1, 2, 2, 2, 1, 0},
                                   {1, 1, 2, 2, 0, 1, 2, 2, 0, 1},
                                   {1, 2, 0, 0, 2, 1, 2, 2, 2, 0},
                                   {0, 1, 2, 1, 2, 1, 2, 0, 1, 1},
                                   {2, 0, 2, 0, 2, 0, 2, 2, 2, 1}};

    //initialisation des variables
    seed = 0;
    int seedChoix = 0;
    int choix;
    int scoreBot = 0;
    int scoreJoueur = 0;
    int jouer = 0;

    while (scoreJoueur < points & scoreBot < points){

        cout << "pierre, feuille ou ciseaux ?(0/1/2)" << endl;
        cin >> jouer;
        choix = seeds[seed][seedChoix];
        if (choix == 0){
            if (jouer == 0){
                cout << "pierre contre pierre, égalité" << endl;
                }
            else if (jouer == 1){
                cout << "pierre contre feuille, le joueur gagne" << endl;
                ++scoreJoueur;}
            else{
                cout << "pierre contre ciseaux, le bot gagne" << endl;
                ++scoreBot;}
        }
        else if (choix == 1){
            if (jouer == 0){
                cout << "feuille contre pierre, le bot gagne" << endl;
                ++scoreBot;}
            else if (jouer == 1){
                cout << "feuille contre feuille, égalité" << endl;
                }
            else{
                cout << "feuille contre ciseaux, le joueur gagne" << endl;
                ++scoreJoueur;}
       }
       else{
            if(jouer == 0){
                cout << "ciseaux contre pierre, le joueur gagne" << endl;
                ++scoreJoueur;}
            else if (jouer == 1){
                cout << "ciseaux contre feuille, le bot gagne" << endl;
                ++scoreBot;}
            else{
                cout << "ciseaux contre ciseaux, égalité" << endl;
                }
       }
       cout << "Joueur - bot" << endl
            << scoreJoueur << " - " << scoreBot << endl;
       if (seedChoix == 9){
           seedChoix = 0;
           ++seed;
       }
       else{
           ++seedChoix;
       }
    }

    if (scoreJoueur == points){
        cout << "tu as gagné" << endl;
    }
    else{
        cout << "tu as perdu" << endl;
    }

    return 0;
}
