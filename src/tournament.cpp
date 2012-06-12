#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "tournament.h"
using std::cout;
using std::vector;

Tournament::Tournament(int ng=8,int tpg=4)
{
    // teams = debug_give_teams();      
    teams = debug_give_teams();
    if(teams.size() != (ng*tpg))
    {
        std::cerr << " if(teams.size() == (ng*tpg)) FAILED\n "; 
        throw "Houston, we have a problem";
        // throw runtime_error; //("Houston, we have a problem");
    }
    num_groups = ng;
    // vector of indexes for teams
    vector<int> team_idx;
    team_idx.reserve(teams.size());
    int count = 0;
    std::for_each(teams.begin(), teams.end(), [&count, &team_idx] (Team t) { team_idx.push_back(count); count++;});

    cout << "Every day... shuffling\n";
    // apply to groups
    for(int i=0;i<num_groups;++i)
    {
        vector<int>::const_iterator first = team_idx.begin() + tpg*i;
        vector<int>::const_iterator last = team_idx.begin() + tpg*i + tpg;
        vector<int> newVec(first, last);
        groups.push_back(Group(newVec));
    }
}

//! An implementation of a printer of teams
void Tournament::print_team_list()
{
    cout << "number of teams: " << teams.size() << "\n";
	std::for_each(teams.begin(), teams.end(), [] (Team n) {cout << n.Name() << "\n"; });
}

void Tournament::print_group_list()
{
    cout << "number of groups: " << groups.size() << "\n";
	//std::vector<Team>::iterator
        
    int gc=1;
    for(auto i = groups.begin(); i != groups.end(); ++i, ++gc)
    {
        cout << "Group " << gc << "\n";  
        auto slot = i->Team_slot();
        for(auto i =slot.begin();i!=slot.end();++i)
        {
            std::cout << "team: " << teams.at(*i).Name() << "\n";
        }
    }
}
