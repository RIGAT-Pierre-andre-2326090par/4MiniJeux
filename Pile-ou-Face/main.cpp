#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

    cout << "Bonjour vous voulez tenter votre chance pour pile ou face" << endl;
    cout << "joueur 1 veuillez entrer votre prénom nom est groupe" << endl;
            string P1;
    string N1;
    string G1;
    cin >> P1;
    cin >> N1;
    cin >> G1;
    cout << "joueur 2 veuillez entrer votre prénom nom est groupe" << endl;
            string P2;
    string N2;
    string G2;
    cin >> P2;
    cin >> N2;
    cin >> G2;

    while (true) {


        cout << "joueur\t"; cout << P1;
        cout<<"\tveuiller choisir 1 pour pile ou 0 pour face " << endl;
        string B;
        int F ;
        cin >> F;
        system("cls");
        cout << "joueur\t"; cout << P2;
        cout<<"\ttveuiller choisir 1 pour pile ou 0 pour face si vous trouver la meme valeur alor vous aurait gagner sinon vous perdez" << endl;
        int R;
        cin >> R;





        if (F == R) {

            cout << "vous avez gagnez" << endl;
            cout << "voulez vous continuer  o/ n" << endl;
            cin >> B;
            if (B == "o") {
                cout << "est ses repartie"<<endl;

            }
            else {
                cout << "vous me rrendez triste";
                break;
            }

        }
        else (F != R); {

            cout << "vous avez perdu" << endl;
            cout << "voulez vous continuer  o/ n" << endl;
            cin >> B;
            if (B == "o") {
                cout << "est ses repartie" << endl;

            }
            else {
                cout << "vous me rrendez triste";
                break;
            }
        }


    }
    system("cls");
}
