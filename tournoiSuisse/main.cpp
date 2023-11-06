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

void tournoiSansBracketLooser()
{
    vector <int> team;
    vector <int> team2;
    unsigned nbTeam = 16;
    //const size_t taille = 1;
    for (unsigned i = 1 ; i <= nbTeam ; ++i){
        team.push_back(i);
    }
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
    }
}


int main(){
     //cout << "Hello World!" << endl;
     tournoiSansBracketLooser();

     return 0;
}
