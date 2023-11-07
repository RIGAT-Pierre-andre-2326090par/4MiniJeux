#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool leJ1AGagne(/*int team1, int team2*/){
    //return jeu(team1,team2);
    int a = 0 + rand()%2;
    if (a == 0) return false;
    else return true;
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

void tournoiSansLooserBracket(string typeTournoi, vector <int> team, unsigned nbTeam){
    if (estUnePuissanceDe2(nbTeam) == -1) cout << "refaite les équipes" << endl;
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
    }
}

void tournoiAvecLooserBracket(string typeTournoi, vector <int> team, unsigned nbTeam){
    if (estUnePuissanceDe2(nbTeam) == -1) cout << "refaite les équipes" << endl;
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
        tournoiSansLooserBracket("du winner bracket",team,nbTeam/2);
        tournoiSansLooserBracket("du looser bracket",team2,nbTeam/2);
        cout << "les vainqueurs " << typeTournoi << " sont " << team[0] << " et " << team2[0] << endl;
    }
}

void triScoreTeam(vector <int> team, vector <int> score){
    int a = 0;
    size_t cpt = 0;
    while (cpt < team.size()){
        for (size_t i = 0 ; i < team.size() - 1 ; ++i){
            if (score[i] > score[i + 1]){
                a = score[i];
                score[i] = score[i + 1];
                score[i + 1] = a;
                a = team[i];
                team[i] = team[i + 1];
                team[i + 1] = a;
                cpt = 0;
            }
            else ++cpt;
        }
    }
}

void tournoiSuisse(string typeTournoi, vector <int> team, unsigned nbTeam, unsigned nbRound){
    unsigned combat = 1;
    vector <int> score;
    for (unsigned i = 0 ; i <= nbTeam ; ++i){
        score.push_back(0);
    }
    for (int j = 0 ; j < nbRound ; ++j){
        for (size_t i = 0 ; i < team.size() - 1 ; i+=2){
            cout << "combat " << combat << endl;
            if (leJ1AGagne(/*team[0],team[1]*/)) {
                cout << team[0 + i] << " gagne" << endl;
                ++score[i];
                }
            else{
                cout << team[1 + i] << " gagne" << endl;
                ++score[i + 1];
            }
            ++combat;
            afficheVector(team);
            afficheVector(score);
        }
        triScoreTeam(team, score);
        afficheVector(team);
        afficheVector(score);
    }
}


int main(){
    //cout << "Hello World!" << endl;
    unsigned nbTeam = 16;
    vector <int> team = donneEquipes(nbTeam);
    //tournoiSansLooserBracket("du tournoi sans looser bracket",team,nbTeam);
    //tournoiAvecLooserBracket("du tournoi avec looser bracket",team,nbTeam);
    tournoiSuisse("du tournoi avec looser bracket",team,nbTeam,1);
    return 0;
}
