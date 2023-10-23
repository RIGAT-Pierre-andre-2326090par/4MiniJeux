#include <iostream>
#include <vector>

using namespace std;

bool leJ1AGagne(int team1, int team2){
    //return jeu();
    int a = 0 + rand()%1;
    if (a == 0) return false;
    else return true;
}

bool estUnePuissanceDe2(int nb){
    for (int i = 0 ; i <= 100 ; ++i){
        if (nb == (2^i)) return true;
    }
    return false;
}

void afficheVector(vector <int> vec){
    cout << "{";
    for (size_t i = 0 ; i < vec.size() ; ++i){
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

void copyVector(vector <int> vec1, vector <int> vec2){
    for (size_t i = 0 ; i < vec1.size() ; ++i){
        vec2.push_back(vec1[i]);
    }
}

void tournoiSansBracketLooser()
{
    vector <int> team;
    vector <int> team2;
    unsigned nbTeam = 16;
    const size_t taille = 1;
    for (unsigned i = 1 ; i <= nbTeam ; ++i){
        team.push_back(i);
    }
    afficheVector(team);
    if (!estUnePuissanceDe2(nbTeam)) cout << "refaite les équipes" << endl;
    else {
        int round = 1;
        while (team.size() > taille){
            for (size_t i = 0 ; i < taille/2 ; ){
                if (leJ1AGagne(team[0+i],team[1+i])) {
                    team2.push_back(team[0+i]);
                    team.erase(team.begin() + 0 + i);
                    team.erase(team.begin() + 0 + i);
                }
                else{
                    team2.push_back(team[1+i]);
                    team.erase(team.begin() + 0 + i);
                    team.erase(team.begin() + 0 + i);
                }
            }
            copyVector(team, team2);
            team2 = {};
            cout << "round " << round << endl;
            afficheVector(team);
            ++round;
        }
    }
}

int main(){
     cout << "Hello World!" << endl;
     tournoiSansBracketLooser();
     return 0;
}
