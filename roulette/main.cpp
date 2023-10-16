#include <iostream>
#include <experimental/random>
using namespace std;

unsigned rouletteCasino(unsigned jetons, unsigned const & seed)
{
// Explication du jeu

cout << "Bonjour dans cette roulette, un jeu trés simple pouvant vous faire devenir riche de jetons !! Ou tout perdre... Alors jouez avec parcimonie sinon c'est la pauvreté" << endl
     << "Voici les règles du jeux. Vous disposez de vos jetons de départ consituant votre argent. Votre but partir avec le jackpot. Durant 10 essaie essayer de gagner le plus d'argent !" << endl
     << "Maintenant comment gagner ? Il suffit de parier un jetons soit sur un nombre, allant de 0 à 36, si cela tombe juste votre mise est multiplié par 36. Vous pouvez aussi parier sur la parité d'un nombre, si cela tombe juste votre mise qui sera multiplié par 2 !" << endl
     << "Bon courage"
     << endl
     << "Vous avez : " << jetons << " jetons"
     << endl
     << endl;

// Déclarer les variables nécessaire au choix de l'utilisateur et de son jeu
unsigned essaie = 0;
unsigned long mise;
int nombreRoulette;
int chiffre;
string parite;
string choixStyleJeu;
string continuer;

// Boucle de jeu
srand(seed);
while (jetons >= 1 && essaie < 3)
{
    // Nombre alétoire correspondant a la case sur laquelle la bille se trouve
    nombreRoulette = rand()%36;
    cout << "Voulez vous parier sur la parité ou un chiffre ? (parite/chiffre) " << endl;
    cin >> choixStyleJeu;
    // Si le joueur veut jouer sur la parite du nombre
    if (choixStyleJeu == "parite")
    {
        // Parier sa mise et jouer
        do
        {
            cout << "Combien de jetons voulez vous misez ? " << endl;
            cin >> mise;
        }
        while (jetons < mise);
        jetons -= mise;
        ++ essaie;
        do
        {
            cout << "paire ou impaire ? " << endl;
            cin >> parite;
        }
        while (parite != "paire" and parite != "impaire");
        if ((nombreRoulette%2 == 0 and parite == "paire") or (nombreRoulette%2 == 1 and parite == "impaire"))
        {
            jetons += mise*2;
            cout << "Victoire ! Vous avez maintenant " << jetons << endl;
            ++ essaie;
        }
        else
        {
            cout << "Défaite ! Vous avez maintenant " << jetons << endl;
            ++ essaie;
        }

    }

    // Si le joueur veut parier sur un chiffre
    if (choixStyleJeu == "chiffre")
    {
        do
        {
            cout << "Combien de jetons voulez vous misez ? " << endl;
            cin >> mise;
        }
        while (jetons < mise);
        jetons -= mise;
        cout << "Quelle chiffre ? " << endl;
        cin >> chiffre;
        if (nombreRoulette == chiffre)
        {
            jetons += mise*36;
            ++ essaie;
            cout << "Victoire ! Vous avez maintenant " << jetons << endl;
        }
        else
            cout << "Défaite ! Vous avez maintenant " << jetons << endl;
    }
    cout << essaie <<endl;

}

// Affichage de fin et on renvoie le score
    cout << "Votre partie est terminé ! Que le sort puisse vous être favorable" << endl;
    return jetons;
}



int main()
{
    if (rouletteCasino(1000,1) > rouletteCasino(1000,1))
        cout << "Victoire joueur 1" << endl;
    else
        cout << "Victoire joueur 2" << endl;
}
