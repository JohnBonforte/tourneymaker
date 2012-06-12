#include "team.h"
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>

// using std::vector;
// using std::cout;
// using std::string;
using namespace std;

Team::Team(std::string nam):name(nam){

}


TeamContainer debug_give_teams()
{
    // TODO: Pick filename of team list.
    std::string filename = "../../../data/en-US/euro2012.txt";
    std::ifstream team_file(filename.c_str());
    // TODO: Account for the usage of spaces.  Right now. Solved by using full
    // words and underscores for spaces.
    vector<string> available_teams((istream_iterator<string>(team_file)), istream_iterator<string>());
    team_file.close();

    const int available_teams_size = available_teams.size();
    std::cout << "number of available teams: " << available_teams_size << "\n";
     std::for_each(available_teams.begin(), available_teams.end(), [] (const string s) { cout << s <<"\n"; }); 
     int wait = 0;
    cin >> wait;
    // TODO: Shuffle option?
    // std::random_shuffle(countries.begin(), countries.end());

    // TODO: Pick number of teams in tournament.
    // // You should pick the number of teams at this point
    int picked_number_of_teams = 16;
    std::vector<Team> temps;
    temps.reserve(picked_number_of_teams);
    // TODO: Pick the ORDER of the teams.  This should account for the group
    for(int i=0;i<picked_number_of_teams;i++)
        temps.push_back(available_teams[i]);
    return temps;
}
