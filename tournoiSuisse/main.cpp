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
    return 0;
}

void afficheVector(vector <int> vec){
    cout << "{";
    for (size_t i = 0 ; i < vec.size() ; ++i){
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

vector <int> donneEquipes(unsigned nbTeam, vector <int> & team){
    for (unsigned i = 1 ; i <= nbTeam ; ++i){
        team.push_back(i);
    }
    return team;
}

void tournoiSansLooserBracket(string typeTournoi, vector <int> & team){
    unsigned swith = 0;
    unsigned round = 1;
    unsigned combat = 1;
    while (team.size() > 1){
        cout << "round " << round << ", " << swith << endl;
        for (size_t i = 0 ; i < team.size() - 1; ++i){
            cout << "combat " << combat << ": " << team[i + swith] << " VS " << team[i + 1 + swith] << endl;
            if (leJ1AGagne(/*team[0],team[1]*/)){
                cout << team[0 + i + swith] << " gagne" << endl;
                team.erase(team.begin() + i + 1 + swith);
            }
            else{
                cout << team[1 + i + swith] << " gagne" << endl;
                team.erase(team.begin() + i + swith);
            }
            ++combat;
            afficheVector(team);
        }
        ++round;
        if (team.size()%2 == 0) swith = 0 ;
        else swith = (swith + 1)%2;
    }
    cout << "le vainqueur " << typeTournoi << " est " << team[0] << endl;
}

void tournoiAvecLooserBracket(string typeTournoi, vector <int> team){
    unsigned combat = 1;
    vector <int> team2;
    for (size_t i = 0 ; i < team.size() - 1; ++i){
        cout << "combat " << combat << ": " << team[i] << " VS " << team[i + 1] << endl;
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
    tournoiSansLooserBracket("du winner bracket",team);
    tournoiSansLooserBracket("du looser bracket",team2);
    cout << "les vainqueurs " << typeTournoi << " sont " << team[0] << " et " << team2[0]  << endl;
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

void defScore(vector <int> & team, vector <int> & score){
    unsigned nbTeam = team.size();
    for (unsigned i = 0 ; i < nbTeam ; ++i){
        score.push_back(0);
    }
}

void tournoiChampionnat(string typeTournoi, vector <int> team){
    vector <int> score;
    unsigned nbTeam = team.size();
    unsigned combat = 1;
    defScore(team,score);
    for (unsigned i = 0 ; i < nbTeam ; ++i){
        for (unsigned j = i + 1  ; j < nbTeam ; ++j){
            cout << "combat " << combat << ": " << team[i] << " VS " << team[j] << endl;
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
}

void tournoiSuisse(string typeTournoi, vector <int> team, unsigned nbRound){
    unsigned combat = 1;
    unsigned round = 1;
    unsigned swith = 0;
    unsigned nbTeam = team.size();
    vector <int> score;
    defScore(team,score);
    for (unsigned j = 0 ; j < nbRound ; ++j){
        cout << "round " << round << endl;
        for (size_t i = 0 ; i < team.size() - 1 ; i+=2){
            cout << "combat " << combat << ": " << team[i + swith] << " VS " << team[i + 1 + swith] << endl;
            if (leJ1AGagne(/*team[0],team[1]*/)) {
                cout << team[i + swith] << " gagne" << endl;
                ++score[i + swith];
            }
            else{
                cout << team[i + 1 + swith] << " gagne" << endl;
                ++score[i + 1 + swith];
            }
            ++combat;
        }
        if (nbTeam%2 == 1) swith = (swith + 1)%2;
        triScoreTeam(team, score);
        ++round;
    }
    cout << "le vainqueur " << typeTournoi << " est " << team[0] << endl;
}

int main(){
    //cout << "Hello World!" << endl;
    srand(time(NULL));
    vector <int> team;
    donneEquipes(18,team);
    afficheVector(team);
    tournoiSansLooserBracket("du tournoi sans looser bracket",team);
    donneEquipes(18,team);
    tournoiAvecLooserBracket("du tournoi avec looser bracket",team);
    //donneEquipes(18,team);
    //tournoiChampionnat("du championnat",team);
    //donneEquipes(18,team);
    //tournoiSuisse("du tournoi suisse",team,8);
    return 0;
}
