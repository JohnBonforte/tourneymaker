#include <iostream>
#include <algorithm>
#include "tournament.h"
using std::cout;
using std::vector;

Tournament::Tournament(int ng=2)
{
    // teams = debug_give_teams();      
    teams = debug_give_teams();
    num_groups = ng;
    // vector of indexes for teams
    // shuffle
    vector<int> team_idx;
    for(unsigned int i=0;i<teams.size();++i)
        team_idx.push_back(i);
    // Uses random seed
    std::random_shuffle(team_idx.begin(), team_idx.end());
    cout << "Creating random shuffle\n";
    for(auto i = team_idx.begin(); i!= team_idx.end();++i)
    {
        cout << *i << "\n";
    }
    cout << "Every day... shuffling\n";
    // apply to groups
    int tpg = 4; //teams per group
    for(int i=0;i<num_groups;++i)
    {
        vector<int>::const_iterator first = team_idx.begin() + tpg*i;
        vector<int>::const_iterator last = team_idx.begin() + tpg*i + tpg;
        vector<int> newVec(first, last);
        groups.push_back(Group(newVec));
    }
}

void Tournament::print_team_list()
{
    cout << "number of teams: " << teams.size() << "\n";
	//std::vector<Team>::iterator
    for(auto i = teams.begin(); i != teams.end(); ++i)
    cout << i->Name() << "\n";  
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
