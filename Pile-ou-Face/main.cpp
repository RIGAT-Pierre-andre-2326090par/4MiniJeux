#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // Inscrition des joueurs pour le pile ou face.
    cout << "Bonjour vous voulez tenter votre chance pour pile ou face" << endl;
    cout << "joueur 1 veuillez entrer votre prénom nom et groupe" << endl;
    // Variable du nom, prénom et équipe du premier joueur.
    string P1;
    string N1;
    string G1;
    cin >> P1;
    cin >> N1;
    cin >> G1;

    // Nous faisons de même avec le second joueur.
    cout << "joueur 2 veuillez entrer votre prénom nom est groupe" << endl;
            string P2;
    string N2;
    string G2;
    cin >> P2;
    cin >> N2;
    cin >> G2;

    
    while (true) {
        // Le premier joueur choisit entre pile ou face.
        cout << "joueur\t"; cout << P1;
        cout<<"\tveuillez choisir 1 pour pile ou 0 pour face " << endl;
        string B;
        int F ;
        cin >> F;
        system("cls");

        // Le joueur deux en fait de même.
        cout << "joueur\t"; cout << P2;
        cout<<"\ttveuiller choisir 1 pour pile ou 0 pour face si vous trouver la meme valeur alor vous aurait gagner sinon vous perdez" << endl;
        int R;
        cin >> R;




        // Si le deuxième joueur a choisi le même côté que le premier, alors il gagne/
        if (F == R) {

            cout << "vous avez gagnez" << endl;
            cout << "voulez vous continuer  o/ n" << endl;
            cin >> B;

            // Les joueurs choisissent ensuite s'il veulent rejouer.
            if (B == "o") {
                cout << "et c'ess repartie"<<endl;
            }
            else {
                cout << "vous me rendez triste";
                break;
            }

        }

        // Si le joueur deux n'a pas réussi à avoir le même symbole, alors il a perdu.
        else (F != R); {

            cout << "vous avez perdu" << endl;
            cout << "voulez vous continuer  o/ n" << endl;
            cin >> B;
            // Les joueurs choisissent ensuite s'il veulent rejouer.
            if (B == "o") {
                cout << "et c'ess repartie"<<endl;
            }
            else {
                cout << "vous me rendez triste";
                break;
            }
        }


    }
    system("cls");
}
