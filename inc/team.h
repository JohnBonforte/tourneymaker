#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <vector>

class Team
{
private:
    std::string name;
public: 
    Team(std::string nam);
    std::string Name(){return name;}
};

std::vector<Team> debug_give_teams();
#endif
