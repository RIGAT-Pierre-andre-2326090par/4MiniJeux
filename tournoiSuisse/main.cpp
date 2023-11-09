#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool leJ1AGagne(/*int team1, int team2*/){
    //return jeu(team1,team2);
    int a = 0 + rand()%2;
    return (a == 0);
}

int estUnePuissanceDe2(int nb){
    for (int i = 0 ; i <= 100 ; ++i){
        if (nb == pow(2,i)) return i;
    }
    return -1;
}

void afficheVector(vector <int> vec){
    cout << "{";
    for (size_t i = 0 ; i < vec.size() ; ++i){
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

vector <int> donneEquipes(unsigned nbTeam){
    vector <int> team;
    for (unsigned i = 1 ; i <= nbTeam ; ++i){
        team.push_back(i);
    }
    return team;
}

int tournoiSansLooserBracket(string typeTournoi, vector <int> team, unsigned nbTeam){
    if (estUnePuissanceDe2(nbTeam) == -1) {
        cout << "refaite les équipes" << endl;
        return 0;
    }
    else {
        int round = 1;
        int combat = 1;
        for (int j = 0 ; j < estUnePuissanceDe2(nbTeam) ; ++j){
            cout << "round " << round << endl;
            for (size_t i = 0 ; i < team.size() - 1; ++i){
                cout << "combat " << combat << endl;
                if (leJ1AGagne(/*team[0],team[1]*/)) {
                    cout << team[0 + i] << " gagne" << endl;
                    team.erase(team.begin() + i + 1);
                }
                else{
                    cout << team[1 + i] << " gagne" << endl;
                    team.erase(team.begin() + i);
                }
                ++combat;
                afficheVector(team);
            }
            ++round;
        }
        cout << "le vainqueur " << typeTournoi << " est " << team[0] << endl;
        return team[0];
    }
}

int tournoiAvecLooserBracket(string typeTournoi, vector <int> team, unsigned nbTeam){
    if (estUnePuissanceDe2(nbTeam) == -1) {
        cout << "refaite les équipes" << endl;
        return 0;
    }
    else {
        int combat = 1;
        vector <int> team2;
        for (size_t i = 0 ; i < team.size() - 1; ++i){
            cout << "combat " << combat << endl;
            if (leJ1AGagne(/*team[0],team[1]*/)) {
                cout << team[0 + i] << " gagne" << endl;
                team2.push_back(team[i + 1]);
                team.erase(team.begin() + i + 1);
            }
            else{
                cout << team[1 + i] << " gagne" << endl;
                team2.push_back(team[i]);
                team.erase(team.begin() + i);
            }
            ++combat;
            afficheVector(team);
            afficheVector(team2);
        }
        cout << "les vainqueurs " << typeTournoi << " sont "
             << tournoiSansLooserBracket("du winner bracket",team,nbTeam/2) << " et "
             << tournoiSansLooserBracket("du looser bracket",team2,nbTeam/2) << endl;
        return team[0];
    }
}

void triScoreTeam(vector <int> & team, vector <int> & score){
    size_t cpt = 0;
    while (cpt < team.size()){
        for (size_t i = 1 ; i < team.size() + 1 ; ++i){
            if (score[i - 1] < score[i]){
                swap(score[i],score[i - 1]);
                swap(team[i],team[i - 1]);
                cpt = 0;
            }
            else ++cpt;
        }
    }
    afficheVector(team);
    afficheVector(score);
}

int tournoiChampionnat(string typeTournoi, vector <int> team, unsigned nbTeam){
    vector <int> score;
    unsigned combat = 1;
    for (unsigned i = 0 ; i <= nbTeam - 1 ; ++i){
        score.push_back(0);
    }
    for (unsigned i = 0 ; i < nbTeam ; ++i){
        for (unsigned j = i + 1  ; j < nbTeam ; ++j){
            cout << "Combat " << combat << ": " << team[i] << " VS " << team[j] << endl;
            if (leJ1AGagne()){
                cout << team[i] << " a gagné" << endl;
                ++score[i];
            }
            else{
                cout << team[j] << " a gagné" << endl;
                ++score[j];
            }
        }
    }
    triScoreTeam(team,score);
    cout << "le vainqueur " << typeTournoi << " est " << team[0] << endl;
    return team[0];
}

int tournoiSuisse(string typeTournoi, vector <int> team, unsigned nbTeam, unsigned nbRound){
    if (nbTeam%2 != 0) {
        cout << "refaite les équipes" << endl;
        return 0;
    }
    else{
        unsigned combat = 1;
        vector <int> score;
        for (unsigned i = 0 ; i <= nbTeam ; ++i){
            score.push_back(0);
        }
        for (unsigned j = 0 ; j < nbRound ; ++j){
            for (size_t i = 0 ; i < team.size() - 1 ; i+=2){
                cout << "Combat " << combat << ": " << team[i] << " VS " << team[i + 1] << endl;
                if (leJ1AGagne(/*team[0],team[1]*/)) {
                    cout << team[i] << " gagne" << endl;
                    ++score[i];
                    }
                else{
                    cout << team[i + 1] << " gagne" << endl;
                    ++score[i + 1];
                }
                ++combat;
            }
        }
        triScoreTeam(team, score);
        cout << "le vainqueur " << typeTournoi << " est " << team[0] << endl;
        return team[0];
    }
}

int main(){
    //cout << "Hello World!" << endl;
    srand(time(NULL));
    unsigned nbTeam = 31;
    vector <int> team = donneEquipes(nbTeam);
    vector <int> a;
    a.push_back(tournoiSansLooserBracket("du tournoi sans looser bracket",team,nbTeam));
    a.push_back(tournoiAvecLooserBracket("du tournoi avec looser bracket",team,nbTeam));
    a.push_back(tournoiChampionnat("du championnat",team,nbTeam));
    a.push_back(tournoiSuisse("du tournoi suisse",team,nbTeam,8));
    afficheVector(a);
    return 0;
}
