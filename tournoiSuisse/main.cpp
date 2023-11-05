#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool leJ1AGagne(/*int & team1, int & team2*/){
    //return jeu(team1,team2);
    int a = 0 + rand()%2;
    if (a == 0) return false;
    else return true;
}

bool estUnePuissanceDe2(int & nb){
    for (int i = 0 ; i <= 100 ; ++i){
        if (nb == pow(2,i)) return true;
    }
    return false;
}

void afficheVector(vector <int> & vec){
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
    const size_t taille = 1;
    for (unsigned i = 1 ; i <= nbTeam ; ++i){
        team.push_back(i);
    }
    afficheVector(team);
    if (!estUnePuissanceDe2(nbTeam)) cout << "refaite les équipes" << endl;
    else {
        int round = 1;
        int combat = 1;
        while (team.size() > taille){
            cout << "round " << round << endl;
            for (size_t i = 0 ; i < pow(2,i) ; ++i){
                cout << "combat " << combat << endl;
                if (leJ1AGagne(/*team[0],team[1]*/)) {
                    cout << team[0] << " gagne" << endl;
                    team2.push_back(team[0]);
                    team.erase(team.begin());
                    team.erase(team.begin());
                }
                else{
                    cout << team[1] << " gagne" << endl;
                    team2.push_back(team[1]);
                    team.erase(team.begin());
                    team.erase(team.begin());
                }
                ++combat;
            }
            nbTeam /= 2;
            copy(team2.begin(), team2.end(), team.begin());
            team2 = {};
            afficheVector(team);
            afficheVector(team2);
            ++round;
        }
    }
}

int main(){
     cout << "Hello World!" << endl;
     tournoiSansBracketLooser();
     /*vector <int> vec1;
     vector <int> vec2;
     afficheVector(vec1);
     afficheVector(vec2);
     vec1 = {1, 2, 3, 4, 5};
     vec2 = copyVector(vec1);
     vec2[1] = 6;
     afficheVector(vec1);
     afficheVector(vec2);*/

     /*int sum = 0;
     for (unsigned i = 0 ; i < 100 ; ++i){
        int a = leJ1AGagne();
        cout << a << endl;
        sum += a;
     }
     cout << sum << endl;*/

     /*vector <int> team;
     vector <int> team2;
     team = {1, 2, 3, 4};
     team2.push_back(team[0]);
     team.erase(team.begin() + 0);
     team.erase(team.begin() + 0);
     afficheVector(team);
     afficheVector(team2);*/

     return 0;
}
