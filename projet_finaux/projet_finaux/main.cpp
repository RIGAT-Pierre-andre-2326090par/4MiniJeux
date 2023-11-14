#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1 juste prix

bool justePrix(unsigned seed) {
    srand(seed);
    //cout << "Essayer de trouver le juste prix." << endl;
    //cout << "Le but est ausi d'essayer de faire le moins d'essaie." << endl;
    //cout << "Bonne chance !" << endl;
    //string Equipe1, Equipe2;
    int valeuratrouver = 0 + rand()%1001;
    //string Equipe0 = Equipe1;
    int cpt1 = 0;
    int cpt2 = 0;
    bool continuer = true;
    while (continuer == true) {
        //cout << Equipe2 << " veuillez taper le nombre a trouver pour l'equipe adverse" << endl;
        //cout << "Entre 0 et 10000 svp" << endl;
        //cin >> valeuratrouver;
        //cout << "A vous de jouer " << Equipe1 << endl;
        int valeurtap;
        int valeurtap2;
        //cout << "Taper le chiffre :" << endl;
        valeurtap = 0 + rand()%1001;
        valeurtap2 = 0 + rand()%1001;
        if (valeuratrouver < valeurtap) {
            //cout << "C'est moins !" << endl;
            cpt1 = cpt1 + 1;
        }
        else if (valeuratrouver > valeurtap) {
            //cout << "C'est plus !" << endl;
            cpt1 = cpt1 + 1;
        }
        else if (valeuratrouver == valeurtap) {
            cpt1 = cpt1 + 1;
            continuer = false;
        }
        if (valeuratrouver < valeurtap2) {
            //cout << "C'est moins !" << endl;
            cpt2 = cpt2 + 1;
        }
        else if (valeuratrouver > valeurtap2) {
            //cout << "C'est plus !" << endl;
            cpt2 = cpt2 + 1;
        }
        else if (valeuratrouver == valeurtap2) {
            cpt2 = cpt2 + 1;
            continuer = false;
        }
    }

    if (cpt1 < cpt2) {
        //cout << "C'est l'equipe " << Equipe2 << "qui a gagner avec " << cpt2 << "essaie !" << endl;
        return false;
    }
    else{
        return true;
    }
}

// 2 morpion et ses fonctions

/*void afficheGrille(const vector<vector<string>>& tab) {
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
}*/

vector<vector<string>> placementPion(vector<vector<string>>& tab, const string pion) {
    unsigned i, j;

    //cout << "Saisir les coordonnees de votre pion entre 0 et 2 :" << endl;
    //cout << "Position x (ordonnees) : ";
    //cin >> i;
    i = 0 + rand()%3;
    //cout << "Position y (abscisses) : ";
    //cin >> j;
    j = 0 + rand()%3;

    // Saisir les coordonnées de notre pion.

    while (true) {
        if (((1 <= i) && (i <= 3)) & ((1 <= j) && (j <= 3))) break;
        /*cout << "|!| Coordonnees incorrectes. Veuillez saisir de nouveau une reponse :"
             << endl;
        cout << "Position x : ";*/
        //cin >> i;
        i = 0 + rand()%3;
        //cout << "Position y : ";
        //cin >> j;
        j = 0 + rand()%3;
    }
    // Vérifier si les coordonnées sont bonnes.

    while (true) {
        if (tab[i][j] == "") {
            tab[i][j] = pion;
            break;
        }
        else {
            /*cout << "|!| Coordonnees incorrectes. Veuillez saisir de nouveau une reponse :"
                 << endl;
            cout << "Position x : ";*/
            //cin >> i;
            i = 0 + rand()%3;
            //cout << "Position y : ";
            //cin >> j;
            j = 0 + rand()%3;
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


bool morpion(unsigned seed) {    // Programme principale du jeu.
    srand(seed);
    /*struct joueurUn {
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

    joueurDeux j2; // Nom de variable de la struct.*/

    string j1pion;
    string j2pion;

    /*cout << "Veuillez renseignez les informations du joueur 1 :" << endl;
    cout << "Votre nom : ";
    cin >> j1.nom;
    cout << "Votre prenom : ";
    cin >> j1.prenom;
    cout << "Votre numero d'equipe : ";
    cin >> j1.numEquipe;*/
    j1pion = "O";
    // Informations du premier joueur.

    /*cout << "Veuillez renseignez les informations du joueur 2 :" << endl;
    cout << "Votre nom : ";
    cin >> j2.nom;
    cout << "Votre prenom : ";
    cin >> j2.prenom;
    cout << "Votre numero d'equipe : ";
    cin >> j2.numEquipe;*/
    j2pion = "X";
    // Informations du second joueur

    vector<vector<string>> tabMorpion;
    for (unsigned i = 0; i < 3; i++) {
        tabMorpion.push_back(vector<string>(3));
    }
    // Création d'une grille de morpion de 3 par 3.

    unsigned i = 0;
    bool condition1 = false;
    bool condition2 = false;
    while (i <= 9) {
        /*cout << "Au tour de " << j1.prenom << " : "
             << endl;*/
        tabMorpion = placementPion(tabMorpion, j1pion);
        condition1 = rechercheLignePleine(tabMorpion, j1pion);
        //afficheGrille(tabMorpion);
        if (condition1 == true) {
            /*cout << j1.prenom << " " << j1.nom << " de l'equipe "
                 << j1.numEquipe << " a gagne la partie ! " << endl;*/

            break;
        }
        i++;

        if (i == 9) {
            /*cout << "Partie finie, egalite." << endl;*/
            break;
        }
        // Si les neufs tours sont joués, alors l'égalité est déclarée
        // nous sortons de la boucle.

        /*cout << "Au tour de " << j2.prenom << " : "
             << endl;*/
        tabMorpion = placementPion(tabMorpion, j2pion);
        condition2 = rechercheLignePleine(tabMorpion, j2pion);
        //afficheGrille(tabMorpion);
        if (condition2 == true) {
            /*cout << j2.prenom << " " << j2.nom << " de l'equipe "
                 << j2.numEquipe << " a gagne la partie ! " << endl;*/
            return false;
            break;
        }
        i++;
    }
    if (condition1) return true;
    if (condition2) return false;
    else return true;
}

// 3 pile ou face

bool pileOuFace(unsigned seed){
    srand(seed);
    /*cout << "Bonjour vous voulez tenter votre chance pour pile ou face" << endl;
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
    cin >> G2;*/
    //cout << "joueur\t"; cout << P1;
    //cout<<"\tveuiller choisir 1 pour pile ou 0 pour face " << endl;
    string B;
    int F ;
    F = 0 + rand()%2;
    //cout << "joueur\t"; cout << P2;
    //cout<<"\ttveuiller choisir 1 pour pile ou 0 pour face si vous trouver la meme valeur alor vous aurait gagner sinon vous perdez" << endl;
    int R;
    R = 0 + rand()%2;
    if (F == R) {
        //cout << "vous avez gagnez" << endl;
        return true;
    }
    else{
        //cout << "vous avez perdu" << endl;
        return false;
    }
}

// 4 pierre feuille ciseaux

bool pfc(unsigned seed){
    srand(seed);
    const int points = 3;

    //pavé qui explique les règles
    /*cout << "voici les règles du pierre-feuille-ciseaux :" << endl <<
        "la feuille emballe la pierre" << endl <<
            "la pierre casse les ciseaux" << endl <<
            "les ciseaux découpe la feuille" << endl <<
        "marquer " << points << " points avant votre adversaire" << endl;*/

    //initialisation des variables
    int scoreJoueur = 0;
    int scoreJoueur2 = 0;
    int jouer = 0;
    int jouer2 = 0;

    //la partie commence
    while ((scoreJoueur < points) & (scoreJoueur2 < points)){
        //cout << "joueur 1 : pierre, feuille ou ciseaux ?(0/1/2)" << endl;
        //cin >> jouer;
        jouer =  0 + rand()%3;
        //cout << "joueur 2 : pierre, feuille ou ciseaux ?(0/1/2)" << endl;
        //cin >> jouer2;
        jouer2 = 0 + rand()%3;
        if (jouer == 0){
            if (jouer2 == 0){
                //cout << "pierre contre pierre, égalité" << endl;
            }
            else if (jouer2 == 1){
                //cout << "pierre contre feuille, le joueur gagne" << endl;
                ++scoreJoueur;}
            else{
                //cout << "pierre contre ciseaux, le bot gagne" << endl;
                ++scoreJoueur2;}
        }
        else if (jouer == 1){
            if (jouer2 == 0){
                //cout << "feuille contre pierre, le bot gagne" << endl;
                ++scoreJoueur2;}
            else if (jouer2 == 1){
                //cout << "feuille contre feuille, égalité" << endl;
            }
            else{
                //cout << "feuille contre ciseaux, le joueur gagne" << endl;
                ++scoreJoueur;}
        }
        else{
            if(jouer2 == 0){
                //cout << "ciseaux contre pierre, le joueur gagne" << endl;
                ++scoreJoueur;}
            else if (jouer2 == 1){
                //cout << "ciseaux contre feuille, le bot gagne" << endl;
                ++scoreJoueur2;}
            else{
                //cout << "ciseaux contre ciseaux, égalité" << endl;
            }
        }
        /*cout << "Joueur 1 - Joueur 2" << endl
             << scoreJoueur << " - " << scoreJoueur2 << endl;*/
    }

    //détermine le gagnant
    if (scoreJoueur == points){
        //cout << "Joueur 1 a gagné" << endl;
        return true;
    }
    else{
        //cout << "Joueur 2 a gagné" << endl;
        return false;
    }
}

// 5 roulette

unsigned rouletteCasino(unsigned jetons, unsigned const & seed)
{
    // Explication du jeu

    /*cout << "Bonjour dans cette roulette, un jeu trés simple pouvant vous faire devenir riche de jetons !! Ou tout perdre... Alors jouez avec parcimonie sinon c'est la pauvreté" << endl
         << "Voici les règles du jeux. Vous disposez de vos jetons de départ consituant votre argent. Votre but partir avec le jackpot. Durant 10 essaie essayer de gagner le plus d'argent !" << endl
         << "Maintenant comment gagner ? Il suffit de parier un jetons soit sur un nombre, allant de 0 à 36, si cela tombe juste votre mise est multiplié par 36. Vous pouvez aussi parier sur la parité d'un nombre, si cela tombe juste votre mise qui sera multiplié par 2 !" << endl
         << "Bon courage"
         << endl
         << "Vous avez : " << jetons << " jetons"
         << endl
         << endl;*/

    // Déclarer les variables nécessaire au choix de l'utilisateur et de son jeu
    unsigned essaie = 0;
    unsigned long mise;
    int nombreRoulette;
    int chiffre;
    int parite;
    int choixStyleJeu;
    //int continuer;

    // Boucle de jeu
    srand(seed);
    while (jetons >= 1 && essaie <= 1)
    {
        // Nombre alétoire correspondant a la case sur laquelle la bille se trouve
        nombreRoulette = rand()%36;
        //cout << "Voulez vous parier sur la parité ou un chiffre ? (parite/chiffre) " << endl;
        //cin >> choixStyleJeu;
        choixStyleJeu = 0 + rand()%2;
        // Si le joueur veut jouer sur la parite du nombre
        if (choixStyleJeu == 0)
        {
            // Parier sa mise et jouer
            do
            {
                //cout << "Combien de jetons voulez vous misez ? " << endl;
                //cin >> mise;
                mise = 1 + rand()%(jetons + 1);
            }
            while (jetons < mise);
            jetons -= mise;
            ++ essaie;
            do
            {
                //cout << "paire ou impaire ? " << endl;
                //cin >> parite;
                parite = 0 + rand()%2;
            }
            while (parite != 0 and parite != 1);
            if ((nombreRoulette%2 == 0 and parite == 0) or (nombreRoulette%2 == 1 and parite == 1))
            {
                jetons += mise*2;
                //cout << "Victoire ! Vous avez maintenant " << jetons << endl;
                ++ essaie;
            }
            else
            {
                //cout << "Défaite ! Vous avez maintenant " << jetons << endl;
                    ++ essaie;
            }

        }

        // Si le joueur veut parier sur un chiffre
        if (choixStyleJeu == 1)
        {
            do
            {
                //cout << "Combien de jetons voulez vous misez ? " << endl;
                //cin >> mise;
                mise = 1 + rand()%(jetons + 1);
            }
            while (jetons < mise);
            jetons -= mise;
            //cout << "Quelle chiffre ? " << endl;
            //cin >> chiffre;
            chiffre = 1 + rand()%37;
            if (nombreRoulette == chiffre)
            {
                jetons += mise*36;
                ++ essaie;
                //cout << "Victoire ! Vous avez maintenant " << jetons << endl;
            }
            else
            {
                //cout << "Défaite ! Vous avez maintenant " << jetons << endl;
                ++ essaie;
            }
        }
    }

    // Affichage de fin et on renvoie le score
    //cout << "Votre partie est terminé ! Que le sort puisse vous être favorable" << endl;
        return jetons;
}

bool affrontementRoulette(/*unsigned const & equipe1, unsigned const & equipe2,*/ unsigned const & seed)
{
    unsigned part1 = rouletteCasino(1000,seed);
    unsigned part2 = rouletteCasino(1000,seed + 1);
    if (part1 > part2){
        //cout << "Victoire de l'equipe " << equipe1 << endl;
        return true;
    }
    else{
        //cout << "Victoire de l'equipe " << equipe2 << endl;
        return false;
    }
}

// 6 fonction pour avoir les équipes rangés

struct joueur{
    string nom;
    string prenom;
    unsigned numEquipe;
};

string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

void donneEquipe(vector <vector <joueur>> & team){
    for (unsigned i (0); i < 114; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        unsigned numEquipe (litUnEntier());
        //cout << nom << endl << prenom << endl << numEquipe << endl;
        team[numEquipe-1].push_back(joueur {nom, prenom, numEquipe});
    }
}

void afficheTeam(vector <vector <joueur>> team){
    for (unsigned i = 0 ; i < team.size() ; ++i){
        cout << "équipe n°" << team[i][0].numEquipe << endl;
            for (unsigned j = 0 ; j < team[i].size() ; ++j){
            cout << "\t- " << team[i][j].nom << " " << team[i][j].prenom << endl << endl;
        }
    }
}

void afficheNumTeam(vector <vector <joueur>> team){
    cout << "{";
    for (unsigned i = 0 ; i < team.size() ; ++i){
        cout << team[i][0].numEquipe;
        if (i < team.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

// 7 les tournois et les fonctions qui vont avec

bool leJ1AGagne(unsigned jeu, unsigned seed){
    bool a;
    switch(jeu){
    case(1): {
        a = justePrix(seed);
        break;
    }
    case(2): {
        a = morpion(seed);
        break;
    }
    case(3): {
        a = pileOuFace(seed);
        break;
    }
    case(4): {
        a = pfc(seed);
        break;
    }
    case(5): {
        a = affrontementRoulette(seed);
        break;
    }
    default: {
        a = (0 + rand()%2 == 0);
        break;
    }
    }
    return a;
}


void afficheVector(vector <int> vec){
    cout << "{";
    for (size_t i = 0 ; i < vec.size() ; ++i){
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

void triScoreTeam(vector <vector <joueur>> & team, vector <int> & score){
    for (unsigned j = 0 ; j < team.size() ; ++j){
        for (unsigned i = 1 ; i < team.size() ; ++i){
            if (score[i - 1] < score[i]){
                swap(score[i],score[i - 1]);
                swap(team[i],team[i - 1]);
            }
        }
    }
    //afficheNumTeam(team);
    //afficheVector(score);
}

void defScore(vector <vector <joueur>> & team, vector <int> & score){
    unsigned nbTeam = team.size();
    for (unsigned i = 0 ; i < nbTeam ; ++i){
        score.push_back(0);
    }
}

void tournoiSansLooserBracket(string typeTournoi, vector <vector <joueur>> & team, unsigned jeu, unsigned seed){
    unsigned swith = 0;
    unsigned round = 1;
    unsigned combat = 1;
    while (team.size() > 1){
        //cout << "round " << round << ", " << swith << endl;
        for (size_t i = 0 ; i < team.size() - 1; ++i){
            //cout << "combat " << combat
                 //<< ": l'équipe n°" << team[i + swith][0].numEquipe << " VS l'équipe n°" << team[i + swith + 1][0].numEquipe << endl;
            if (leJ1AGagne(jeu, combat + seed)){
                //cout << "l'équipe n°" << team[i + swith][0].numEquipe << " gagne" << endl;
                team.erase(team.begin() + i + 1 + swith);
            }
            else{
                //cout << "l'équipe n°" << team[i + swith + 1][0].numEquipe << " gagne" << endl;
                team.erase(team.begin() + i + swith);
            }
            ++combat;
            //afficheNumTeam(team);
        }
        ++round;
        if (team.size()%2 == 0) swith = 0 ;
        else swith = (swith + 1)%2;
    }
    //cout << "le vainqueur " << typeTournoi << " est l'équipe n°" << team[0][0].numEquipe << endl;
    cout << "c'est l'equipe " << team[0][0].numEquipe << " qui a gagne";
}

void tournoiAvecLooserBracket(string typeTournoi, vector <vector <joueur>> team, unsigned jeu, unsigned seed){
    unsigned combat = 1;
    vector <vector <joueur>> team2;
    for (size_t i = 0 ; i < team.size() - 1; ++i){
        //cout << "combat " << combat << ": l'équipe n°" << team[i][0].numEquipe << " VS l'équipe n°" << team[i + 1][0].numEquipe << endl;
        if (leJ1AGagne(jeu, combat + seed)) {
            //cout << "l'équipe n°" << team[i][0].numEquipe << " gagne" << endl;
            team2.push_back(team[i + 1]);
            team.erase(team.begin() + i + 1);
        }
        else{
            //cout << "l'équipe n°" << team[i + 1][0].numEquipe << " gagne" << endl;
            team2.push_back(team[i]);
            team.erase(team.begin() + i);
        }
        ++combat;
        //afficheNumTeam(team);
        //afficheNumTeam(team2);
    }
    tournoiSansLooserBracket("du winner bracket",team,jeu,seed);
    tournoiSansLooserBracket("du looser bracket",team2,jeu,seed);
    team.push_back(team2[0]);
    tournoiSansLooserBracket(typeTournoi,team,jeu,seed);
    //cout << "les vainqueurs " << typeTournoi << " sont l'équipe n°" << team[0][0].numEquipe << endl;
    cout << "c'est l'equipe " << team[0][0].numEquipe << " qui a gagne";
}

void tournoiChampionnat(string typeTournoi, vector <vector <joueur>> team, unsigned jeu, unsigned seed){
    vector <int> score;
    unsigned nbTeam = team.size();
    unsigned combat = 1;
    defScore(team,score);
    for (unsigned i = 0 ; i < nbTeam ; ++i){
        for (unsigned j = i + 1  ; j < nbTeam ; ++j){
            //cout << "combat " << combat << " : l'équipe n°" << team[i][0].numEquipe << " VS l'équipe n°" << team[j][0].numEquipe << endl;
            if (leJ1AGagne(jeu, combat + seed)){
                //cout << "l'équipe n°" << team[i][0].numEquipe << " gagne" << endl;
                ++score[i];
            }
            else{
                //cout << "l'équipe n°" << team[j][0].numEquipe << " gagne" << endl;
                ++score[j];
            }
            ++combat;
        }
    }
    triScoreTeam(team,score);
    //cout << "le vainqueur " << typeTournoi << " est " << team[0][0].numEquipe << endl;
    cout << "c'est l'equipe " << team[0][0].numEquipe << " qui a gagne";
}

void tournoiSuisse(string typeTournoi, vector <vector <joueur>> team, unsigned nbRound, unsigned jeu, unsigned seed){
    unsigned combat = 1;
    unsigned round = 1;
    unsigned swith = 0;
    unsigned nbTeam = team.size();
    vector <int> score;
    defScore(team,score);
    for (unsigned j = 0 ; j < nbRound ; ++j){
        //cout << "round " << round << endl;
        for (size_t i = 0 ; i < team.size() - 1 ; i+=2){
            //cout << "combat " << combat << ": " << team[i + swith][0].numEquipe << " VS " << team[i + 1 + swith][0].numEquipe << endl;
            if (leJ1AGagne(jeu, combat + seed)) {
                //cout << "l'équipe n°" << team[i + swith][0].numEquipe << " gagne" << endl;
                ++score[i + swith];
            }
            else{
                //cout << "l'équipe n°" << team[i + swith + 1][0].numEquipe << " gagne" << endl;
                ++score[i + 1 + swith];
            }
            ++combat;
        }
        if (nbTeam%2 == 1) swith = (swith + 1)%2;
        triScoreTeam(team, score);
        ++round;
    }
    //cout << "le vainqueur " << typeTournoi << " est " <<  << endl;
    cout << "c'est l'equipe " << team[0][0].numEquipe << " qui a gagne";
}

int main(){
    //cout << "Hello World!" << endl;
    vector <vector <joueur>> team(18);
    unsigned jeu = 1;
    unsigned combat = 1;
    unsigned seed = 0;
    donneEquipe(team);
    //afficheTeam(team);
    if (combat == 1) tournoiSansLooserBracket("du tournoi sans looser bracket",team,jeu,seed);
    if (combat == 2) tournoiAvecLooserBracket("du tournoi avec looser bracket",team,jeu,seed);
    if (combat == 3) tournoiChampionnat("du championnat",team,jeu,seed);
    if (combat == 4) tournoiSuisse("du tournoi suisse",team,8,jeu,seed);
    return 0;
}
